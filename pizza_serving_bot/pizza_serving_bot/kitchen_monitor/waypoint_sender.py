import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateThroughPoses
from rclpy.action import ActionClient

# Waypoint를 보내는 클래스를 정의
class WaypointSender(Node):
    def __init__(self):
        super().__init__('waypoint_sender')  # 노드 이름을 'waypoint_sender'로 설정
        # NavigateThroughPoses 액션 클라이언트를 생성
        self._action_client = ActionClient(self, NavigateThroughPoses, 'navigate_through_poses')
    
    # 여러 개의 waypoint를 전송하는 함수
    def send_waypoints(self, waypoints):
        # NavigateThroughPoses 메시지의 Goal 객체 생성
        goal_msg = NavigateThroughPoses.Goal()
        goal_msg.poses = []  # waypoints를 저장할 리스트 초기화

        # 주어진 waypoints에 대해 하나씩 PoseStamped 메시지 생성
        for wp in waypoints:
            pose = PoseStamped()
            pose.header.frame_id = "map"  # 좌표계는 "map"으로 설정
            pose.header.stamp = self.get_clock().now().to_msg()  # 현재 시간 스탬프 추가
            pose.pose.position.x = wp[0]  # x 좌표 설정
            pose.pose.position.y = wp[1]  # y 좌표 설정
            pose.pose.orientation.z = wp[2]  # 회전 각도 theta 설정
            pose.pose.orientation.w = 1.0  # 회전의 나머지 값 설정
            goal_msg.poses.append(pose)  # Pose를 goal_msg에 추가

        # 액션 서버와 연결될 때까지 대기
        self._action_client.wait_for_server()

        # waypoints를 전송한다고 로그에 출력
        self.get_logger().info(f'Sending {len(waypoints)} waypoints')

        # 목표를 비동기로 전송하고, 피드백과 응답 콜백을 설정
        self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback  # 피드백 콜백 함수
        ).add_done_callback(self.goal_response_callback)  # 목표 응답 콜백 함수 설정
    
    # 피드백을 받았을 때 호출되는 콜백 함수
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Navigating through waypoints. Current waypoint: {feedback.current_pose_index}")  # 현재 진행 중인 waypoint 출력
    
    # 목표 응답을 받은 후 호출되는 콜백 함수
    def goal_response_callback(self, future):
        goal_handle = future.result()  # 목표 처리 핸들 가져오기
        if not goal_handle.accepted:  # 목표가 거부되었을 경우
            self.get_logger().info('Waypoints rejected :(')
            return
        self.get_logger().info('Waypoints accepted :)')  # 목표가 승인되었을 경우
        # 목표 결과를 받았을 때 호출되는 콜백 함수 설정
        goal_handle.get_result_async().add_done_callback(self.get_result_callback)
    
    # 목표 결과를 받은 후 호출되는 콜백 함수
    def get_result_callback(self, future):
        result = future.result().result  # 결과 받아오기
        self.get_logger().info(f'Result: {result}')  # 결과 출력
        rclpy.shutdown()  # ROS2를 종료

# main 함수: WaypointSender 노드 초기화 및 waypoint 전송
def main():
    rclpy.init()  # ROS2 시스템 초기화
    node = WaypointSender()  # WaypointSender 노드 생성

    # 전달할 waypoint 목록 (x, y, theta)
    waypoints = [
        (1.0, 2.0, 0.0),  # 첫 번째 waypoint
        (2.0, 3.0, 0.0),  # 두 번째 waypoint
        (3.0, 2.0, 0.0)   # 세 번째 waypoint
    ]

    node.send_waypoints(waypoints)  # waypoints를 전송
    rclpy.spin(node)  # 노드 실행

if __name__ == '__main__':
    main()  # main 함수 실행
