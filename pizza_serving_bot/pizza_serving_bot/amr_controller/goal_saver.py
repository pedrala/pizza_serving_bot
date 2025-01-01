import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from rclpy.qos import QoSProfile, ReliabilityPolicy

class GoalSaver(Node):

    def __init__(self):
        super().__init__('goal_saver')

        # 6개의 테이블 좌표를 저장할 리스트
        self.table_coordinates = []

        # QoS 프로파일 생성 방식 변경
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,  
            depth=10
        )

        # '/goal' 토픽을 구독하여 Goal 클릭 시 콜백 함수 실행
        self.subscription = self.create_subscription(
            PoseStamped,
            '/goal',
            self.goal_callback,
            qos_profile=qos_profile 
        )

    def goal_callback(self, msg: PoseStamped):
        # RViz에서 클릭된 Goal 좌표를 테이블 좌표 리스트에 추가
        if len(self.table_coordinates) < 6:
            table_number = len(self.table_coordinates)  # 테이블 번호는 리스트의 길이에 맞게 할당
            x = msg.pose.position.x
            y = msg.pose.position.y

            # 테이블 좌표를 리스트에 추가
            self.table_coordinates.append({"table_number": table_number, "x": x, "y": y})

            # 좌표 출력 (디버깅용)
            self.get_logger().info(f"Received Goal: table_number={table_number}, x={x}, y={y}")
            self.get_logger().info(f"Updated table_coordinates: {self.table_coordinates}")
        else:
            self.get_logger().info("Maximum number of tables reached (6).")

def main(args=None):
    rclpy.init(args=args)
    goal_saver = GoalSaver()
    rclpy.spin(goal_saver)
    goal_saver.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
