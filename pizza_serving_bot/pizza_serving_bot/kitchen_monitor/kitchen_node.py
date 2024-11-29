import datetime
import sqlite3
import sys
import os
import matplotlib
from matplotlib import font_manager
from matplotlib.figure import Figure
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
import requests
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

api_base_url = "http://192.168.123.47:5000/api"  # API 서버 주소

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
        self.setWindowTitle("Kitchen Display System")
        self.setGeometry(100, 100, 1660, 1080)

        self.main_layout = QVBoxLayout()
        self.top_layout = QHBoxLayout()

        self.robot_label = QLabel("ROBOT COORDINATE : X(  ), Y(  ), Z(  )")
        self.robot_label.setStyleSheet("font-size: 16px; font-weight: bold;")
        self.top_layout.addWidget(self.robot_label, alignment=Qt.AlignLeft)

        self.title_label = QLabel("KITCHEN DISPLAY")
        self.title_label.setAlignment(Qt.AlignCenter)
        self.title_label.setStyleSheet("font-size: 30px; font-weight: bold; color: green;")
        self.top_layout.addWidget(self.title_label)

        self.sales_layout = QHBoxLayout()
        self.day_sales_button = QPushButton("DAY")
        self.month_sales_button = QPushButton("MONTH")
        self.year_sales_button = QPushButton("YEAR")

        self.day_sales_button.clicked.connect(lambda: self.show_sales_window("DAY"))
        self.month_sales_button.clicked.connect(lambda: self.show_sales_window("MONTH"))
        self.year_sales_button.clicked.connect(lambda: self.show_sales_window("YEAR"))

        for button in [self.day_sales_button, self.month_sales_button, self.year_sales_button]:
            button.setStyleSheet("font-size: 16px; padding: 10px;")
            self.sales_layout.addWidget(button)

        self.top_layout.addLayout(self.sales_layout)
        self.main_layout.addLayout(self.top_layout)

        self.scroll_area = QScrollArea()
        self.scroll_area.setWidgetResizable(True)

        self.order_widget = QWidget()
        self.order_widget.setStyleSheet("background-color: #F0F0F0;")
        self.grid_layout = QGridLayout()
        self.grid_layout.setSpacing(20)
        self.order_widget.setLayout(self.grid_layout)

        self.scroll_area.setWidget(self.order_widget)
        self.main_layout.addWidget(self.scroll_area)

        self.order_cards = []
        self.rows = 2
        self.cols = 4

        self.load_orders()  # API 또는 데이터베이스에서 주문 로드

        self.setLayout(self.main_layout)
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.refresh_orders)
        self.timer.start(1000)  # 1초마다 새로고침

    def show_sales_window(self, sales_type):
        self.sales_window = SalesWindow(sales_type)
        self.sales_window.show()

    def load_orders(self):
        try:
            response = requests.get(f"{api_base_url}/orders")
            if response.status_code == 200:
                orders = response.json()
                self.clear_order_cards()
                for order_id, data in orders.items():
                    self.add_order_card(order_id, data["timestamp"], data["table_number"], data["menu_items"])
            else:
                print(f"Failed to load orders, status code: {response.status_code}")
        except Exception as e:
            print(f"Error loading orders: {e}")

    def add_order_card(self, order_id, order_time, table_number, menu_items):
        card = self.create_order_card(order_id, order_time, table_number, menu_items)
        row = len(self.order_cards) // self.cols
        col = len(self.order_cards) % self.cols
        self.grid_layout.addWidget(card, row, col)
        self.order_cards.append(card)

    def create_order_card(self, order_id, order_time, table_number, menu_items):
        card = QGroupBox()
        card_layout = QVBoxLayout()
        card_layout.setAlignment(Qt.AlignTop)

        order_id_label = QLabel(f"Order #{order_id}")
        order_id_label.setFixedHeight(50)
        order_id_label.setAlignment(Qt.AlignCenter)
        order_id_label.setStyleSheet("font-size: 28px; font-weight: bold; color: green;")
        card_layout.addWidget(order_id_label)

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

        for item in menu_items:
            menu_label = QLabel(f"  • {item}")
            menu_label.setStyleSheet("font-size: 20px;")
            menu_label.setFixedHeight(50)
            card_layout.addWidget(menu_label)

        cancel_button = QPushButton("Cancel Order")
        cancel_button.setStyleSheet("""
            background-color: red;
            color: white;
            font-size: 20px;
            padding: 5px 10px;
            border-radius: 5px;
        """)
        cancel_button.clicked.connect(lambda: self.update_order_status(order_id, "Canceled"))
        card_layout.addWidget(cancel_button)

        complete_button = QPushButton("Complete Order")
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
        card.setStyleSheet("""
            QGroupBox {
                background-color: white;
                border: 2px solid green;
                border-radius: 10px;
                padding: 15px;
            }
        """)

        return card

    def update_order_status(self, order_id, status):
        try:
            response = requests.put(f"{api_base_url}/order/{order_id}/{status}")
            if response.status_code == 200:
                print(f"Order {order_id} status updated to {status}")
                self.refresh_orders()
            else:
                print(f"Failed to update order status, status code: {response.status_code}")
        except Exception as e:
            print(f"Error updating order status: {e}")

    def refresh_orders(self):
        self.load_orders()

    def clear_order_cards(self):
        for card in self.order_cards:
            card.setParent(None)
        self.order_cards.clear()


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
        try:
            # 매출 데이터와 메뉴 판매량 데이터 API 호출
            sales_response = requests.get(f"{api_base_url}/sales/{sales_type.lower()}")
            menu_response = requests.get(f"{api_base_url}/menu_sales/{sales_type.lower()}")

            if sales_response.status_code == 200 and menu_response.status_code == 200:
                sales_data = sales_response.json()
                menu_data = menu_response.json()

                labels = sales_data.get("labels", [])
                sales = sales_data.get("sales", [])
                all_menu_items = menu_data.get("menu_items", [])
                menu_sales = menu_data.get("menu_sales", [])
            else:
                print(f"Failed to fetch data: Sales({sales_response.status_code}), Menu({menu_response.status_code})")
                labels, sales, all_menu_items, menu_sales = [], [], [], []

        except Exception as e:
            print(f"Error fetching graph data: {e}")
            labels, sales, all_menu_items, menu_sales = [], [], [], []

        # 그래프 그리기
        self.figure.clear()

        # 매출액 그래프
        ax1 = self.figure.add_subplot(211)
        ax1.bar(labels, sales, color='green')
        ax1.set_title(f"{sales_type} 매출액", fontsize=18, fontweight='bold')
        ax1.set_ylabel("금액(원)", fontsize=18, fontweight='bold', rotation=0, labelpad=45)
        ax1.grid(axis='y', linestyle='--', alpha=0.7)

        # 메뉴별 판매량 그래프
        ax2 = self.figure.add_subplot(212)
        ax2.bar(all_menu_items, menu_sales, color='orange')
        ax2.set_title(f"{sales_type} 판매량", fontsize=18, fontweight='bold')
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
