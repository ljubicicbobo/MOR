from setuptools import find_packages
from setuptools import setup

setup(
    name='tug_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('tug_msgs', 'tug_msgs.*')),
)
