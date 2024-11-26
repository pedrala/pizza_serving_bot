import rclpy
from rclpy.node import Node
from pizza_order_msgs.srv import OrderService
from pizza_order_msgs.msg import OrderDetail  # OrderDetail 메시지 임포트

class TableNode(Node):
    def __init__(self):
        super().__init__('table_node')
        self.cli = self.create_client(OrderService, 'process_order')

        # Ensure the service is available
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for OrderService to become available...')

        self.get_logger().info('OrderService is available. Ready to send orders.')

        # Example usage: Simulate sending an order
        self.send_order(order_id=1, table_number=5, detail_id=2, 
                        item_ids=[101, 102],
                        item_names=['Pizza Margherita', 'Coke'],
                        quantities=[2, 3], prices=[12.5, 2.5])

    def send_order(self, order_id, table_number, detail_id, item_ids, item_names, quantities, prices):
        request = OrderService.Request()
        request.order_id = order_id
        request.table_number = table_number
        request.detail_id = detail_id

        # Create OrderDetail objects for each item
        order_details = []
        for item_id, item_name, quantity, price in zip(item_ids, item_names, quantities, prices):
            order_detail = OrderDetail()
            order_detail.item_id = item_id
            order_detail.item_name = item_name
            order_detail.quantity = quantity
            order_detail.price = price
            order_details.append(order_detail)

        # Add the list of OrderDetail objects to the request
        request.order_details = order_details

        self.get_logger().info(f'Sending order: Order ID={order_id}, Table Number={table_number}, Details={item_names}')
        
        self.future = self.cli.call_async(request)
        self.future.add_done_callback(self.order_response_callback)

    def order_response_callback(self, future):
        try:
            response = future.result()
            if response.order_result:
                self.get_logger().info('Order placed successfully.')
            else:
                self.get_logger().error('Order failed to be placed.')
        except Exception as e:
            self.get_logger().error(f'Failed to process order response: {e}')

def main():
    rclpy.init()
    node = TableNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
