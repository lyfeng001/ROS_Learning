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
    //1.4
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    //1.5
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxx");
    ROS_INFO("radius 存在吗？%d",flag1);
    ROS_INFO("radiusxx 存在吗？%d",flag2);
    //1.6
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果%s",key.c_str());

    //method 2 
    double radius_param = ros::param::param("radius",100.5);
    ROS_INFO("radius_param = %.2f");

    return 0;
}



