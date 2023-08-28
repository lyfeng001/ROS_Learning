#include "ros/ros.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"time");
    ros::NodeHandle nh;

    ros::Time right_now = ros::Time::now();
    ROS_INFO("当前时刻：%.2f",right_now.toSec());
    ROS_INFO("当前时刻：%.2d",right_now.sec);
    return 0;
}



