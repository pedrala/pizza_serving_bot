import sys
import sqlite3
import rclpy
from rclpy.node import Node
from PyQt5.QtWidgets import QApplication, QMainWindow, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget
from pizza_order_msgs.srv import OrderService

class KitchenNode(Node):
    def __init__(self):
        super().__init__('kitchen_node')
        self.srv = self.create_service(OrderService, 'process_order', self.process_order_callback)
        self.init_database()

    def init_database(self):
        self.conn = sqlite3.connect('restaurant.db')
        self.cursor = self.conn.cursor()
        
        # Create tables if they do not exist
        self.cursor.execute('''CREATE TABLE IF NOT EXISTS order_table (
            order_id INTEGER PRIMARY KEY,
            table_number INTEGER
        )''')

        self.cursor.execute('''CREATE TABLE IF NOT EXISTS order_detail (
            detail_id INTEGER PRIMARY KEY,
            order_id INTEGER,
            item_id INTEGER,
            item_name TEXT,
            quantity INTEGER,
            price REAL,
            FOREIGN KEY(order_id) REFERENCES order_table(order_id)
        )''')

        self.cursor.execute('''CREATE TABLE IF NOT EXISTS item (
            item_id INTEGER PRIMARY KEY,
            item_name TEXT,
            price REAL
        )''')

        self.conn.commit()

    def process_order_callback(self, request, response):
        self.get_logger().info(f"Processing order: {request.order_id} from table {request.table_number}")

        # Insert order into order_table
        self.cursor.execute('INSERT INTO order_table (order_id, table_number) VALUES (?, ?)',
                            (request.order_id, request.table_number))

        # Initialize detail_id counter
        detail_id = 1  # Start with 1 or other logic for auto-increment

        for order_detail in request.order_details:
            # Insert the details into the database
            self.cursor.execute('INSERT INTO order_detail (detail_id, order_id, item_id, item_name, quantity, price) VALUES (?, ?, ?, ?, ?, ?)',
                                (detail_id, request.order_id, order_detail.item_id, order_detail.item_name, order_detail.quantity, order_detail.price))
            detail_id += 1  # Increment for the next detail

        self.conn.commit()

        response.order_result = True
        return response

    def close_database(self):
        self.conn.close()

class KitchenApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Kitchen Orders')
        self.setGeometry(100, 100, 600, 400)

        self.table_widget = QTableWidget()
        layout = QVBoxLayout()
        layout.addWidget(self.table_widget)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        self.init_database()
        self.refresh_table()

    def init_database(self):
        self.conn = sqlite3.connect('restaurant.db')
        self.cursor = self.conn.cursor()

    def refresh_table(self):
        self.cursor.execute('''SELECT o.order_id, o.table_number, d.item_name, d.quantity, d.price
                                FROM order_table o
                                JOIN order_detail d ON o.order_id = d.order_id''')
        rows = self.cursor.fetchall()

        self.table_widget.setRowCount(len(rows))
        self.table_widget.setColumnCount(5)
        self.table_widget.setHorizontalHeaderLabels(['Order ID', 'Table Number', 'Item Name', 'Quantity', 'Price'])

        for row_idx, row_data in enumerate(rows):
            for col_idx, col_data in enumerate(row_data):
                self.table_widget.setItem(row_idx, col_idx, QTableWidgetItem(str(col_data)))

    def close_database(self):
        self.conn.close()

    def closeEvent(self, event):
        self.close_database()
        event.accept()

def main():
    rclpy.init()
    kitchen_node = KitchenNode()

    app = QApplication(sys.argv)
    kitchen_app = KitchenApp()
    kitchen_app.show()

    try:
        rclpy.spin(kitchen_node)  # Add this line to keep the service alive and listen for requests
    except KeyboardInterrupt:
        kitchen_node.close_database()
    finally:
        rclpy.shutdown()

    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
