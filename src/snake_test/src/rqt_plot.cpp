#include <ros/ros.h>
#include <gazebo_msgs/GetModelState.h>
#include <std_msgs/Float64.h>
 

 

int main(int argc, char **argv)
{
    ros::init(argc, argv, "location");
    setlocale(LC_ALL,"");
    ros::NodeHandle nh;
    ros::Publisher x = nh.advertise<std_msgs::Float64>("/snake/location/x", 1000);
    ros::Publisher y = nh.advertise<std_msgs::Float64>("/snake/location/y", 1000);
    ros::Publisher z = nh.advertise<std_msgs::Float64>("/snake/location/z", 1000);
    ros::ServiceClient client =  nh.serviceClient<gazebo_msgs::GetModelState>("/gazebo/get_model_state");

    ros::service::waitForService("/gazebo/get_model_state");

    ros::Rate loop_rate(1000);
    while(ros::ok())
    {
        gazebo_msgs::GetModelState modelState;
        modelState.request.model_name = "snake";
        bool flag = client.call(modelState);
        if (flag)
        {
            std_msgs::Float64 x_;
            std_msgs::Float64 y_;
            std_msgs::Float64 z_; 
            x_.data = modelState.response.pose.position.x;
            y_.data = modelState.response.pose.position.y;
            z_.data = modelState.response.pose.position.z;
            x.publish(x_);
            y.publish(y_);
            z.publish(z_);
        }
        else
        {
            continue;
        }


        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
