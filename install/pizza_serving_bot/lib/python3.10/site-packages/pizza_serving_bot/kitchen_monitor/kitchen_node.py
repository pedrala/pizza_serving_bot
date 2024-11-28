import datetime
import sqlite3
import sys
import matplotlib
from matplotlib import font_manager
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from pizza_order_msgs.srv import OrderService
from pizza_order_msgs.msg import OrderDetail  # OrderDetail 메시지 임포트
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QGridLayout, QLabel, 
    QPushButton, QScrollArea, QGroupBox, QHBoxLayout, QMainWindow
)
from PyQt5.QtCore import Qt, QTimer
from datetime import datetime
from rclpy.executors import MultiThreadedExecutor
import threading

db_path = "/home/viator/ws/b3_ws/pizza.db"

class KitchenServiceNode(Node):
    def __init__(self):
        super().__init__('kitchen_service_node')
        
        # QoS 프로파일 생성 방식 변경
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,  
            depth=10
        )

        # 서비스와 클라이언트 설정
        self.srv = self.create_service(
            OrderService, 
            'process_order', 
            self.process_order_callback,
            qos_profile=qos_profile  # 키워드 인자로 전달
        )
    
    def process_order_callback(self, request, response):
        self.get_logger().info('주문 처리 중: %s' % request.order_id)
        # 주문 처리 로직 추가
        response.status = "Processed"
        return response

class KitchenDisplay(QWidget):
    def __init__(self):
        super().__init__()
        self.lock = threading.Lock()
        self.setWindowTitle("Kitchen Display System")
        self.setGeometry(100, 100, 1660, 1080)

        # 메인 레이아웃
        self.main_layout = QVBoxLayout()

        # 상단 레이아웃
        self.top_layout = QHBoxLayout()

        # 왼쪽 - 로봇 좌표 표시
        self.robot_label = QLabel("ROBOT COORDINATE : X(  ), Y(  ), Z(  )")
        self.robot_label.setStyleSheet("font-size: 16px; font-weight: bold;")
        self.top_layout.addWidget(self.robot_label, alignment=Qt.AlignLeft)

        # 중앙 - 키친 디스플레이 제목
        self.title_label = QLabel("KITCHEN DISPLAY")
        self.title_label.setAlignment(Qt.AlignCenter)
        self.title_label.setStyleSheet("font-size: 30px; font-weight: bold; color: green;")
        self.top_layout.addWidget(self.title_label)

        # 오른쪽 - 매출 버튼
        self.sales_layout = QHBoxLayout()
        self.day_sales_button = QPushButton("DAY")
        self.month_sales_button = QPushButton("MONTH")
        self.year_sales_button = QPushButton("YEAR")

        # 버튼 스타일 및 클릭 이벤트
        self.day_sales_button.clicked.connect(lambda: self.open_sales_window("DAY"))
        self.month_sales_button.clicked.connect(lambda: self.open_sales_window("MONTH"))
        self.year_sales_button.clicked.connect(lambda: self.open_sales_window("YEAR"))

        for button in [self.day_sales_button, self.month_sales_button, self.year_sales_button]:
            button.setStyleSheet("font-size: 16px; padding: 10px;")
            self.sales_layout.addWidget(button)

        self.top_layout.addLayout(self.sales_layout)

        # 상단 레이아웃 추가
        self.main_layout.addLayout(self.top_layout)

        # 주문 카드 레이아웃
        self.scroll_area = QScrollArea()
        self.scroll_area.setWidgetResizable(True)

        # 주문 카드들을 담을 위젯
        self.order_widget = QWidget()
        self.order_widget.setStyleSheet("background-color: #F0F0F0;")
        self.grid_layout = QGridLayout()
        self.grid_layout.setSpacing(20)
        self.order_widget.setLayout(self.grid_layout)

        self.scroll_area.setWidget(self.order_widget)
        self.main_layout.addWidget(self.scroll_area)

        # 주문 카드 목록
        self.order_cards = []
        self.rows = 2  # 고정된 행 수
        self.cols = 4  # 고정된 열 수

        # 테스트 데이터 추가
        self.load_orders_from_database()

        self.setLayout(self.main_layout)
        
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.refresh_orders)  # refresh_orders 메서드 호출
        self.timer.start(1000)  # 3000ms = 3초
    
    def load_orders_from_database(self):
     
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        
        # orders 및 orderdetails 데이터를 조인하여 가져오기
        query = """
        SELECT o.order_id, o.timestamp, o.table_number, od.item_name, od.quantity
        FROM orders o
        JOIN orderdetails od ON o.order_id = od.order_id
        WHERE o.status = 'Pending'
        """
        cursor.execute(query)
        rows = cursor.fetchall()
        
        # 주문 데이터를 주문 ID별로 그룹화
        orders = {}
        for order_id, timestamp, table_number, item_name, quantity in rows:
            if order_id not in orders:
                orders[order_id] = {
                    "timestamp": timestamp[11:16],  # HH:MM 형식으로 변환
                    "table_number": table_number,
                    "menu_items": []
                }
            orders[order_id]["menu_items"].append(f"{item_name} x {quantity}")

        # 주문 카드 생성 및 추가
        for order_id, data in orders.items():
            self.add_order_card(order_id, data["timestamp"], data["table_number"], data["menu_items"])

        conn.close()

    def create_order_card(self, order_id, order_time, table_number, menu_items):
        card = QGroupBox()
        card_layout = QVBoxLayout()
        card_layout.setAlignment(Qt.AlignTop)

        # 주문번호
        order_id_label = QLabel(f"{order_id}")
        order_id_label.setFixedHeight(50)
        order_id_label.setAlignment(Qt.AlignCenter)
        order_id_label.setStyleSheet("font-size: 28px; font-weight: bold; color: green;")
        card_layout.addWidget(order_id_label)

        # 주문시간 + 테이블번호 (한 줄, 중앙 정렬)
        order_info_layout = QHBoxLayout()
        order_time_label = QLabel(f"TIME : {order_time}")
        order_time_label.setFixedHeight(50)
        order_time_label.setAlignment(Qt.AlignCenter)
        table_number_label = QLabel(f"TABLE : {table_number}")
        table_number_label.setFixedHeight(50)
        table_number_label.setAlignment(Qt.AlignCenter)
        order_time_label.setStyleSheet("font-size: 20px;")
        table_number_label.setStyleSheet("font-size: 20px;")
        order_info_layout.addWidget(order_time_label)
        order_info_layout.addWidget(table_number_label)
        card_layout.addLayout(order_info_layout)

        # 메뉴 목록 (크기 고정)
        for item in menu_items:
            menu_label = QLabel(f"  • {item}")
            menu_label.setStyleSheet("font-size: 20px;")
            menu_label.setFixedHeight(50)  # 메뉴 크기 고정
            card_layout.addWidget(menu_label)
            
        # 빈 공간 추가 (버튼을 하단에 고정하기 위해)
        # card_layout.addStretch()
                    
        # 취소 버튼
        cancel_button = QPushButton("Cancelled")
        cancel_button.setStyleSheet("""
            background-color: red;
            color: white;
            font-size: 20px;
            padding: 5px 10px;
            border-radius: 5px;
        """)
        cancel_button.clicked.connect(lambda: self.update_order_status(order_id, "Cancelled"))
        card_layout.addWidget(cancel_button)

        card.setLayout(card_layout)

        # 완료 버튼
        complete_button = QPushButton("Completed")
        complete_button.setStyleSheet("""
            background-color: blue;
            color: white;
            font-size: 20px;
            padding: 5px 10px;
            border-radius: 5px;
        """)
        complete_button.clicked.connect(lambda: self.update_order_status(order_id, "Completed"))
        card_layout.addWidget(complete_button)

        card.setLayout(card_layout)

        # 카드 스타일
        card.setStyleSheet("""
            QGroupBox {
                background-color: white;
                border: 2px solid green;
                border-radius: 10px;
                padding: 10px;
            }
        """)

        return card

    def add_order_card(self, order_id, order_time, table_number, menu_items):
        card = self.create_order_card(order_id, order_time, table_number, menu_items)
        self.order_cards.append(card)
        self.update_order_grid()

    def remove_order_card(self, card):
        self.order_cards.remove(card)
        self.update_order_grid()

    def update_order_grid(self):
        # 기존 위젯 모두 제거
        for i in reversed(range(self.grid_layout.count())):
            widget_item = self.grid_layout.itemAt(i)
            if widget_item:
                widget = widget_item.widget()
                if widget:
                    self.grid_layout.removeWidget(widget)
                    widget.setParent(None)

        # 새로 정렬하여 카드 추가
        for index, card in enumerate(self.order_cards):
            row = index // self.cols
            col = index % self.cols
            self.grid_layout.addWidget(card, row, col)

        # 빈 공간 채우기
        total_slots = self.rows * self.cols
        empty_slots = total_slots - len(self.order_cards)
        for i in range(empty_slots):
            row = (len(self.order_cards) + i) // self.cols
            col = (len(self.order_cards) + i) % self.cols
            placeholder = QLabel("")
            placeholder.setStyleSheet("background-color: #E0E0E0; border: 1px dashed gray;")
            self.grid_layout.addWidget(placeholder, row, col)
         
    def update_order_status(self, order_id, status):
    
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()

        # 주문 상태 업데이트
        query = "UPDATE orders SET status = ? WHERE order_id = ?"
        cursor.execute(query, (status, order_id))
        conn.commit()
        conn.close()

        # 주문 카드 갱신 전 기존 카드 제거
        self.order_cards.clear()
        for i in reversed(range(self.grid_layout.count())):
            widget_item = self.grid_layout.itemAt(i)
            if widget_item:
                widget = widget_item.widget()
                if widget:
                    self.grid_layout.removeWidget(widget)
                    widget.setParent(None)

        # 주문 데이터 다시 로드
        self.load_orders_from_database()

    def open_sales_window(self, sales_type):
        self.sales_window = SalesWindow(sales_type)
        self.sales_window.show()
        
    def refresh_orders(self):
    # 기존 주문 카드 제거
        self.order_cards.clear()
        for i in reversed(range(self.grid_layout.count())):
            widget_item = self.grid_layout.itemAt(i)
            if widget_item:
                widget = widget_item.widget()
                if widget:
                    self.grid_layout.removeWidget(widget)
                    widget.setParent(None)

        # 데이터베이스에서 새 데이터 로드
        self.load_orders_from_database()


# 한글 폰트 설정
font_path = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"  # Ubuntu Noto Sans CJK 폰트 경로
font_prop = font_manager.FontProperties(fname=font_path)
matplotlib.rc('font', family=font_prop.get_name())


class SalesWindow(QWidget):
    def __init__(self, sales_type):
        super().__init__()
        self.setWindowTitle(f"Sales Information")
        self.setGeometry(200, 200, 1660, 1080)

        # 메인 레이아웃
        self.main_layout = QVBoxLayout()

        # 상단 레이아웃 (타이틀)
        self.sales_type_label = QLabel(f"{sales_type}")
        self.sales_type_label.setFixedHeight(50)
        self.sales_type_label.setAlignment(Qt.AlignCenter)
        self.sales_type_label.setStyleSheet("""
            font-size: 30px; 
            font-weight: bold; 
            color: green;
        """)
        self.main_layout.addWidget(self.sales_type_label)

        # 그래프 추가
        self.figure = Figure(figsize=(14, 8))
        self.canvas = FigureCanvas(self.figure)

        # 그래프 생성
        self.create_graph(sales_type)

        # 레이아웃 구성
        self.main_layout.addWidget(self.canvas)
        self.setLayout(self.main_layout)

    def create_graph(self, sales_type):
       
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()

        now = datetime.now()
        current_year = now.year
        current_month = now.month
        current_day = now.strftime('%Y-%m-%d')
        
        sales_money = 0
        sales_count = 0

        # 매출 데이터
        if sales_type == "DAY":
            sales_money = "일별"
            sales_count = "금일"
            labels = [str(day) for day in range(1, 32)]
            query = f"""
                SELECT strftime('%d', o.timestamp) AS day, SUM(od.total_price)
                FROM orders o
                JOIN orderdetails od ON o.order_id = od.order_id
                WHERE o.status = 'Completed' AND strftime('%Y-%m', o.timestamp) = '{current_year:04d}-{current_month:02d}'
                GROUP BY day
            """
            cursor.execute(query)
            data = cursor.fetchall()
            sales_data = {int(row[0]): row[1] for row in data}
            sales = [sales_data.get(day, 0) for day in range(1, 32)]

            # 메뉴별 판매량 (모든 메뉴 이름 포함, 당일 팔린 메뉴만 판매량 반영)
            query_menu = f"""
                SELECT m.item_name, COALESCE(SUM(od.quantity), 0)
                FROM Menu m
                LEFT JOIN OrderDetails od ON m.item_name = od.item_name
                LEFT JOIN orders o ON od.order_id = o.order_id AND o.status = 'Completed'
                WHERE strftime('%Y-%m-%d', o.timestamp) = '{current_day}'
                GROUP BY m.item_id, m.item_name
            """

        elif sales_type == "MONTH":
            sales_money = "월별"
            sales_count = "금월"
            labels = [str(month) for month in range(1, 13)]
            query = f"""
                SELECT strftime('%m', o.timestamp) AS month, SUM(od.total_price)
                FROM orders o
                JOIN orderdetails od ON o.order_id = od.order_id
                WHERE o.status = 'Completed' AND strftime('%Y', o.timestamp) = '{current_year:04d}'
                GROUP BY month
            """
            cursor.execute(query)
            data = cursor.fetchall()
            sales_data = {int(row[0]): row[1] for row in data}
            sales = [sales_data.get(month, 0) for month in range(1, 13)]

            # 메뉴별 판매량 (모든 메뉴 이름 포함, 당월 팔린 메뉴만 판매량 반영)
            query_menu = f"""
                SELECT m.item_name, COALESCE(SUM(od.quantity), 0)
                FROM Menu m
                LEFT JOIN OrderDetails od ON m.item_name = od.item_name
                LEFT JOIN orders o ON od.order_id = o.order_id AND o.status = 'Completed'
                WHERE strftime('%Y-%m', o.timestamp) = '{current_year:04d}-{current_month:02d}'
                GROUP BY m.item_id, m.item_name
            """

        elif sales_type == "YEAR":
            sales_money = "연별"
            sales_count = "금년"
            labels = [str(year) for year in range(current_year - 10, current_year + 1)]
            query = f"""
                SELECT strftime('%Y', o.timestamp) AS year, SUM(od.total_price)
                FROM orders o
                JOIN orderdetails od ON o.order_id = od.order_id
                WHERE o.status = 'Completed' AND strftime('%Y', o.timestamp) BETWEEN '{current_year - 10:04d}' AND '{current_year:04d}'
                GROUP BY year
            """
            cursor.execute(query)
            data = cursor.fetchall()
            sales_data = {int(row[0]): row[1] for row in data}
            sales = [sales_data.get(year, 0) for year in range(current_year - 10, current_year + 1)]

            # 메뉴별 판매량 (모든 메뉴 이름 포함, 당해 팔린 메뉴만 판매량 반영)
            query_menu = f"""
                SELECT m.item_name, COALESCE(SUM(od.quantity), 0)
                FROM Menu m
                LEFT JOIN OrderDetails od ON m.item_name = od.item_name
                LEFT JOIN orders o ON od.order_id = o.order_id AND o.status = 'Completed'
                WHERE strftime('%Y', o.timestamp) = '{current_year:04d}'
                GROUP BY m.item_id, m.item_name
            """

        else:
            raise ValueError("Invalid sales type.")

        # 모든 메뉴를 가져와 초기화
        cursor.execute("SELECT item_name FROM Menu ORDER BY item_id ASC")
        all_menu_items = [row[0] for row in cursor.fetchall()]

        # 판매량 쿼리 실행
        cursor.execute(query_menu)
        sold_menu_data = dict(cursor.fetchall())  # 메뉴 이름 -> 판매량 매핑
        menu_sales = [sold_menu_data.get(menu, 0) for menu in all_menu_items]

        conn.close()

        # 그래프 그리기
        self.figure.clear()

        # 매출액 그래프
        ax1 = self.figure.add_subplot(211)
        ax1.bar(labels, sales, color='green')
        ax1.set_title(f"{sales_money} 매출액", fontsize=18, fontweight='bold')
        ax1.set_ylabel("금액(원)", fontsize=18, fontweight='bold', rotation=0, labelpad=45)
        ax1.grid(axis='y', linestyle='--', alpha=0.7)

        # 메뉴별 판매량 그래프
        ax2 = self.figure.add_subplot(212)
        ax2.bar(all_menu_items, menu_sales, color='orange')
        ax2.set_title(f"{sales_count} 판매량", fontsize=18, fontweight='bold')
        ax2.set_ylabel("수량(개)", fontsize=18, fontweight='bold', rotation=0, labelpad=65)
        ax2.set_xticks(range(len(all_menu_items)))
        ax2.set_xticklabels(all_menu_items, rotation=0, ha="center")
        ax2.grid(axis='y', linestyle='--', alpha=0.7)

        # 그래프 간격 조정
        self.figure.tight_layout(h_pad=2.5)
        self.canvas.draw()

def main():
    rclpy.init()

    executor = MultiThreadedExecutor()
    #노드 추가
    serviceNode = KitchenServiceNode()
    executor.add_node(serviceNode)

    # PyQt 애플리케이션 시작
    app = QApplication(sys.argv)

    window = KitchenDisplay()
    window.show()

    # 별도의 스레드에서 executor 실행
    executor_thread = threading.Thread(target=executor.spin, daemon=True)
    executor_thread.start()

    # PyQt 애플리케이션 종료 후 ROS 2 종료
    rclpy.shutdown()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
