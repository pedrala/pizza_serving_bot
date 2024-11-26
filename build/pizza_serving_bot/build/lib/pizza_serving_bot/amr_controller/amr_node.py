import os
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
import numpy as np
from rclpy.qos import QoSProfile, ReliabilityPolicy

class AMRNode(Node):
    def __init__(self):
        super().__init__('amr_node')

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,  # BEST_EFFORT 또는 RELIABLE
            depth=10
        )
        
        # 현재 위치를 발행할 토픽 생성
        self.position_publisher_ = self.create_publisher(Point, '/amr_current_position', qos_profile)
        
       
        # Odometry 또는 AMCL의 위치 정보를 구독
        self.pose_subscription_ = self.create_subscription(
            Odometry,
            '/odom',  # 또는 '/amcl_pose'로 변경 가능
            self.pose_callback,
            10
        )
        # 일정 주기로 위치와 영상을 퍼블리시 (초 단위로 설정 가능)
        self.timer_ = self.create_timer(1.0, self.publish_data)
        # 로봇의 현재 위치
        self.current_position = Point()

    # Odometry로부터 로봇 위치 정보 받기
    def pose_callback(self, msg):
        # Odometry 메시지에서 위치 정보 가져오기image_messagex
        self.current_position.y = msg.pose.pose.position.y
        self.current_position.z = 0.0  # 2D 위치
        self.get_logger().info(f"로봇 위치 업데이트: x={self.current_position.x}, y={self.current_position.y}")

    # 현재 좌표와 영상을 퍼블리시하는 함수
    def publish_data(self):
        # 좌표를 퍼블리시
        self.position_publisher_.publish(self.current_position)
        self.get_logger().info(f"AMR 현재 위치 발행: x={self.current_position.x}, y={self.current_position.y}")

    def destroy_node(self):
        # 카메라 자원 해제
        super().destroy_node()

# ROS2 노드 실행 함수
def main():
    rclpy.init()
    node = AMRNode()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
