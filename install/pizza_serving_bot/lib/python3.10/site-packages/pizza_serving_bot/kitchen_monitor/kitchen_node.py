import rclpy
from rclpy.node import Node
from pizza_order_msgs.srv import OrderService
from pizza_order_msgs.msg import OrderInfo  # OrderInfo 메시지
import sqlite3
from PyQt5.QtWidgets import QApplication, QMainWindow, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget
import sys

class KitchenNode(Node):
    def __init__(self):
        super().__init__('kitchen_node')
        self.srv = self.create_service(OrderService, 'process_order', self.process_order_callback)
        self.order_info_publisher = self.create_publisher(OrderInfo, 'order_info', 10)  # OrderInfo 퍼블리셔 생성
        self.timer = self.create_timer(1.0, self.publish_order_info)  # 1초마다 주문 정보 퍼블리시

        # 초기값 설정
        self.order_id = 1  # 초기 주문 ID
        self.table_number = 5  # 초기 테이블 번호
        self.is_order_received = False  # 주문을 받은 여부를 확인

        # Database 초기화
        self.init_database()

    def init_database(self):
        self.conn = sqlite3.connect('pizza.db')  # pizza.db 사용
        self.cursor = self.conn.cursor()

    def process_order_callback(self, request, response):
        # 주문을 받으면 주문 정보를 업데이트
        self.get_logger().info(f"Processing order: {request.order_id} from table {request.table_number}")

        return response
  
    # def process_order_callback2(self, request, response):
    #     # 주문을 받으면 주문 정보를 업데이트
    #     self.get_logger().info(f"Processing order: {request.order_id} from table {request.table_number}")

    #     # 주문 정보를 받은 후 업데이트
    #     self.order_id = request.order_id
    #     self.table_number = request.table_number
    #     self.is_order_received = True  # 주문을 받았음을 표시

    #     # 데이터베이스에 주문 정보 추가
    #     self.cursor.execute('INSERT INTO Orders (order_id, table_number) VALUES (?, ?)',
    #                         (request.order_id, request.table_number))

    #     # 주문 세부 정보 추가 (가정: request.order_details는 OrderDetail 객체 목록)
    #     for order_detail in request.order_details:
    #         detail_id = order_detail.detail_id
    #         self.cursor.execute('INSERT INTO OrderDetails (detail_id, order_id,  item_name, quantity, total_price) VALUES (?, ?, ?, ?, ?)',
    #                             (detail_id, request.order_id, order_detail.item_name, order_detail.quantity, order_detail.total_price))

    #     self.conn.commit()

    #     # 주문 처리 결과 응답
    #     response.order_result = True
    #     return response 

    def publish_order_info(self):
        # 주문 정보를 1초마다 퍼블리시
        msg = OrderInfo()

        # 주문을 받은 경우에만 `OrderInfo` 퍼블리시
        if self.is_order_received:
            msg.order_id = self.order_id
            msg.table_number = self.table_number
        else:
            msg.order_id = self.order_id  # 초기값
            msg.table_number = self.table_number  # 초기값

        self.order_info_publisher.publish(msg)
        self.get_logger().info(f'Publishing order info: {msg}')

    def close_database(self):
        self.conn.close()

class KitchenApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Kitchen Orders')
        self.setGeometry(100, 100, 600, 400)

        self.table_widget = QTableWidget()
        layout = QVBoxLayout()
        layout.addWidget(self.table_widget)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        self.init_database()
        self.refresh_table()

    def init_database(self):
        self.conn = sqlite3.connect('pizza.db')  # pizza.db 사용
        self.cursor = self.conn.cursor()

    def refresh_table(self):
        self.cursor.execute('''SELECT o.order_id, o.table_number, d.item_name, d.quantity, d.total_price
                                FROM Orders o
                                JOIN OrderDetails d ON o.order_id = d.order_id
                                LIMIT 8''')  # 간단한 8개의 주문 정보만 조회
        rows = self.cursor.fetchall()

        # 2열 4행의 테이블 구성
        self.table_widget.setRowCount(4)
        self.table_widget.setColumnCount(2)
        self.table_widget.setHorizontalHeaderLabels(['Order Info', 'Item Details'])

        for row_idx in range(4):
            if row_idx * 2 < len(rows):  # 각 행에 데이터가 있으면 표시
                order_id, table_number, item_name, quantity, price = rows[row_idx * 2]
                self.table_widget.setItem(row_idx, 0, QTableWidgetItem(f'Order ID: {order_id}\nTable: {table_number}'))
                self.table_widget.setItem(row_idx, 1, QTableWidgetItem(f'Item: {item_name}\nQty: {quantity}\nPrice: {price}'))

        # 테이블 크기 조정
        self.table_widget.resizeColumnsToContents()

    def close_database(self):
        self.conn.close()

    def closeEvent(self, event):
        self.close_database()
        event.accept()

def main():
    rclpy.init()
    kitchen_node = KitchenNode()

    app = QApplication(sys.argv)
    kitchen_app = KitchenApp()
    kitchen_app.show()

    try:
        rclpy.spin(kitchen_node)  # 서비스가 활성화되어 요청을 대기
    except KeyboardInterrupt:
        kitchen_node.close_database()
    finally:
        rclpy.shutdown()

    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
