#include "ros/ros.h"


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"param_del_c");
    ros::NodeHandle nh;
    //method 1
    bool flag1 = nh.deleteParam("radius");
    if (flag1)
    {
        ROS_INFO("success");
    }
    else
    {
        ROS_INFO("failed");
    }

    //method 2
    bool flag2 = ros::param::del("radius_param");
    if (flag2)
    {
        ROS_INFO("radius_param success");
    }
    else
    {
        ROS_INFO("radius_param failed");
    }


    return 0;
}


