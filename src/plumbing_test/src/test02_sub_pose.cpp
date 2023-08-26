#include "ros/ros.h"
#include "turtlesim/Pose.h"


void doMsgs(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("乌龟的位姿信息：坐标(%.2f,%.2f),朝向:(%.2f),线速度(%.2f)，角速度(%.2f)",pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);

}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"jieshou");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("turtle1/pose",10,doMsgs);
    ros::spin();
    return 0;
}



