#!/bin/bash

# Check if gnome-terminal is installed
if ! command -v gnome-terminal &> /dev/null; then
    echo "gnome-terminal is not installed. Please install it or use a compatible terminal."
    exit 1
fi

# Open the first command in a new tab
gnome-terminal --tab --title="Turtlebot Launch" -- bash -c "
echo 'Launching turtlebot_launch.xml with RViz...';
ros2 launch tug_turtlebot4 turtlebot_launch.xml rviz:=true;
exec bash"

# Open the second command in a new tab
gnome-terminal --tab --title="Simple Turtle Launch" -- bash -c "
echo 'Launching simple_turtle_launch.xml...';
ros2 launch tug_turtlebot4 simple_turtle_launch.xml;
exec bash"

# Open the third command in a new tab
gnome-terminal --tab --title="Teleop Twist Keyboard" -- bash -c "
echo 'Running teleop_twist_keyboard...';
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r __ns:=/tug_turtlebot4;
	exec bash"

