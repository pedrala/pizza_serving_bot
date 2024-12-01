import sys
from pizza_order_msgs.srv import GoalLoc
from PyQt5.QtWidgets import QApplication, QLabel, QVBoxLayout, QWidget
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtSvg import QSvgWidget
from PyQt5.QtCore import QFile, QIODevice
from PyQt5.QtSvg import QSvgRenderer 
from PyQt5.QtGui import QPixmap, QPainter 
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QPushButton, QLabel, QListWidget, QGridLayout, QScrollArea,
    QFrame, QComboBox, QMessageBox, QSizePolicy, QListWidgetItem,
    QGroupBox
)
from PyQt5.QtWidgets import QSpacerItem, QSizePolicy
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import Odometry
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy
import os

# Map metadata
MAP_RESOLUTION = 0.05  # meters per pixel
MAP_ORIGIN = [-1.27, -2.47]  # [x, y]

# 상대 경로를 사용하여 img 디렉터리 설정
img_path = os.path.join(os.path.dirname(__file__), 'img')
img_path2 = os.path.abspath(os.path.join(os.path.dirname(__file__), 'amr_controller', 'img'))
#/home/viator/ws/b3_ws/pizza_serving_bot/pizza_serving_bot/amr_controller/img

table_coordinates = [
    {"table_number": 0, "x": 0.0, "y": -0.51},
    {"table_number": 1, "x": 2.5, "y": 2.0},   #오케이
    {"table_number": 2, "x": -1.0379695892333984, "y": -0.5310251712799072},
    {"table_number": 3, "x": 2.3, "y": -1.5},  #오케이
    {"table_number": 4, "x": 0.0048611038364470005, "y": -0.5726232528686523},
    {"table_number": 5, "x": 0.5, "y": 2.2},   #오케이
    {"table_number": 6, "x": -0.8, "y": -2.0}     
]

class AMRNode(Node):
    def __init__(self):
        super().__init__('amr_node')
        self.order_display_app = None

        self.table_number = None
        self.order_id = None
        self.status = 'Waiting'

        # 로봇의 현재 위치
        self.current_position = Point()

        # 초기 위치를 설정합니다.
        self.initial_position = {"table_number": 0}  # 초기 테이블 번호 예제
        self.get_logger().info(f"초기 위치 설정: {self.initial_position}")

        # 액션 클라이언트 생성
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # QoS 프로파일 생성 방식 변경
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,  
            depth=10
        )

        # 초기 위치 퍼블리셔
        self.initial_pose_pub = self.create_publisher(
            PoseWithCovarianceStamped,
            '/initialpose',
            qos_profile=qos_profile 
        )

        #odometry 또는 AMCL의 위치 정보를 구독
        self.pose_sub= self.create_subscription(
            Odometry,
            '/odom',  # 또는 '/amcl_pose'로 변경 가능
            self.pose_callback,
            qos_profile=qos_profile 
        )
        
        # 테이블 위치 받기 설정
        self.goal_loc_serv= self.create_service(
            GoalLoc, 
            'goal_loc', 
            self.goal_loc_callback,
            qos_profile=qos_profile 
        )

         # 초기 위치 설정
        self.set_initial_pose_from_table(0)

    def goal_loc_callback(self, request, response):
        self.get_logger().info("AMR Server is ready.")
        self.get_logger().info(f"goal_loc: {request}")
        try:
            # 주문과 연결된 테이블 번호 찾기
            table_coordinates_by_order = next(
                (coord for coord in table_coordinates if coord["table_number"] == request.table_number), 
                None
            )

            if table_coordinates_by_order is None:
                self.get_logger().error(f"테이블 번호 {request.table_number}에 해당하는 좌표를 찾을 수 없습니다.")
                response.send_result = False
                return response

            # 좌표 정보 기록
            self.table_number = request.table_number
            self.order_id = request.order_id
            self.status = request.status

            # 로그로 테이블 좌표 출력
            self.get_logger().info(f"목표 테이블 위치: 테이블 {self.table_number}, "
                                    f"X: {table_coordinates_by_order['x']}, "
                                    f"Y: {table_coordinates_by_order['y']}")

            # 실제 좌표를 response에도 포함
            response.send_result = True
            response.x = table_coordinates_by_order['x']
            response.y = table_coordinates_by_order['y']
            
            # 이미지 갱신
            self.order_display_app.update_display()

            # 테이블 번호를 받으면 출발 버튼 활성화
            self.order_display_app.trigger_start_delivery()

        except Exception as e:
            self.get_logger().error(f"목표 위치 처리 중 오류 발생: {e}")
            response.send_result = False

        return response
    
    def set_initial_pose(self, x, y, yaw):
        """초기 위치를 설정하고 퍼블리시하는 함수"""
        pose_msg = PoseWithCovarianceStamped()
        pose_msg.header.frame_id = 'map'
        pose_msg.header.stamp = self.get_clock().now().to_msg()

        pose_msg.pose.pose.position.x = x
        pose_msg.pose.pose.position.y = y
        pose_msg.pose.pose.orientation.z = yaw  # Assuming yaw is the quaternion z component
        pose_msg.pose.pose.orientation.w = 1.0

        self.initial_pose_pub.publish(pose_msg)
        self.get_logger().info(f"Initial pose set to x={x}, y={y}, yaw={yaw}")

    def set_initial_pose_from_table(self, table_number):
        """테이블 번호에 해당하는 좌표를 초기 위치로 설정하는 함수"""
        coordinates = next((coord for coord in table_coordinates if coord["table_number"] == table_number), None)
        if coordinates is None:
            self.get_logger().error(f"Table number {table_number} does not exist for initial pose.")
            return

        self.set_initial_pose(x=0.0, y=-0.51, yaw=0.0)
        #self.set_initial_pose(coordinates["x"], coordinates["y"], 0.0)  # yaw is set to 0.0 by default

    def send_goal(self, table_number, return_to_initial=False):
        """로봇을 목표 좌표로 이동시키는 함수"""
        coordinates = next((coord for coord in table_coordinates if coord["table_number"] == table_number), None)
        if coordinates is None:
            self.get_logger().error(f"테이블 번호 {table_number}에 해당하는 좌표가 없습니다.")
            return

        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.pose.position.x = coordinates["x"]
        goal_msg.pose.pose.position.y = coordinates["y"]
        goal_msg.pose.pose.orientation.w = 1.0

        self._action_client.wait_for_server()
        future = self._action_client.send_goal_async(goal_msg)
        future.add_done_callback(lambda f: self.goal_response_callback(f, table_number, return_to_initial))
        self.get_logger().info(f"목표가 전송되었습니다: 테이블 번호={table_number}, x={coordinates['x']}, y={coordinates['y']}")

        # Disable the start button once the goal is sent
        self.order_display_app.start_button.setEnabled(False)
        if  table_number == 0:
            self.status = "Going Home"  # Change status to in progress
        else :
            self.status = "Navigating"  # Change status to in progress
        self.order_display_app.update_display()  # Update the display with new status

    def goal_response_callback(self, future, table_number, return_to_initial):
        """목표 전송 결과를 처리하는 콜백 함수"""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info(f"테이블 {table_number}에 대한 목표가 거부되었습니다.")
            return

        self.get_logger().info(f"테이블 {table_number}에 대한 목표가 수락되었습니다. 이동을 시작합니다...")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self.goal_result_callback(f, table_number, return_to_initial))


    def goal_result_callback(self, future, table_number, return_to_initial):
        """목표 도달 결과를 처리하는 콜백 함수"""
        result = future.result().result
        if result:
            self.get_logger().info(f"테이블 {table_number}에 성공적으로 도달했습니다.")
            self.get_logger().info(f"테이블 위치: x={self.current_position.x}, y={self.current_position.y}")

            self.status = "Arrived"  # Change status to in progress
            self.show_popup(table_number)  # Show popup message
        else:
            self.get_logger().info(f"테이블 {table_number}에 도달하지 못했습니다.")

        if return_to_initial:
            # Once we return to the initial position, reset values
            self.get_logger().info("원위치로 돌아왔습니다. 상태 초기화 중...")
            self.get_logger().info(f"원위치 : x={self.current_position.x}, y={self.current_position.y}")

            self.status = 'Waiting'
            self.table_number = None
            self.order_id = None
            self.order_display_app.update_display()  # Update display after returning

    def show_popup(self, table_number):
        """목표 테이블에 도달했을 때 팝업 메시지를 띄우는 함수"""
        self.popup_msg = QMessageBox()  # 인스턴스 속성으로 저장
        self.popup_msg.setIcon(QMessageBox.Information)
        self.popup_msg.setWindowTitle("배달 완료")

        #현재위치가 원위치면 네비게이션 종료
        if  table_number == 0:
            self.ok_button = self.popup_msg.addButton(QMessageBox.Ok)
            self.popup_msg.setText(f"원위치입니다.")# OK 버튼 추가 및 저장            
            self.popup_msg.setWindowFlags(self.popup_msg.windowFlags() | Qt.WindowStaysOnTopHint)
            self.popup_msg.exec_()
        else :  
             # OK 버튼 추가 및 저장
            self.ok_button = self.popup_msg.addButton(QMessageBox.Ok)
            self.popup_msg.setText(f"{table_number}번 테이블 주문하신 피자 도착하였습니다.")
            self.popup_msg.buttonClicked.connect(self.on_popup_closed_direct)  # 메서드 직접 참조
            self.popup_msg.setWindowFlags(self.popup_msg.windowFlags() | Qt.WindowStaysOnTopHint)
            self.popup_msg.exec_()        

    def on_popup_closed_direct(self, button):
        """팝업 닫힌 후 실행되는 동작 (table_number를 다른 방식으로 전달)"""
        if button == self.ok_button or button.text() == "&OK":
            self.get_logger().info("확인 버튼 클릭: 원위치로 돌아갑니다...")
            if self.initial_position:  # initial_position이 설정되었는지 확인
                self.send_goal(self.initial_position["table_number"], return_to_initial=True)
            else:
                self.get_logger().error("초기 위치가 설정되지 않았습니다. 이동할 수 없습니다.")
                self.send_goal(self.initial_position["table_number"], return_to_initial=True)

    # Odometry로부터 로봇 위치 정보 받기
    def pose_callback(self, msg):
        # Odometry 메시지에서 위치 정보 가져오기image_messagex
        self.current_position.y = msg.pose.pose.position.y
        self.current_position.z = 0.0  # 2D 위치
        self.get_logger().info(f"AMR 위치 업데이트: x={self.current_position.x}, y={self.current_position.y}")


class OrderInfoDisplayApp(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node  # 이 부분에서 AMRNode를 전달받음
        if self.node is None:
            raise ValueError("AMRNode should not be None")

        # UI Setup
        self.setWindowTitle("Service Robot Status Display")
        self.setFixedSize(300, 400)  # Adjust the size of the window

        # Labels for displaying order information
        self.status_label = QLabel("Status: 대기중", self)
        self.order_label = QLabel("Order Id: ", self)
        self.table_label = QLabel("Table Number: ", self)
        
        # Create the start delivery button and set it to be initially disabled
        self.start_button = QPushButton("출발", self)
        self.start_button.setEnabled(False)  # Disable the button initially
        self.start_button.clicked.connect(self.start_delivery)

        # Aligning the labels and button to the center
        self.status_label.setAlignment(Qt.AlignCenter)
        self.order_label.setAlignment(Qt.AlignCenter)
        self.table_label.setAlignment(Qt.AlignCenter)
       
        # QLabel to hold the emoji
        self.emoji_label = QLabel(self)
        self.emoji_label.setAlignment(Qt.AlignCenter)  # Align the label
        self.emoji_label.setFixedSize(200, 220)  # Set size for the label

        # Layout Setup
        layout = QVBoxLayout()

        # Adding the labels and emoji at the top
        layout.addWidget(self.status_label)
        layout.addWidget(self.order_label)
        layout.addWidget(self.table_label)
        layout.addWidget(self.emoji_label)

        # Spacer to push the start button to the bottom
        spacer = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)
        layout.addItem(spacer)

        # Adding the start button at the bottom and centering it
        layout.addWidget(self.start_button, alignment=Qt.AlignCenter)

        # Center align all widgets in the layout
        layout.setAlignment(Qt.AlignCenter)

        self.setLayout(layout)

        # Timer to refresh UI
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_display)
        self.timer.start(500)  # Update every 500ms

    def update_display(self):
        self.status_label.setText(f"Status: {self.node.status}")
        self.order_label.setText(f"Order Id: {self.node.order_id}")
        self.table_label.setText(f"Table Number: {self.node.table_number}")

         # Change status and emoji based on the robot's status
        if self.node.status == 'Waiting':  # Sleeping face
            self.set_svg_image("sleeping.svg")
        elif self.node.status == 'Completed':  # Smiling face
            self.set_svg_image("smiling.svg")
        elif self.node.status == 'Navigating' or self.node.status == 'Going Home':  # Running animation
            self.set_svg_image("running.svg")  # Display running.svg for navigating status
        elif self.node.status == 'Arrived':  # Smiling face
            self.set_svg_image("smiling.svg")
        else:
            self.emoji_label.clear()  # Clear the image if status doesn't match

        self.emoji_label.update()  # Force update of the SVG widget

    def set_svg_image(self, svg_file):
        """Load and display an SVG file."""
        file_path = os.path.join(img_path, svg_file)    
        # QSvgRenderer 객체 생성
        renderer = QSvgRenderer(file_path)
        
        # QPixmap 생성 (이미지를 표시할 공간을 위해 크기 설정)
        pixmap = QPixmap(200, 220)  # 크기는 필요에 따라 조정
        
        # QPainter 객체 생성 (QPixmap에 그릴 수 있도록 설정)
        painter = QPainter(pixmap)
        
        # QPainter로 QSvgRenderer 렌더링
        renderer.render(painter)
        
        # QLabel에 QPixmap 설정
        self.emoji_label.setPixmap(pixmap)
        
        # 이미지 크기 조정
        self.emoji_label.setFixedSize(pixmap.size())  # QLabel 크기를 이미지 크기에 맞춤
        self.emoji_label.setAlignment(Qt.AlignCenter)  # 중앙 정렬

        # QPainter 종료
        painter.end()

        # 업데이트 호출하여 UI 반영
        self.emoji_label.update()
   
    def start_delivery(self):
        if self.node.table_number is not None:          
            self.node.status = 'Navigating'  # Update status to Navigating
            self.node.get_logger().info(f"Starting delivery to Table {self.node.table_number}")
            self.node.send_goal(self.node.table_number)
        else:
            self.node.get_logger().error("No table number set. Cannot start delivery.")
    
    def trigger_start_delivery(self):
        """Enable the start button when a table number is received."""
        self.start_button.setEnabled(True)  # Enable the start button     

def main():
    app = QApplication(sys.argv)
    rclpy.init()
    
    # ROS2 노드 생성
    serviceNode = AMRNode()

    # PyQt5 윈도우 생성
    window = OrderInfoDisplayApp(serviceNode)
    serviceNode.order_display_app = window

    window.show()

    # QTimer를 사용하여 ROS2 이벤트 주기적으로 실행
    timer = QTimer()
    timer.timeout.connect(lambda: rclpy.spin_once(serviceNode, timeout_sec=0.1))
    timer.start(10)  # 10ms마다 ROS2 이벤트 실행

    # PyQt5 이벤트 루프 실행
    exit_code = app.exec_()

    # 종료 처리
    serviceNode.destroy_node()
    rclpy.shutdown()
    sys.exit(exit_code)

if __name__ == "__main__":
    main()
