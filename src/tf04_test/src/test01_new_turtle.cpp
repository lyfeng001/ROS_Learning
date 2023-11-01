#include "ros/ros.h"
#include "turtlesim/Spawn.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"fabu");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    // ros::service::waitForService("/spawn");
    client.waitForExistence();
    bool flag = client.call(spawn);
    if (flag)
    {
        ROS_INFO("success,name:%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("failed");
    }
    return 0;
}






