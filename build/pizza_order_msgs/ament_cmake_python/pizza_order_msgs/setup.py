from setuptools import find_packages
from setuptools import setup

setup(
    name='pizza_order_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('pizza_order_msgs', 'pizza_order_msgs.*')),
)
