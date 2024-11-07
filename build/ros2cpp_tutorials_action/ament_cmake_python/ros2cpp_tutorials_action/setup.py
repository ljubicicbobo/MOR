from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2cpp_tutorials_action',
    version='1.0.0',
    packages=find_packages(
        include=('ros2cpp_tutorials_action', 'ros2cpp_tutorials_action.*')),
)
