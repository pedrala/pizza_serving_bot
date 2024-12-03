import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # kitchen monitor 노드 실행
        Node(
            package='pizza_serving_bot',
            executable='kitchen',
            name='kitchen_monitor',
            output='screen',
        ),

        # kiosk 노드 실행
        Node(
            package='pizza_serving_bot',
            executable='kiosk',
            name='table_order_kiosk',
            output='screen',
        ),

        # AMR 노드 실행
        Node(
            package='pizza_serving_bot',
            executable='amr',
            name='amr_controller',
            output='screen',
        ),
    ])
