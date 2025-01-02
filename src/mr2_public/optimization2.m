% first lets read a file and convert ticks to wheel angular velocities
format long; 

odom_data = readmatrix('odom.dat');
pose_data = readmatrix('pose.dat');

left_encoder = odom_data(:, 1);
right_encoder = odom_data(:, 2);
time = odom_data(:, 3);

x_disp = pose_data(:, 1);
y_disp = pose_data(:, 2);
yaw = pose_data(:, 3);
%pose_time = pose_data(:, 4);

ticks_per_rev = 2573;
wheel_rad_R = 0.03569598463;
wheel_rad_L = 0.03594734249;

delta_time = diff(time);
delta_left_ticks = diff(left_encoder);
delta_right_ticks = diff(right_encoder);


delta_theta_left = (delta_left_ticks/ ticks_per_rev) * 2 * pi;
delta_theta_right = (delta_right_ticks / ticks_per_rev) * 2 * pi;

omega_L = delta_theta_left ./ delta_time;
omega_R = delta_theta_right ./ delta_time;


% Calculate L
L_k = zeros(2, length(delta_time));

for k = 2:length(delta_time)
    integral_L = trapz(time(k-1:k), omega_L(k-1:k));
    integral_R = trapz(time(k-1:k), omega_R(k-1:k));
    L_k(:, k) = [integral_L; integral_R];
end

% Calculate J21 J22

delta_pose_time = diff(time);
s_theta = yaw;

sigma_theta = 0.01 * ones(size(s_theta)); % const value

weighted_sum_Lk_Lk = zeros(2, 2);
weighted_sum_Lk_s_theta = zeros(2, 1);

for k=1:length(delta_time)
    if (k > length(s_theta))
        break;
    end

    L_k_curr = L_k(:, k);
    weight = 1 / (sigma_theta(k)^2);
    weighted_sum_Lk_Lk = weighted_sum_Lk_Lk + weight*(L_k_curr*L_k_curr');
    weighted_sum_Lk_s_theta = weighted_sum_Lk_s_theta + weight*(L_k_curr' * s_theta(k));
end

J_hat = weighted_sum_Lk_Lk \ weighted_sum_Lk_s_theta;

fprintf("J values calculated \n");
fprintf('J21: %.3f\n', J_hat(1));
fprintf('J22: %.3f\n', J_hat(2));
% We get J21 = 0.473, and J22 = 0.268
% Which seems incorecct, not sure what exactly is causing that problem


