import sys
from pizza_order_msgs.srv import GoalLoc
from PyQt5.QtWidgets import QApplication, QLabel, QVBoxLayout, QWidget
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import QTimer, Qt
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
from nav_msgs.msg import Odometry
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy
import os

# 상대 경로를 사용하여 img 디렉터리 설정
img_path = os.path.join(os.path.dirname(__file__), 'img')
img_path2 = os.path.abspath(os.path.join(os.path.dirname(__file__), 'amr_controller', 'img'))
#/home/viator/ws/b3_ws/pizza_serving_bot/pizza_serving_bot/amr_controller/img

table_coordinates = [
    {"table_number": 0, "x": -2.2494759559631348, "y": -0.00932601373642683},
    {"table_number": 1, "x": -1.0717217922210693, "y": 0.5569685697555542},
    {"table_number": 2, "x": -1.0379695892333984, "y": -0.5310251712799072},
    {"table_number": 3, "x": -0.012011311016976833, "y": 0.5289795398712158},
    {"table_number": 4, "x": 0.0048611038364470005, "y": -0.5726232528686523},
    {"table_number": 5, "x": 1.1286749839782715, "y": 0.542879581451416},
    {"table_number": 6, "x": 1.136879801750183, "y": -0.5590267181396484}
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

        # 액션 클라이언트 생성
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # QoS 프로파일 생성 방식 변경
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,  
            depth=10
        )
        
        #odometry 또는 AMCL의 위치 정보를 구독
        self.pose_subscription_ = self.create_subscription(
            Odometry,
            '/odom',  # 또는 '/amcl_pose'로 변경 가능
            self.pose_callback,
            10
        )
        
        # 테이블 위치 받기 설정
        self.srv = self.create_service(
            GoalLoc, 
            'goal_loc', 
            self.goal_loc_callback,
            qos_profile=qos_profile 
        )

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
                response.status = "좌표 없음"
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
            response.x = table_coordinates_by_order['x']
            response.y = table_coordinates_by_order['y']
            
            #이미지 갱신
            self.order_display_app.update_display()

            # 테이블 번호를 받으면 출발 버튼 활성화
            self.order_display_app.trigger_start_delivery()


        except Exception as e:
            self.get_logger().error(f"목표 위치 처리 중 오류 발생: {e}")
            #response.status = "오류 발생"

        return response
    
    def send_goal(self, table_number):
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        
        coordinates = next((coord for coord in table_coordinates if coord["table_number"] == table_number), None)
        if coordinates is None:
            self.get_logger().error(f"테이블 번호 {table_number}에 해당하는 좌표를 찾을 수 없습니다.")
            return
        
        goal_msg.pose.pose.position.x = coordinates["x"]
        goal_msg.pose.pose.position.y = coordinates["y"]
        goal_msg.pose.pose.orientation.w = 1.0
        
        self._action_client.wait_for_server()
        future = self._action_client.send_goal_async(goal_msg)
        future.add_done_callback(lambda f: self.goal_response_callback(f, table_number))
        self.get_logger().info(f"Goal sent: table_number={table_number}, x={coordinates['x']}, y={coordinates['y']}.")

    def goal_response_callback(self, future, table_number):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info(f"Goal for Table {table_number} was rejected by the server.")
            return
        
        self.get_logger().info(f"Goal for Table {table_number} was accepted. Moving now...")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self.goal_result_callback(f, table_number))

    def goal_result_callback(self, future, table_number):
        result = future.result().result
        if result:
            self.get_logger().info(f"Successfully arrived at Table {table_number}.")
        else:
            self.get_logger().info(f"Failed to reach Table {table_number}.")
        
    # Odometry로부터 로봇 위치 정보 받기
    def pose_callback(self, msg):
        # Odometry 메시지에서 위치 정보 가져오기image_messagex
        self.current_position.y = msg.pose.pose.position.y
        self.current_position.z = 0.0  # 2D 위치
        self.get_logger().info(f"로봇 위치 업데이트: x={self.current_position.x}, y={self.current_position.y}")


class OrderInfoDisplayApp(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node  # 이 부분에서 AMRNode를 전달받음
        if self.node is None:
            raise ValueError("AMRNode should not be None")

        # UI Setup
        self.setWindowTitle("Service Robot Status Display")
        self.setFixedSize(500, 400)  # Adjust the size of the window

        # Labels for displaying order information
        self.status_label = QLabel("Status: 대기중", self)
        self.order_label = QLabel("Order Id: ", self)
        self.table_label = QLabel("Table Number: ", self)

        # Image label for emoji display
        self.emoji_label = QLabel(self)

        # Create the start delivery button and set it to be initially disabled
        self.start_button = QPushButton("출발", self)
        self.start_button.setEnabled(False)  # Disable the button initially
        self.start_button.clicked.connect(self.start_delivery)

        # Aligning the labels and button to the center
        self.status_label.setAlignment(Qt.AlignCenter)
        self.order_label.setAlignment(Qt.AlignCenter)
        self.table_label.setAlignment(Qt.AlignCenter)
        self.emoji_label.setAlignment(Qt.AlignCenter)

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

        self.setLayout(layout)

        # Timer to refresh UI
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_display)
        self.timer.start(500)  # Update every 500ms

    def update_display(self):
        self.status_label.setText(f"Status: {self.node.status}")
        self.order_label.setText(f"Order Id: {self.node.order_id}")
        self.table_label.setText(f"Table Number: {self.node.table_number}")

        # Create a QPixmap for each status and change the emoji accordingly
        if self.node.status == 'Waiting':  # Sleeping face
            pixmap = self.create_image("sleeping.png")
        elif self.node.status == 'Completed':  # Smiling face
            pixmap = self.create_image("smiling.png")
        else:
            pixmap = QPixmap()  # Empty if status doesn't match

        if not pixmap.isNull():
            # Get the current window size
            window_width = self.size().width()
            window_height = self.size().height()

            # Scale the image to 70% of the window size
            scaled_width = int(window_width * 0.7)
            scaled_height = int(window_height * 0.7)
            self.emoji_label.setPixmap(pixmap.scaled(scaled_width, scaled_height, Qt.KeepAspectRatio))
        else:
            # Handle the case where the pixmap is null (image not found)
            self.emoji_label.setText("Image not found")  # Show a placeholder text


    def create_image(self, image_name):
        """Load an image from the file system."""
        image_path = os.path.join(img_path, image_name)
        
        if not os.path.exists(image_path):
            print(f"Image not found: {image_path}")
            return QPixmap()
        
        pixmap = QPixmap(image_path)
        if pixmap.isNull():
            print(f"Failed to load image: {image_path}")
            return QPixmap()
        
        return pixmap

    
    def start_delivery(self):
        if self.node.table_number is not None:          
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
