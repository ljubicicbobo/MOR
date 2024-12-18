
pose_data = readtable('pose.dat');
odom_data = readtable('odom.dat');

x_pose = pose_data.x;
y_pose = pose_data.y;

x_odom = odom_data.x;
y_odom = odom_data.y;


figure;
plot(x_pose, y_pose, '-o', 'DisplayName', 'Pose'); 
hold on;
plot(x_odom, y_odom, '-x', 'DisplayName', 'Odometry'); 
hold off;


xlabel('X Position');
ylabel('Y Position');
title('Comparison of Robot Trajectories');
legend('Location', 'best'); 
grid on;
