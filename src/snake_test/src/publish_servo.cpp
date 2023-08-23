#include <ros/ros.h>
#include <std_msgs/UInt16MultiArray.h>

#define precision 1000
#define pi 3.1415926
int main(int argc,char**argv)
{
    ros::init(argc,argv,"publish_servo");
    ros::NodeHandle n;

    ros::Publisher servo_publisher = n.advertise<std_msgs::UInt16MultiArray>("servo_pos",10);

    //servo_publisher是发布者
    ros::Rate loop_rate(1000);
    std_msgs::UInt16MultiArray servo_msg;
    int count = 0;
    double theta = 0;
    while(ros::ok())
    {
        count++;
        
        for (int i = 1; i < 17; i++)
        {
            if (i % 2 != 0)
                servo_msg.data.push_back(2048);
            else
                servo_msg.data.push_back(2048 + int(0.40 / 6.28318 * 4096 * cos(theta + i * pi / 9)));
            

        }
        servo_publisher.publish(servo_msg);

        ros::spinOnce();
        
        loop_rate.sleep(); 
        
        if (!count%precision)
        {
            theta = 0;
        }
    }
    return 0;
}
