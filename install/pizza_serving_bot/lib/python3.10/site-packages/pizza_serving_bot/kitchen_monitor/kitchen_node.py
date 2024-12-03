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
from pizza_order_msgs.srv import CancelService
from pizza_order_msgs.msg import CallManager
from pizza_order_msgs.srv import GoalLoc
from std_msgs.msg import String  # ROS 2 String 메시지 타입
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QPushButton, QLabel, QListWidget, QGridLayout, QScrollArea,
    QFrame, QComboBox, QMessageBox, QSizePolicy, QListWidgetItem,
    QGroupBox
)
from PyQt5.QtCore import Qt, QTimer,pyqtSignal,QThread, QObject
from datetime import datetime
from rclpy.executors import MultiThreadedExecutor
import threading

font_path = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"  # Ubuntu Noto Sans CJK 폰트 경로
font_prop = font_manager.FontProperties(fname=font_path)
matplotlib.rc('font', family=font_prop.get_name())

api_base_url = "http://192.168.0.18:5000/api"  # API 서버 주소

class SignalBridge(QObject):
    table_call_signal = pyqtSignal(str)  # 테이블 호출 신호

class KitchenServiceNode(Node):
    def __init__(self, signal_bridge):
        super().__init__('kitchen_service_node')

        # ROS2 노드 초기화
        if not rclpy.ok():
            rclpy.init()  # ROS2 초기화

         # SignalBridge 객체를 내부에서 생성
        self.signal_bridge = signal_bridge  # SignalBridge 객체 생성

        # QoS 프로파일 생성 방식 변경
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,  
            depth=10
        )

        # 주문서비스 서버설정
        self.order_ser = self.create_service(
            OrderService, 
            'process_order', 
            self.process_order_callback,
            qos_profile=qos_profile 
        )

        # 주문취소서비스 클라이언트설정
        self.cancel_cli = self.create_client(
            CancelService, 
            'cancel_order', 
            qos_profile=qos_profile 
        )

        # 직원호출 구독설정
        self.call_manager_sub = self.create_subscription(
            CallManager, 
            'call_manager', 
            self.call_manager_callback,
            qos_profile=qos_profile 
        )

        #주문정보와 골(테이블위치) 클라이언트 설정
        self.order_cli = self.create_client(
            GoalLoc, 
            'goal_loc', 
            qos_profile=qos_profile  
        )
    
    def process_order_callback(self, request, response):
        self.get_logger().info('주문 처리 중: %s' % request.order_id)
        # 주문 처리 로직 추가
        response.status = "Compeleted"
        return response
    

    def call_manager_callback(self, msg):
        # 테이블 번호를 가져와서 팝업창에 표시
        self.get_logger().info(f"table number: {msg.table_number}")

        self.get_logger().info(f"테이블번호 {msg.table_number}로부터 직원호출이 요청되었습니다.")
        popup_message = f"테이블번호 {msg.table_number}로부터 직원호출이 요청되었습니다."
        self.signal_bridge.table_call_signal.emit(popup_message)  # PyQt 신호 전송

class KitchenDisplay(QWidget):
    show_popup_signal = pyqtSignal(str)  # 팝업 메시지를 위한 Signal 정의

    def __init__(self, signal_bridge, service_node):
        #super().__init__('kitchen_display')
      
        QWidget.__init__(self)  # QWidget 초기화

        self.signal_bridge = signal_bridge
        self.service_node = service_node  # KitchenServiceNode 객체를 저장

        self.setWindowTitle("Kitchen Display System")
        self.setGeometry(100, 100, 1660, 1080)

        self.main_layout = QVBoxLayout()
        self.top_layout = QHBoxLayout()

        # 상단 레이아웃: 제목 및 좌표 표시
        self.robot_label = QLabel("ROBOT COORDINATE : X(  ), Y(  ), Z(  )")
        self.robot_label.setStyleSheet("font-size: 16px; font-weight: bold;")
        self.top_layout.addWidget(self.robot_label, alignment=Qt.AlignLeft)

        self.title_label = QLabel("KITCHEN DISPLAY")
        self.title_label.setAlignment(Qt.AlignCenter)
        self.title_label.setStyleSheet("font-size: 30px; font-weight: bold; color: green;")
        self.top_layout.addWidget(self.title_label)

        # 직원 호출 상태 표시
        self.call_label = QLabel("No calls yet")
        self.call_label.setStyleSheet("font-size: 18px; font-weight: bold; color: red;")
        self.top_layout.addWidget(self.call_label, alignment=Qt.AlignRight)

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

        # 주문 카드 상태 저장
        self.order_cards = []
        self.rows = 2
        self.cols = 4

        self.load_orders()  # API 또는 데이터베이스에서 주문 로드

        # 메인 레이아웃 설정
        self.setLayout(self.main_layout)

        # Signal-Slot 연결
        self.show_popup_signal.connect(self.show_popup_message)

        # ROS 2와 연결된 SignalBridge 신호 연결
        signal_bridge.table_call_signal.connect(self.show_popup_message)

        # 주문 새로고침 타이머
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.refresh_orders)
        self.timer.start(1000)  # 1초마다 새로고침

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

    def show_sales_window(self, sales_type):
        self.sales_window = SalesWindow(sales_type)
        self.sales_window.show()

    def load_orders(self):
        try:
            response = requests.get(f"{ api_base_url}/orders")
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
        """
        새로운 주문 카드 추가
        """
        card = self.create_order_card(order_id, order_time, table_number, menu_items)
        self.order_cards.append(card)  # 카드 리스트에 추가
        self.update_order_grid()  # 그리드 업데이트
        
    def update_order_grid(self):
        """
        주문 그리드가 항상 2x4 형태를 유지하도록 구현.
        """
        # 기존 위젯 모두 제거
        for i in reversed(range(self.grid_layout.count())):
            widget_item = self.grid_layout.itemAt(i)
            if widget_item:
                widget = widget_item.widget()
                if widget:
                    self.grid_layout.removeWidget(widget)
                    widget.setParent(None)

        # 주문 카드 추가
        for index, card in enumerate(self.order_cards):
            row = index // self.cols
            col = index % self.cols
            self.grid_layout.addWidget(card, row, col)

        # 총 슬롯 수 계산 (2x4 그리드)
        total_slots = self.rows * self.cols

        # 부족한 슬롯에 빈 공간 추가
        for i in range(len(self.order_cards), total_slots):
            row = i // self.cols
            col = i % self.cols
            placeholder = QLabel("")  # 빈 공간
            placeholder.setStyleSheet("background-color: #E0E0E0; border: 1px dashed gray;")  # 시각적 구분
            self.grid_layout.addWidget(placeholder, row, col)

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
        cancel_button.clicked.connect(lambda: self.cancel_order(order_id, table_number, "Cancelled"))
        card_layout.addWidget(cancel_button)

        complete_button = QPushButton("Complete Order")
        complete_button.setStyleSheet("""
            background-color: blue;
            color: white;
            font-size: 20px;
            padding: 5px 10px;
            border-radius: 5px;
        """)
        complete_button.clicked.connect(lambda: self.call_amr(order_id, table_number, "Completed"))
        card_layout.addWidget(complete_button)
        complete_button = QPushButton("Complete Order")

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
            # 주문 새로고침
            self.refresh_orders()

            response = requests.put(f"{api_base_url}/order/{order_id}/{status}")
            if response.status_code == 200:
                print(f"Order {order_id} status updated to {status}")
                self.refresh_orders()
            else:
                print(f"Failed to update order status, status code: {response.status_code}")
                   
        except Exception as e:
            print(f"Error updating order status: {e}")

    def call_amr(self, order_id, table_number, status):
        print("status: "+ status )
        print("order_id: "+ order_id)  
        # GoalLoc 클라이언트를 이용하여 테이블 위치 정보 요청
        goal_loc_request = GoalLoc.Request()  
        # order_id를 정수로 변환
        goal_loc_request.order_id = int(order_id)
        goal_loc_request.table_number = int(table_number)
        goal_loc_request.status = "Completed"
        print("order_id: " + str(goal_loc_request.order_id))
        print("table_number: " + str(goal_loc_request.table_number))

        # service_node의 ROS 노드와 클라이언트 사용
        orderCli = self.service_node.order_cli

        # 서비스 호출
        future = orderCli.call_async(goal_loc_request)
        #rclpy.spin_until_future_complete(node, future)

         # 멀티스레드 Executor 생성
        from rclpy.executors import MultiThreadedExecutor
        executor = MultiThreadedExecutor()
        executor.add_node(self.service_node)

        # spin_until_future_complete 호출
        try:
            rclpy.spin_until_future_complete(self.service_node, future, executor=executor)
        except Exception as e:
            print(f"Error during spin_until_future_complete: {e}")
            return
        
        if future.result() is not None:
            result = future.result()
            # 결과 출력
            print(f"Navigation Result: success={result.send_result}, "
                    f"x={result.x}, y={result.y}")
        else:
            print("Navigation failed")
          
        # DB 업데이트
        self.update_order_status(order_id, status)

    def cancel_order(self, order_id, table_number, status):

        print("status: "+ status )
        print("order_id: "+ order_id)
    
        # order_id를 정수로 변환
        can_ser_request = CancelService.Request()
        can_ser_request.order_id = int(order_id)
        can_ser_request.table_number = int(table_number)
        print("order_id: " + str(can_ser_request.order_id))
        print("table_number: " + str(can_ser_request.table_number))

        # ROS2 서비스 호출
        future = self.service_node.cancel_cli.call_async(can_ser_request)
        future.add_done_callback(self.cancel_response_callback)

        # 사용자에게 주문 취소 메시지 표시
        QMessageBox.information(self, "주문 취소", f"주문 번호 : {order_id}번\n주문이 취소되었습니다.\n테이블 번호: \n{table_number}")

        # DB 업데이트
        self.update_order_status(order_id, status)

    def cancel_response_callback(self, future):
        try:
            response = future.result()
            if response.status == "Cancelled":
                QMessageBox.information(self, "주문 취소", "주문이 성공적으로 취소되었습니다.")
            else:
                QMessageBox.warning(self, "주문 취소 실패", "주문 취소 요청이 실패했습니다.")
        except Exception as e:
            QMessageBox.critical(self, "오류 발생", f"주문 취소 처리 중 오류가 발생했습니다: {e}")


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

        print(f"sales_type:{sales_type}")

        try:
            # sales_type 값을 소문자로 전달하기 전에 유효성 검사
            valid_sales_types = ["day", "month", "year"]  # 허용된 sales_type 값 목록
            if sales_type.lower() not in valid_sales_types:
                print(f"[ERROR] Invalid sales type: {sales_type}")
                return  # 잘못된 값일 경우 처리 중단
        
            response_sales = requests.get(f"{api_base_url}/sales/{sales_type}")
            print(f"[DEBUG] Sales API Response: {response_sales.status_code}, {response_sales.text}")

            response_menu_sales = requests.get(f"{api_base_url}/menu_sales/{sales_type}")
            print(f"[DEBUG] Menu Sales API Response: {response_menu_sales.status_code}, {response_menu_sales.text}")

            if response_sales.status_code != 200:
                print(f"[ERROR] Failed to fetch sales data: {response_sales.status_code}")
                return
            if response_menu_sales.status_code != 200:
                print(f"[ERROR] Failed to fetch menu sales data: {response_menu_sales.status_code}")
                return

            # 응답 데이터 파싱
            sales_data = response_sales.json()
            menu_sales_data = response_menu_sales.json()

            # 매출액 데이터
            labels = sales_data.get('labels', [])
            sales = sales_data.get('sales', [])

            # 메뉴별 판매량 데이터
            menu_names = menu_sales_data.get('menu_names', [])
            menu_sales = menu_sales_data.get('menu_sales', [])

            print(f"[DEBUG] Parsed Sales Data: {labels}, {sales}")
            print(f"[DEBUG] Parsed Menu Sales Data: {menu_names}, {menu_sales}")

        except Exception as e:
            print(f"Error: {e}")
            return
        
        # 그래프 그리기
        self.figure.clear()

        # 상단: 매출액 그래프
        ax1 = self.figure.add_subplot(211)
        ax1.bar(labels, sales, color='green')
        ax1.set_title("매출액", fontsize=18, fontweight='bold')
        ax1.set_ylabel("금액(원)", fontsize=18, fontweight='bold', rotation=0, labelpad=45)
        ax1.grid(axis='y', linestyle='--', alpha=0.7)

        # 하단: 메뉴별 판매량 그래프
        ax2 = self.figure.add_subplot(212)
        ax2.bar(menu_names, menu_sales, color='orange')
        ax2.set_title("판매량", fontsize=18, fontweight='bold')
        ax2.set_ylabel("수량(개)", fontsize=18, fontweight='bold', rotation=0, labelpad=70)
        ax2.set_xticks(range(len(menu_names)))
        ax2.set_xticklabels(menu_names, rotation=0, ha="center")  # 메뉴 이름 회전
        ax2.grid(axis='y', linestyle='--', alpha=0.7)

def main():
    # ROS 2 초기화
    rclpy.init()

    # QApplication 생성
    app = QApplication(sys.argv)

    # SignalBridge와 노드 생성
    signal_bridge = SignalBridge()
    service_node = KitchenServiceNode(signal_bridge)
    display_node = KitchenDisplay(signal_bridge, service_node)

    # 멀티스레드 executor 생성
    executor = MultiThreadedExecutor()
    executor.add_node(service_node)  # service_node의 ROS 노드 추가
    display_node.show()
    #executor.add_node(display_node)

    # ROS 2 스핀을 별도의 스레드에서 실행
    def ros_spin():
        try:
            executor.spin()
        except Exception as e:
            print(f"ROS Executor error: {e}")
        finally:
            executor.shutdown()
            rclpy.shutdown()

    ros_thread = threading.Thread(target=ros_spin, daemon=True)
    ros_thread.start()

    # 윈도우 표시
    display_node.show()

    # PyQt 이벤트 루프 실행
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()