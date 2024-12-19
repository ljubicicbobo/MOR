% first lets read a file and convert ticks to wheel angular velocities

odom_data = readmatrix('odom.dat');
pose_data = readmatrix('pose.dat');

left_encoder = odom_data(:, 1);
right_encoder = odom_data(:, 2);
time = odom_data(:, 3)

ticks_per_rev = 2573;
wheel_rad_R = 0.07139196927;
wheel_rad_L = 0.07189468498;

delta_time = diff(time);
delta_left_ticks = diff(left_encoder);
delta_right_ticks = diff(right_encoder);


delta_theta_left = (delta_left_ticks/ ticks_per_rev) * 2 * pi;
delta_theta_right = (delta_right_ticks / ticks_per_rev) * 2 * pi;

omega_L = delta_theta_left ./ delta_time;
omega_R = delta_theta_right ./ delta_time;

% Calculate Average Wheel Velocity
T = 50%time(end) - time(1);

avg_omega_L = (1/T)*sum((delta_theta_left));
avg_omega_R = (1/T)*sum((delta_theta_right));

% Integration of absolute angular velocities
avg_omega_L_mag_integration = trapz(time(2:end), (omega_L)) / T;
avg_omega_R_mag_integration = trapz(time(2:end), (omega_R)) / T;

% Display results
fprintf('Time (s)    Left Angular Velocity (rad/s)    Right Angular Velocity (rad/s)\n');
for i = 1:length(omega_L)
    fprintf('%.3f        %.3f                        %.3f\n', time(i+1), omega_L(i), omega_R(i)); 
end

fprintf("\nAverage Angular Vel:\n");
fprintf('Left Wheel: %.3f rad/s\n', avg_omega_L);
fprintf('Right Wheel: %.3f rad/s\n', avg_omega_R);

fprintf('Left Wheel: %.3f rad/s\n', avg_omega_L_mag_integration);
fprintf('Right Wheel: %.3f rad/s\n', avg_omega_R_mag_integration);
