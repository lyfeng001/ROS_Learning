#include "ros/ros.h"

#include "plumbing_src/hello.h"


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"src");
    hello_ns::MyHello myhello;
    myhello.run();
    
    return 0;
}



