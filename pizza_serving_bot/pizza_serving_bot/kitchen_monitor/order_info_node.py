import rclpy
from rclpy.node import Node
from example_interfaces.msg import String  # 예시로 추가된 메시지, 실제로는 custom 메시지를 사용해야 함
from pizza_order_msgs import OrderInfo  # 우리가 만든 OrderInfo 메시지 (예시 이름)

class OrderInfoNode(Node):
    def __init__(self):
        super().__init__('order_info_node')
        self.publisher = self.create_publisher(OrderInfo, 'order_info', 10)
        self.timer = self.create_timer(1.0, self.publish_order_info)
        self.order_id = 1
        self.table_number = 5
        self.status = 'Order Received'

    def publish_order_info(self):
        msg = OrderInfo()
        msg.order_id = self.order_id
        msg.table_number = self.table_number
        msg.status = self.status

        self.publisher.publish(msg)
        self.get_logger().info(f'Publishing order info: {msg}')

        # Update order_id or status as needed for new orders
        self.order_id += 1
        self.status = 'Being Prepared' if self.order_id % 2 == 0 else 'Order Received'

def main(args=None):
    rclpy.init(args=args)
    node = OrderInfoNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
