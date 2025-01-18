//
// Created by bobo on 16.01.25.
//
// TODO: Compute the robot's linear and angular velocities
for (int i=0; i < num_points; ++i) {
    // same as before ***
    double t = i*dt;
    float x = a*sin(omega * t);
    float y = b*sin(2*omega*t);

    float dx_dt = a*omega*cos(omega*t);
    float dy_dt = b*2*omega*cos(2*omega*t);

    float ddx_dtt = -a*omega*omega*sin(omega*t);
    float ddy_dtt = -b*4*omega*omega*sin(2*omega*t);

    // ***
    // We can get the magnitude of the velocity vector by squaring the first derivative of x and y.
    // that represent our linear velocity which dosnt have direction
    float linear_vel= sqrt(dx_dt * dx_dt +  dy_dt * dy_dt);

    // Angular velocity calculated using formula (33) [AngVel]
    float angular_vel1 = (ddy_dtt*dx_dt - dy_dt*ddx_dtt);
    float angular_vel2 = (dx_dt*dx_dt +  dy_dt*dy_dt);
    float angular_velocity = angular_vel1/angular_vel2;


    geometry_msgs::msg::Twist twist_msgs;
    // we only go into we direction along x axis
    twist_msgs.linear.x = linear_vel;
    twist_msgs.linear.y = 0;
    twist_msgs.linear.z = 0.0;

    // as we move around 2d plane we need only angular around z-axis
    twist_msgs.angular.x = 0.0;
    twist_msgs.angular.y = 0.0;
    twist_msgs.angular.z = angular_velocity;

    cmd_vel_msgs_.push_back(twist_msgs);
}