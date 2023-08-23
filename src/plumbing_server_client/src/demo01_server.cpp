#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

bool doNums(plumbing_server_client::Addints::Request &request,
            plumbing_server_client::Addints::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的请求数据：%d, %d",num1, num2);
    int sum = num1+num2;
    response.sum = sum;
    ROS_INFO("求和结果：%d",sum);
    
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"baJie");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addints",doNums);
    ros::spin();
    return 0;
}
