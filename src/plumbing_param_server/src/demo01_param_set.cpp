#include "ros/ros.h"



int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_param_c");
    ros::NodeHandle nh;
    // add parameters
    //method 1
    nh.setParam("type","xiaohuangche");
    nh.setParam("radius",0.15);    
    //method 2
    ros::param::set("type_param","xiaobaiche");
    ros::param::set("radius_param",0.15);

    // change parameters
    //method 1
    nh.setParam("radius",0.2);
    //method 2
    ros::param::set("radius_param",0.3);

    return 0;
}



