import sys
from pizza_order_msgs.msg import OrderInfo
from PyQt5.QtWidgets import QApplication, QLabel, QVBoxLayout, QWidget
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import QTimer, Qt
import rclpy
from rclpy.node import Node
import os

class OrderInfoDisplay(Node):
    def __init__(self):
        super().__init__('order_info_display')
        self.status = '대기중'
        self.order_id = None
        self.table_number = None

        # ROS2 Subscriber
        self.create_subscription(OrderInfo, '/order_info', self.order_info_callback, 10)

    def order_info_callback(self, msg):
        try:
            order_info = eval(msg.data)  # Expecting a list: [order_id, table_number, status]
            if len(order_info) == 3:
                self.order_id, self.table_number, self.status = order_info
        except Exception as e:
            self.get_logger().error(f"Failed to process order_info: {e}")

class OrderInfoDisplayApp(QWidget):
    def __init__(self, node):
        super().__init__()
        self.node = node

        # UI Setup
        self.setWindowTitle("Service Robot Status Display")
        self.setFixedSize(500, 400)  # Adjust the size of the window

        # Labels for displaying order information
        self.status_label = QLabel("Status: 대기중", self)
        self.order_label = QLabel("Order Id: ", self)
        self.table_label = QLabel("Table Number: ", self)

        # Image label for emoji display
        self.emoji_label = QLabel(self)

        # Aligning the labels to the center
        self.status_label.setAlignment(Qt.AlignCenter)
        self.order_label.setAlignment(Qt.AlignCenter)
        self.table_label.setAlignment(Qt.AlignCenter)
        self.emoji_label.setAlignment(Qt.AlignCenter)

        # Layout Setup
        layout = QVBoxLayout()
        layout.addWidget(self.status_label)
        layout.addWidget(self.order_label)
        layout.addWidget(self.table_label)
        layout.addWidget(self.emoji_label)
        self.setLayout(layout)

        # Timer to refresh UI
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_display)
        self.timer.start(500)  # Update every 500ms

    def update_display(self):
        self.status_label.setText(f"Status: {self.node.status}")
        self.order_label.setText(f"Order Id: {self.node.order_id}")
        self.table_label.setText(f"Table Number: {self.node.table_number}")

        # Get the absolute path to the img directory
        base_path = "/home/viator/ws/b3_ws/pizza_serving_bot/pizza_serving_bot/amr_controller/img"

        # Create a QPixmap for each status and change the emoji accordingly
        if self.node.status == '대기중':  # Sleeping face
            pixmap = self.create_image("sleeping.png", base_path)
        elif self.node.status == '배달완료':  # Smiling face
            pixmap = self.create_image("smiling.png", base_path)
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


    def create_image(self, image_name, base_path):
        """Load an image from the file system."""
        base_path = "/home/viator/ws/b3_ws/pizza_serving_bot/pizza_serving_bot/amr_controller/img"
        image_path = os.path.join(base_path, image_name)

        # Check if the image exists
        if not os.path.exists(image_path):
            print(f"Image not found: {image_path}")
            return QPixmap()  # Return a null QPixmap if image is not found

        # Load the image from the file system and return as QPixmap
        pixmap = QPixmap(image_path)

        return pixmap

def main():
    rclpy.init()
    node = OrderInfoDisplay()

    app = QApplication(sys.argv)
    gui = OrderInfoDisplayApp(node)
    gui.show()

    # Run ROS2 node in a separate thread
    from threading import Thread
    ros_thread = Thread(target=rclpy.spin, args=(node,), daemon=True)
    ros_thread.start()

    # Run PyQt application
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
