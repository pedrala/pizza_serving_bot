import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QPushButton
from PyQt5.QtGui import QPixmap


class OrderActionServer(Node):
    def __init__(self):
        super().__init__('order_action_server')
        # 서비스 서버 생성
        self.srv = self.create_service(SetBool, 'order_service', self.handle_order_request)
        self.get_logger().info("Order Service Server is ready.")
        
        # 액션 클라이언트 생성
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # GUI 생성
        self.gui = OrderGUI()

        # 초기 위치 (0, 0)으로 설정
        self.initial_position = (0.0, 0.0)

        # 초기 위치에서 이미지1 띄우기
        self.gui.update_image("image1.png")

    def handle_order_request(self, request, response):
        table_number = request.table_number
        order_number = request.order_id
        x = request.locx
        y = request.locy
        z = request.locz
        
        # 화면에 데이터 띄우기
        self.gui.update_order_info(table_number, order_number, x, y, z)

        # GUI의 확인 버튼을 눌렀을 때 이동 명령을 실행하도록 설정
        self.gui.confirm_button.clicked.connect(lambda: self.move_to_coordinates(x, y, table_number, order_number))

        response.success = True
        response.message = f"Order received: Table {table_number}, Order {order_number}, Coordinates ({x}, {y}, {z})"
        return response

    def move_to_coordinates(self, x, y, table_number, order_number):
        self.get_logger().info(f"Moving to coordinates: ({x}, {y})")
        
        # 이동 중 이미지2 띄우기
        self.gui.update_image("image2.png")
        
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = "map"
        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y
        goal_msg.pose.pose.orientation.w = 1.0  # 기본 방향 (회전 없음)

        self.send_goal_and_wait(goal_msg, table_number, order_number)

    def send_goal_and_wait(self, goal_msg, table_number, order_number):
        if not self._action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().error("Action server not available!")
            return

        send_goal_future = self._action_client.send_goal_async(goal_msg)
        send_goal_future.add_done_callback(lambda future: self.goal_response_callback(future, table_number, order_number))

    def goal_response_callback(self, future, table_number, order_number):
        result = future.result()
        if result:
            self.get_logger().info(f"Navigation successful to the specified coordinates.")
            # 좌표 도달 후 메시지 변경
            self.gui.update_message(f"음식을 테이블 위에 올려주세요")
            # 확인 버튼 클릭 시 초기 위치로 돌아가기
            self.gui.confirm_button.clicked.connect(self.move_back_to_initial_position)
        else:
            self.get_logger().error("Navigation failed.")

    def move_back_to_initial_position(self):
        self.get_logger().info("Returning to initial position.")
        x, y = self.initial_position
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = "map"
        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y
        goal_msg.pose.pose.orientation.w = 1.0  # 기본 방향 (회전 없음)

        # 초기 위치로 이동
        self.send_goal_and_wait(goal_msg, 0, 0)
        # 초기 위치에서 이미지1로 변경
        self.gui.update_image("image1.png")


class OrderGUI(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Order Details")
        self.setGeometry(100, 100, 400, 400)

        self.layout = QVBoxLayout()

        # QLabel들을 생성하여 정보를 표시
        self.table_label = QLabel("Table: Waiting for Order...")
        self.order_label = QLabel("Order: Waiting for Order...")
        self.coordinates_label = QLabel("Coordinates: Waiting for Order...")
        self.message_label = QLabel("Message: Waiting for Order...")

        # 이미지 표시를 위한 QLabel 추가
        self.image_label = QLabel(self)

        # 확인 버튼 생성
        self.confirm_button = QPushButton("Confirm Movement")

        self.layout.addWidget(self.image_label)  # 이미지를 위젯에 추가
        self.layout.addWidget(self.table_label)
        self.layout.addWidget(self.order_label)
        self.layout.addWidget(self.coordinates_label)
        self.layout.addWidget(self.message_label)
        self.layout.addWidget(self.confirm_button)

        self.setLayout(self.layout)

    def update_order_info(self, table_number, order_number, x, y, z):
        # GUI 업데이트: 받은 주문 정보를 표시
        self.table_label.setText(f"Table: {table_number}")
        self.order_label.setText(f"Order: {order_number}")
        self.coordinates_label.setText(f"Coordinates: ({x}, {y}, {z})")

    def update_message(self, message):
        # 메시지 레이블 업데이트
        self.message_label.setText(f"Message: {message}")

    def update_image(self, image_file):
        # 이미지를 QLabel에 표시
        pixmap = QPixmap(image_file)  # 이미지 파일 로드
        self.image_label.setPixmap(pixmap.scaled(300, 300))  # 이미지 크기 조정 후 표시


def main(args=None):
    rclpy.init(args=args)

    # PyQt5 앱 초기화
    app = QApplication(args)

    # OrderActionServer 노드와 GUI 실행
    node = OrderActionServer()

    # GUI 창 띄우기
    node.gui.show()

    # ROS 2 spin
    rclpy.spin(node)
    
    rclpy.shutdown()
    app.exec_()


if __name__ == '__main__':
    main()
