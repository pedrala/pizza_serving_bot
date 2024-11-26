from setuptools import find_packages, setup

package_name = 'pizza_serving_bot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    package_data={
        'pizza_serving_bot': ['amr_controller/img/*'],
    },
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='viator',
    maintainer_email='pedralation@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'amr = pizza_serving_bot.amr_controller.amr_node:main',
            'display = pizza_serving_bot.amr_controller.order_info_display:main',
            'kitchen = pizza_serving_bot.kitchen_monitor.kitchen_node:main',
            'order = pizza_serving_bot.kitchen_monitor.order_info_node:main',
            'table = pizza_serving_bot.table_order.table_node:main',
          
        ],
    },
)
