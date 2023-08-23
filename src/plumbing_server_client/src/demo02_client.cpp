#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    if(argc != 3)
    {
        ROS_INFO("参数个数不对");
        return 1;
    }

    ros::init(argc,argv, "guKe");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::Addints>("addints");
    plumbing_server_client::Addints ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    client.waitForExistence();

    bool flag = client.call(ai);

    if (flag)
    {
        ROS_INFO("响应成功，结果是：%d", ai.response.sum);
    }
    else
    {
        ROS_INFO("响应失败");
    }
    // ros::spin();
    return 0;
}

