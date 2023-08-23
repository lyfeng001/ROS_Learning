#include "ros/ros.h"





int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;

    //method 1
    //1.1
    double radius = nh.param("radius",0.6);
    ROS_INFO("param：radius=%.2f",radius);
    //method 2 

    return 0;
}



