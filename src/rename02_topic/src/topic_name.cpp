#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello");
    // ros::NodeHandle nh;
/*
The "global" has the higher priority


// The topic:
    // namespace is /xxx    global: the same height as the ns
    //                      relative: under the ns
    //                      private: under the ns and the node, i.e., ns/node/topic 
// The ndoe:
    // under the ns initially, while having the name in the "ros::init"

*/


    //global  话题名称需要以/开头，这种情况下和节点（命名空间爱你及名称）没有关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);

    //relative  start not with "/"
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    //private  need to create specific NodeHandle
    ros::NodeHandle nh("~");
    ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    while(ros::ok())
    {

    }
    return 0;
}



