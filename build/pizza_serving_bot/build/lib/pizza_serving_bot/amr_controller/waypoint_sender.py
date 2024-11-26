import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateThroughPoses
from rclpy.action import ActionClient

class WaypointSender(Node):
    def __init__(self):
        super().__init__('waypoint_sender')
        self._action_client = ActionClient(self, NavigateThroughPoses, 'navigate_through_poses')
    def send_waypoints(self, waypoints):
        goal_msg = NavigateThroughPoses.Goal()
        goal_msg.poses = []
        for wp in waypoints:
            pose = PoseStamped()
            pose.header.frame_id = "map"
            pose.header.stamp = self.get_clock().now().to_msg()
            pose.pose.position.x = wp[0]
            pose.pose.position.y = wp[1]
            pose.pose.orientation.z = wp[2]
            pose.pose.orientation.w = 1.0
            goal_msg.poses.append(pose)
        self._action_client.wait_for_server()
        self.get_logger().info(f'Sending {len(waypoints)} waypoints')
        self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        ).add_done_callback(self.goal_response_callback)
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Navigating through waypoints. Current waypoint: {feedback.current_pose_index}")
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Waypoints rejected :(')
            return
        self.get_logger().info('Waypoints accepted :)')
        goal_handle.get_result_async().add_done_callback(self.get_result_callback)
    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result: {result}')
        rclpy.shutdown()
def main():
    rclpy.init()
    node = WaypointSender()
    waypoints = [
        (1.0, 2.0, 0.0),  # (x, y, theta)
        (2.0, 3.0, 0.0),
        (3.0, 2.0, 0.0)
    ]
    node.send_waypoints(waypoints)
    rclpy.spin(node)
if __name__ == '__main__':
    main()