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
    //1.2
    double radius2;
    bool result = nh.getParam("radius",radius2);
    if (result)
    {
        ROS_INFO("获取的半径是：%.2f",radius2);
    }
    else
    {
        ROS_INFO("被查询的的变量不存在"); 
    }
    //1.3
    bool result2 = nh.getParamCached("radius",radius2);
    if (result2)
    {
        ROS_INFO("获取的半径是：%.2f",radius2);
    }
    else
    {
        ROS_INFO("被查询的的变量不存在"); 
    }
    //method 2 


    return 0;
}



