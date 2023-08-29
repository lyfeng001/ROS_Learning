#include "ros/ros.h"
#include "plumbing_head/hello.h"

namespace hello_ns {

void MyHello::run(){
    ROS_INFO("run!!!!");
}

}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hhh");
    hello_ns::MyHello myhello;
    myhello.run();
    return 0;
}

