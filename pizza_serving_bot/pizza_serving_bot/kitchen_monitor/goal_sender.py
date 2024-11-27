import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient

# 목표를 보내는 클래스를 정의
class GoalSender(Node):
    def __init__(self):
        super().__init__('goal_sender')  # 노드 이름을 'goal_sender'로 설정
        # NavigateToPose 액션 클라이언트를 생성
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
    
    # 목표를 보낼 함수
    def send_goal(self, x, y, theta):
        # NavigateToPose 메시지의 Goal 객체 생성
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = "map"  # 좌표계는 "map"으로 설정
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()  # 현재 시간 스탬프 추가
        goal_msg.pose.pose.position.x = x  # 목표 x 좌표 설정
        goal_msg.pose.pose.position.y = y  # 목표 y 좌표 설정
        goal_msg.pose.pose.orientation.z = theta  # 목표 theta(회전 각도) 설정
        goal_msg.pose.pose.orientation.w = 1.0  # 회전의 나머지 값 설정

        # 액션 서버와 연결될 때까지 대기
        self._action_client.wait_for_server()

        # 목표를 전송한다고 로그에 출력
        self.get_logger().info(f'Sending goal to: x={x}, y={y}, theta={theta}')

        # 목표를 비동기로 전송하고, 피드백과 응답 콜백을 설정
        self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback  # 피드백 콜백 함수
        ).add_done_callback(self.goal_response_callback)  # 목표 응답 콜백 함수 설정
    
    # 피드백을 받았을 때 호출되는 콜백 함수
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Current progress: {feedback.current_pose}")  # 진행 중인 목표의 현재 상태 출력
    
    # 목표 응답을 받은 후 호출되는 콜백 함수
    def goal_response_callback(self, future):
        goal_handle = future.result()  # 목표 처리 핸들 가져오기
        if not goal_handle.accepted:  # 목표가 거부되었을 경우
            self.get_logger().info('Goal rejected :(')
            return
        self.get_logger().info('Goal accepted :)')  # 목표가 승인되었을 경우
        # 목표 결과를 받았을 때 호출되는 콜백 함수 설정
        goal_handle.get_result_async().add_done_callback(self.get_result_callback)
    
    # 목표 결과를 받은 후 호출되는 콜백 함수
    def get_result_callback(self, future):
        result = future.result().result  # 결과 받아오기
        self.get_logger().info(f'Result: {result}')  # 결과 출력
        rclpy.shutdown()  # ROS2를 종료

# main 함수: GoalSender 노드 초기화 및 목표 전송
def main():
    rclpy.init()  # ROS2 시스템 초기화
    node = GoalSender()  # GoalSender 노드 생성
    node.send_goal(2.0, 3.0, 0.0)  # 목표 좌표: x=2.0, y=3.0, theta=0.0 전송
    rclpy.spin(node)  # 노드 실행

if __name__ == '__main__':
    main()  # main 함수 실행
