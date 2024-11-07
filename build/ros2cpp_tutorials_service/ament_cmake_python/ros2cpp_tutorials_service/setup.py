from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2cpp_tutorials_service',
    version='1.0.0',
    packages=find_packages(
        include=('ros2cpp_tutorials_service', 'ros2cpp_tutorials_service.*')),
)
