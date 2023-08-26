#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "myctrl");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    ros::Rate rate(10);
    geometry_msgs::Twist twist;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 2.0;
    twist.linear.x = 20;
    twist.linear.y = 0;
    twist.linear.z = 0;
    while (ros::ok)
    {
        pub.publish(twist);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}


