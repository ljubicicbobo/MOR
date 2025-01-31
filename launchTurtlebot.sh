#!/bin/bash

# Check if gnome-terminal is installed
if ! command -v gnome-terminal &> /dev/null; then
    echo "gnome-terminal is not installed. Please install it or use a compatible terminal."
    exit 1
fi

# Open the first command in a new tab
gnome-terminal --tab --title="Turtlebot Launch" -- bash -c "
echo 'Launching turtlebot_launch.xml with RViz...';
ros2 launch tug_turtlebot4 nav_launch.xml"


# Open the third command in a new tab
gnome-terminal --tab --title="Teleop Twist Keyboard" -- bash -c "
echo 'Running teleop_twist_keyboard...';
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r __ns:=/tug_turtlebot4"
