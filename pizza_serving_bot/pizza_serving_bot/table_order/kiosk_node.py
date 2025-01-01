import rclpy
from rclpy.node import Node
from pizza_order_msgs.srv import OrderService
from pizza_order_msgs.msg import OrderDetail  
from pizza_order_msgs.srv import CancelService
from pizza_order_msgs.msg import CallManager
import sys
import sqlite3
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QPushButton, QLabel, QListWidget, QGridLayout, QScrollArea,
    QFrame, QComboBox, QMessageBox, QSizePolicy, QListWidgetItem
)
from PyQt5.QtCore import Qt, QTime, QTimer,pyqtSignal,QThread, QObject
from PyQt5.QtGui import QFont, QPixmap
from functools import partial
from rclpy.qos import QoSProfile, ReliabilityPolicy

db_path = "/home/viator/ws/b3p1_ws/pizza.db"  # 여기에 실제 데이터베이스 경로를 입력하세요.

class SignalBridge(QObject):
    table_call_signal = pyqtSignal(str)  # 테이블 호출 신호

class KioskNode(QMainWindow):
    show_popup_signal = pyqtSignal(str)  # 팝업 메시지를 위한 Signal 정의

    def __init__(self, signal_bridge):
        super().__init__()

        # ROS2 노드 초기화
        if not rclpy.ok():
            rclpy.init()  # ROS2 초기화

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,  
            depth=10
        )

        self.node = rclpy.create_node('kiosk_node')

        self.signal_bridge = signal_bridge

        #주문요청 클라이언트 설정
        self.order_cli = self.node.create_client(
            OrderService, 
            'process_order', 
            qos_profile=qos_profile 
        )

        #주문취소 서버 설정
        self.cancel_ser = self.node.create_service(
            CancelService, 
            'cancel_order', 
            self.cancel_order_callback,
            qos_profile=qos_profile
        )
        
        #직원호출 토픽 퍼블리쉬 설정
        self.call_manager_pub = self.node.create_publisher(
            CallManager, 
            'call_manager', 
            qos_profile=qos_profile  # 키워드 인자로 전달
        )

        self.setWindowTitle("키오스크 주문 시스템")
        self.setGeometry(100, 100, 1024, 768)
                     
        self.init_data()
        self.initUI()

        # Signal-Slot 연결
        self.show_popup_signal.connect(self.show_popup_message)

        # ROS 2와 연결된 SignalBridge 신호 연결
        signal_bridge.table_call_signal.connect(self.show_popup_message)
    
    def show_popup_message(self, message):
        """
        호출된 테이블 번호를 화면에 표시하고 팝업으로 알림을 표시합니다.
        """
        self.call_label.setText(message)
        popup = QMessageBox()
        popup.setWindowTitle("Call Manager")
        popup.setText(message)
        popup.setIcon(QMessageBox.Information)
        popup.setStandardButtons(QMessageBox.Ok)
        popup.exec_()


    def cancel_order_callback(self, request, response):
        self.node.get_logger().info(f'주문 취소 요청: order_id={request.order_id}, table_number={request.table_number}')
        response.status = "Cancelled"

        # 팝업 메시지 전송
        popup_message = f"테이블 번호 {request.table_number}의 주문이 취소되었습니다."
        self.signal_bridge.table_call_signal.emit(popup_message)  # PyQt5 신호 전송

        # PyQt5 팝업창 띄우기
        #QMessageBox.information(self, "주문 취소", popup_message)

        # ROS 로그에 출력
        self.node.get_logger().info(popup_message)

        return response

    
    def init_data(self):
        # 카테고리별로 메뉴 항목을 가져옵니다.
        self.menu_data = {
            "피자": self.fetch_menu_items("피자"),
            "음료": self.fetch_menu_items("음료"),
            "기타": self.fetch_menu_items("기타"),
        }
        self.current_category = "피자"  # 초기 카테고리는 "피자"로 설정
        self.cart = {}
        self.order_history = []

    def fetch_menu_items(self, category):
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()

        # 카테고리별로 데이터를 가져오기 위한 쿼리 작성
        if category == "피자":
            query = '''
            SELECT item_name, price, image FROM Menu
            WHERE item_id BETWEEN 1 AND 6
            ORDER BY item_id;  -- item_id를 기준으로 정렬
            '''
        elif category == "음료":
            query = '''
            SELECT item_name, price, image FROM Menu
            WHERE item_id BETWEEN 7 AND 8
            ORDER BY item_id;  -- item_id를 기준으로 정렬
            '''
        elif category == "기타":
            query = '''
            SELECT item_name, price, image FROM Menu
            WHERE item_id BETWEEN 9 AND 12
            ORDER BY item_id;  -- item_id를 기준으로 정렬
            '''
        else:
            query = "SELECT item_name, price, image FROM Menu ORDER BY item_id;"  # item_id 기준 정렬

        cursor.execute(query)
        items = cursor.fetchall()

        # 데이터를 리스트로 변환
        menu_items = [{"name": item[0], "price": item[1], "image": item[2]} for item in items]
        conn.close()

        return menu_items


    def initUI(self):
        main_widget = QWidget()
        self.setCentralWidget(main_widget)

        main_layout = QVBoxLayout()
        top_layout = QHBoxLayout()

        # 테이블 번호 선택
        table_label = QLabel("테이블 번호:")
        table_label.setStyleSheet("font-size: 16px; font-weight: bold; color: #424242;")
        top_layout.addWidget(table_label)

        self.table_dropdown = QComboBox()
        self.table_dropdown.addItems([str(i) for i in range(1, 7)])
        self.table_dropdown.setStyleSheet("""
            font-size: 16px; 
            background-color: #FFFFFF; 
            border: 1px solid #DDDDDD; 
            border-radius: 10px;
            padding: 5px;
        """)
        top_layout.addWidget(self.table_dropdown)

        top_layout.addStretch()

        # 현재 시간 표시
        self.time_label = QLabel()
        self.time_label.setStyleSheet("font-size: 16px; color: #424242;")
        self.update_time()
        top_layout.addWidget(self.time_label)

        timer = QTimer(self)
        timer.timeout.connect(self.update_time)
        timer.start(1000)

        main_layout.addLayout(top_layout)

        # 중간 레이아웃
        middle_layout = QHBoxLayout()

        # 카테고리 버튼
        category_layout = QVBoxLayout()
        category_label = QLabel("카테고리")
        category_label.setStyleSheet("font-size: 20px; font-weight: bold; color: #424242;")
        category_layout.addWidget(category_label)

        for category in self.menu_data.keys():
            category_button = QPushButton(category)
            category_button.setStyleSheet("""
                font-size: 16px; 
                background-color: #FFB74D; 
                color: white; 
                border-radius: 10px;
                margin-bottom: 10px;
            """)
            category_button.clicked.connect(lambda _, c=category: self.change_category(c))
            category_layout.addWidget(category_button)

        category_layout.addStretch()
        middle_layout.addLayout(category_layout, 1)

        # 메뉴 레이아웃
        menu_layout = QVBoxLayout()
        menu_header = QLabel("메뉴 목록")
        menu_header.setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 10px; color: #424242;")
        menu_layout.addWidget(menu_header)

        scroll_area = QScrollArea()
        scroll_area.setWidgetResizable(True)

        self.menu_grid = QWidget()
        self.grid_layout = QGridLayout(self.menu_grid)
        self.grid_layout.setSpacing(10)
        scroll_area.setWidget(self.menu_grid)
        menu_layout.addWidget(scroll_area)
        middle_layout.addLayout(menu_layout, 3)

        # 장바구니 레이아웃
        cart_layout = QVBoxLayout()
        cart_label = QLabel("장바구니")
        cart_label.setStyleSheet("font-size: 20px; font-weight: bold; color: #424242;")
        cart_layout.addWidget(cart_label)

        self.cart_list_widget = QListWidget()
        self.cart_list_widget.setStyleSheet("""
            background-color: #FFF8E1; 
            border: 1px solid #DDDDDD; 
            border-radius: 10px;
            padding: 5px;
        """)
        cart_layout.addWidget(self.cart_list_widget)

        self.total_label = QLabel("현재 가격: 0원")
        self.total_label.setStyleSheet("font-size: 18px; font-weight: bold; color: #388E3C;")
        cart_layout.addWidget(self.total_label)

        order_button = QPushButton("주문하기")
        order_button.setStyleSheet("""
            font-size: 18px; 
            background-color: #4CAF50; 
            color: white; 
            border-radius: 10px; 
            padding: 10px;
        """)
        order_button.clicked.connect(self.place_order)
        cart_layout.addWidget(order_button)

        call_staff_button = QPushButton("직원 호출")
        call_staff_button.setStyleSheet("""
            font-size: 18px; 
            background-color: #FF9800; 
            color: white; 
            border-radius: 10px; 
            padding: 10px;
        """)
        call_staff_button.clicked.connect(self.call_staff)
        cart_layout.addWidget(call_staff_button)

        total_button = QPushButton("Total")
        total_button.setStyleSheet("""
            font-size: 18px; 
            background-color: #64B5F6; 
            color: white; 
            border-radius: 10px; 
            padding: 10px;
        """)
        total_button.clicked.connect(self.show_total_orders)
        cart_layout.addWidget(total_button)

        middle_layout.addLayout(cart_layout, 2)
        main_layout.addLayout(middle_layout)
        main_widget.setLayout(main_layout)

        # 초기 메뉴 로드
        self.load_menu_items()

    def update_time(self):
        current_time = QTime.currentTime().toString("hh:mm:ss")
        self.time_label.setText(f"현재 시간: {current_time}")

    def change_category(self, category):
        self.current_category = category
        self.load_menu_items()

    def load_menu_items(self):
        for i in reversed(range(self.grid_layout.count())):
            widget = self.grid_layout.itemAt(i).widget()
            if widget:
                widget.deleteLater()

        items = self.menu_data[self.current_category]
        for index, item in enumerate(items):
            frame = QFrame()
            frame.setFrameShape(QFrame.StyledPanel)
            frame.setStyleSheet("background-color: #FFF9C4; border: 1px solid #FFEB3B; border-radius: 15px;")
            frame.setFixedSize(200, 280)  # 프레임 크기를 더 크게 조정

            frame_layout = QVBoxLayout()

         # 이미지 추가
            image_label = QLabel()
            if item['image']:  # 이미지 파일 경로가 있다면
                pixmap = QPixmap(item['image'])  # 이미지 경로를 통해 QPixmap 객체 생성
                pixmap = pixmap.scaled(200, 180, Qt.KeepAspectRatio)  # 이미지 크기를 더 크게 조정
                image_label.setPixmap(pixmap)
            else:
                image_label.setText("이미지 없음")  # 이미지가 없을 경우 텍스트 표시

            frame_layout.addWidget(image_label)

            # 음식 이름과 가격
            label = QLabel(f"{item['name']}\n{item['price']}원")
            label.setStyleSheet("font-size: 14px; font-weight: bold; color: #424242;")  # 텍스트 크기 작게 조정
            label.setAlignment(Qt.AlignCenter)

            # 버튼 레이아웃
            button_layout = QHBoxLayout()
            minus_button = QPushButton("-")
            minus_button.setStyleSheet("""
                font-size: 18px; 
                background-color: #F44336; 
                color: white; 
                border-radius: 10px;
            """)
            minus_button.clicked.connect(partial(self.update_cart, item, -1))
            button_layout.addWidget(minus_button)

            plus_button = QPushButton("+")
            plus_button.setStyleSheet("""
                font-size: 18px; 
                background-color: #4CAF50; 
                color: white; 
                border-radius: 10px;
            """)
            plus_button.clicked.connect(partial(self.update_cart, item, 1))
            button_layout.addWidget(plus_button)

            frame_layout.addWidget(label)
            frame_layout.addLayout(button_layout)

            frame.setLayout(frame_layout)
            self.grid_layout.addWidget(frame, index // 3, index % 3)


    def update_cart(self, item, quantity_change):
        item_name = item['name']
        if item_name not in self.cart:
            self.cart[item_name] = 0
        self.cart[item_name] += quantity_change

        if self.cart[item_name] <= 0:
            del self.cart[item_name]

        self.update_cart_display()

    def update_cart_display(self):
        self.cart_list_widget.clear()
        total_price = 0
        for item_name, quantity in self.cart.items():
            self.cart_list_widget.addItem(f"{item_name} x{quantity} = {self.get_item_price(item_name) * quantity}원")
            total_price += self.get_item_price(item_name) * quantity

        self.total_label.setText(f"현재 가격: {total_price}원")

    def get_item_price(self, item_name):
        for item in self.menu_data["피자"]:
            if item['name'] == item_name:
                return item['price']
        for item in self.menu_data["음료"]:
            if item['name'] == item_name:
                return item['price']
        for item in self.menu_data["기타"]:
            if item['name'] == item_name:
                return item['price']
        return 0

    def place_order(self):
        # 테이블 번호를 입력받고 정수로 변환
        table_number = int(self.table_dropdown.currentText())
        
        # 유효한 테이블 번호 확인
        if table_number <= 0:
            raise ValueError("Table number must be a positive integer.")
        
        if not self.cart:
            QMessageBox.warning(self, "경고", "장바구니에 항목이 없습니다.")
            return

        # 1. Orders 테이블에 주문 추가
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()

        # 주문 상태를 'Pending'으로 설정
        cursor.execute('''
            INSERT INTO Orders (table_number, status)
            VALUES (?, ?)
        ''', (table_number, 'Pending'))

        # 방금 추가된 주문의 ID를 가져옴
        order_id = cursor.lastrowid
        
        # 2. OrderDetails 테이블에 주문 항목 추가
        order_details_for_show = []
        order_details = []
        total_price = 0
        detail_id = 0

        for item_name, quantity in self.cart.items():
            # Find the last detail_id in the OrderDetails table and increment it
            cursor.execute('SELECT MAX(detail_id) FROM OrderDetails')
            last_detail_id = cursor.fetchone()[0]
            
            # If there's no previous detail_id, start from 1
            if last_detail_id is None:
                detail_id = 1
            else:
                detail_id = last_detail_id + 1
            
            item_price = self.get_item_price(item_name)
            item_total_price = item_price * quantity
            total_price += item_total_price
            order_details_for_show.append(f"{item_name} x{quantity} ({item_total_price}원)")

            # 인터페이스 서비스 전달용
            order_detail = OrderDetail()
            order_detail.detail_id = detail_id
            order_detail.item_name = item_name
            order_detail.quantity = quantity
            order_detail.price = item_price
            order_details.append(order_detail)

            # Check if the detail_id already exists (though this should not happen now)
            cursor.execute('SELECT COUNT(*) FROM OrderDetails WHERE detail_id = ?', (detail_id,))
            existing = cursor.fetchone()[0]

            if existing == 0:
                # Proceed with insertion if detail_id does not exist
                cursor.execute('INSERT INTO OrderDetails (detail_id, order_id, item_name, quantity, total_price) VALUES (?, ?, ?, ?, ?)',
                                    (detail_id, order_id, item_name, quantity, item_total_price))
            else:
                # Handle the case where detail_id exists
                print(f"Detail ID {detail_id} already exists.")

        # 변경 사항을 커밋
        conn.commit()
        conn.close()

        # 주문 처리 후 장바구니 초기화 및 화면 업데이트
        self.cart.clear()
        self.update_cart_display()

        # 전체 주문 내역에 추가
        self.order_history.append({
            'table_number': str(table_number),
            'order_details': ", ".join(order_details_for_show),
            'total': total_price
        })

        request = OrderService.Request()
        request.order_id = order_id
        request.table_number = table_number
        request.detail_id = detail_id
        request.order_details = order_details

        # ROS2 서비스 호출
        future = self.order_cli.call_async(request)
        future.add_done_callback(self.order_response_callback)

        # 사용자에게 주문 완료 메시지 표시
        order_details_text = "\n".join(order_details_for_show)
        QMessageBox.information(self, "주문 완료", f"주문 번호 : {order_id}번\n주문이 완료되었습니다.\n주문 내용: \n{order_details_text}\n총 금액: {total_price}원")

    def order_response_callback(self, future):
        try:
            response = future.result()
            if response.order_result:
                QMessageBox.information(self, "주문 성공", "주문이 성공적으로 접수되었습니다.")
                self.order_history.append(self.cart)
                self.cart.clear()
                self.update_cart_display()
            else:
                QMessageBox.critical(self, "주문 실패", "주문 접수가 실패했습니다.")
        except Exception as e:
            QMessageBox.critical(self, "주문 실패", f"오류 발생: {e}")

    def show_total_orders(self):
    # 선택된 테이블 번호 가져오기
        selected_table = self.table_dropdown.currentText()

        if not self.order_history:
            QMessageBox.information(self, "주문 내역", "현재까지의 주문 내역이 없습니다.")
            return

        # 해당 테이블의 모든 주문 가져오기
        orders_for_table = [order for order in self.order_history if order['table_number'] == selected_table]

        if not orders_for_table:
            QMessageBox.information(self, f"테이블 {selected_table}의 주문 내역", "주문 내역이 없습니다.")
            return

        # 동일한 메뉴 항목을 하나로 묶기
        combined_orders = {}
        for order in orders_for_table:
            items = order['order_details'].split(", ")  # 주문 항목은 쉼표로 구분되어 있음
            for item in items:
                # "항목 x수량 (가격)" 형식에서 항목명과 수량 추출
                item_name, quantity_price = item.split(" x")
                quantity, _ = quantity_price.split(" ")  # "수량 (가격)" 형식에서 수량만 추출
                quantity = int(quantity.strip())

                if item_name in combined_orders:
                    combined_orders[item_name] += quantity
                else:
                    combined_orders[item_name] = quantity

        # 계산서 텍스트 생성
        bill_details = ""
        total_price = 0
        for item_name, quantity in combined_orders.items():
            item_price = self.get_item_price(item_name)
            item_total_price = item_price * quantity
            total_price += item_total_price
            bill_details += f"{item_name} x{quantity} = {item_total_price}원\n"

        # 최종 계산서 텍스트
        bill_summary = f"테이블 {selected_table}의 계산서:\n\n{bill_details}\n총 금액: {total_price}원"

        # 메시지 박스에 계산서 표시
        QMessageBox.information(self, f"테이블 {selected_table} 계산서", bill_summary)

    #CancelService  적용하도록 바꿀 것
    def call_staff(self):
        # 선택된 테이블 번호 가져오기
        selected_table = self.table_dropdown.currentText()

        # CallManager 메시지 생성 및 필드 설정
        msg = CallManager()
        msg.table_number = int(selected_table)  # table_number 필드에 값 설정

        # 메시지를 퍼블리시
        self.call_manager_pub.publish(msg)

        # 사용자에게 알림 표시
        QMessageBox.information(self, "직원 호출", f"테이블 {selected_table}에서 직원을 호출하였습니다.")



def main():
    app = QApplication(sys.argv)
     # SignalBridge와 노드 생성
    signal_bridge = SignalBridge()

    window = KioskNode(signal_bridge)
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()