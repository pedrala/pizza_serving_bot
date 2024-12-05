from setuptools import find_packages, setup
import os

package_name = 'pizza_serving_bot'

# 파일 경로 수정: 실제 경로를 정확히 지정
launch_file_path = os.path.join('pizza_serving_bot', 'launch', 'pizza_serving_bot.launch.py')


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
         # launch 폴더의 파일을 명시적으로 설치하도록 설정  ---
        ('share/' + package_name + '/launch', [launch_file_path]),
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
            'kitchen = pizza_serving_bot.kitchen_monitor.kitchen_node:main',
            'kiosk = pizza_serving_bot.table_order.kiosk_node:main',
            'amr = pizza_serving_bot.amr_controller.amr_node:main',
            #'saver = pizza_serving_bot.amr_controller.goal_saver:main',        
        ],
    },
)
