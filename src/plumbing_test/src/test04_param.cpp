#include "ros/ros.h"





int main(int argc, char *argv[])
{
    ros::init(argc,argv, "sheZhi");
    ros::NodeHandle nh("turtlesim");
    // ros::param::set("/turtlesim/background_r",255);
    // ros::param::set("/turtlesim/background_g",255);
    // ros::param::set("/turtlesim/background_b",255);
    nh.setParam("background_r",0);
    nh.setParam("background_g",0);
    nh.setParam("background_b",0);

    return 0;
}



