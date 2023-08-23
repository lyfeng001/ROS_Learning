// created by cherryblossomnight on 2022/10/25
// it write to 18 joint snake robot 
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"
#include <snake_test/Serpentine.h>
#include <vector>
#include <string>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>

#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>
#include <gazebo_msgs/GetModelState.h>
#include <gazebo_msgs/LinkStates.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/SVD>

#define updateRate 1000
#define pi 3.1415926
#define precision 1000
#define delta_t 0.001
// A bool variable expresses whether gait coefficients have changed and the 
// movement of the snake need to be transformed
bool transform = false;
snake_test::Serpentine pre, cur;

void SerTran(const snake_test::Serpentine::ConstPtr& in) 
{
    // Exchage Serpentine gait coefficients
    // Assign current coefficients to previous coefficients
    // Assign command coefficients to current coefficients
    //
    // Snake_urdf::Serpentine:
    // float alpha (0, 0.38) -> cornor control
    // float omega (0, 1] -> frequency(velocity) control
    // float gamma [-0.15, 0.15] -> swerve control
    pre.alphaH = cur.alphaH;
    pre.alphaW = cur.alphaW;
    pre.gamma = cur.gamma;
    cur.alphaH = in->alphaH;
    cur.alphaW = in->alphaW;
    cur.gamma = in->gamma;
    
    transform = false;
}

void callBack(const std_msgs::Float64::ConstPtr& in, double *out)
{
    *(out) = in->data;

}

void stateCallBack(const gazebo_msgs::LinkStatesConstPtr& state_, gazebo_msgs::LinkStates *state)
{
    *state = *state_;

}

int main(int argc, char **argv){
    ros::init(argc, argv, "snake_control_gazebo");
    setlocale(LC_ALL,"");
    ros::NodeHandle n;
    tf::TransformListener listener(ros::Duration(3));
    std::vector<ros::Publisher> joint_pos_pub;
    double phi = pi / 4;
    std::vector<nav_msgs::Odometry> poses;
    gazebo_msgs::LinkStates link_states;

    for (int i = 0; i < 9; i++)
    {
        nav_msgs::Odometry new_pose;
        poses.push_back(new_pose);
    }
    ros::Subscriber sub = n.subscribe<snake_test::Serpentine>("/snake/sermessage", 10, SerTran);
    ros::Subscriber phi_sub = n.subscribe<std_msgs::Float64>("/snake/phi", 10, boost::bind(&callBack, _1, &phi));
    ros::Subscriber state_sub = n.subscribe<gazebo_msgs::LinkStates>("/gazebo/link_states", 10, boost::bind(&stateCallBack, _1, &link_states));


    //Initial previous and current coefficients
    pre.alphaW = 0.45;
    pre.alphaH = 0.28;
    pre.gamma = 0.0;
    cur.alphaW = 0.45;
    cur.alphaH = 0.28;
    cur.gamma = 0.0;
    double omega = 0.5;
    ros::Publisher x = n.advertise<std_msgs::Float64>("/snake/location/x", 1000);
    ros::Publisher y = n.advertise<std_msgs::Float64>("/snake/location/y", 1000);
    ros::Publisher z = n.advertise<std_msgs::Float64>("/snake/location/z", 1000);
    ros::ServiceClient client =  n.serviceClient<gazebo_msgs::GetModelState>("/gazebo/get_model_state");
    ros::service::waitForService("/gazebo/get_model_state");

    geometry_msgs::Pose pose;

    Eigen::Matrix<double, 9, 3> matrix_93;
   
    for (int i = 1; i < 17; i++)
        joint_pos_pub.push_back(n.advertise<std_msgs::Float64>("/snake/joint" + std::to_string(i) + "_position_controller/command", 1000));

    ros::Rate loop_rate(updateRate);
    

    double theta = 0;
    
  
    ROS_INFO("haha");
    std::vector<double> pre_JointMessages;
    std::vector<double> cur_JointMessages;
    for (int number = 1; number < 17; number++)
    {
        if (number % 2 != 0)
        {

            pre_JointMessages.push_back(0.0);
            cur_JointMessages.push_back(0.0);
        }
        else
        {
            //pre_JointMessages.push_back(number * pi / 16);
            //cur_JointMessages.push_back(number * pi / 16);
            pre_JointMessages.push_back(0.0);
            cur_JointMessages.push_back(0.0);
        
        }


    }
    Eigen::Vector3d PRE_X_;
    PRE_X_(0) = 0.0;
    PRE_X_(1) = 0.0;
    PRE_X_(2) = 0.0;
    while(ros::ok())
    {
        theta += 2 * pi / precision;
        double sum_x ,sum_y, sum_z;
        sum_x = sum_y = sum_z = 0.0;
        
        if (link_states.pose.size() > 0)
        {
            for (int i = 0; i < 9; i++)
            {
                sum_x += link_states.pose[2 * i + 1].position.x;
                sum_y += link_states.pose[2 * i + 1].position.y;
                sum_z += link_states.pose[2 * i + 1].position.z;
            }

            pose.position.x = sum_x / 9;
            pose.position.y = sum_y / 9;
            pose.position.z = sum_z / 9;
            for (int i = 0; i < 9; i++)
            {
                matrix_93(i, 0) = link_states.pose[2 * i + 1].position.x - pose.position.x;
                matrix_93(i, 1) = link_states.pose[2 * i + 1].position.y - pose.position.y;
                matrix_93(i, 2) = link_states.pose[2 * i + 1].position.z - pose.position.z;
            }

            Eigen::JacobiSVD<Eigen::MatrixXd> svd(matrix_93, Eigen::ComputeFullV | Eigen::ComputeFullU);  
            Eigen::Matrix3d V = svd.matrixV(); 
            Eigen::Matrix3d V_; 

            Eigen::Vector3d X_;
            Eigen::Vector3d Y_;
            Eigen::Vector3d Z_;
            ROS_WARN_STREAM(link_states);

        //     //double coeff = sqrt((link_states.pose[1].position.x - link_states.pose[17].position.x)*(link_states.pose[1].position.x - link_states.pose[17].position.x) 
        //     // + (link_states.pose[1].position.y - link_states.pose[17].position.y)*(link_states.pose[1].position.y - link_states.pose[17].position.y));
            
        //    // X_(0) = (link_states.pose[1].position.x - link_states.pose[17].position.x) / coeff;
        //    // X_(1) = (link_states.pose[1].position.y - link_states.pose[17].position.y) / coeff;
        //    // X_(2) = 0.0;
        //   //  Z_(0) = 0.0;
        //    // Z_(1) = 0.0;
        //     //Z_(2) = 1.0;
            double x_coeff = sqrt((V(0,0) * V(0,0)) + ((V(0,1) * V(0,1))));

            X_(0) = -V(0,0) / x_coeff;
            X_(1) = -V(0,1) / x_coeff;
            X_(2) = 0.0;
            Z_(0) = 0.0;
            Z_(1) = 0.0;
            Z_(2) = 1.0;

            //     // if (X_.dot(PRE_X_) < 0)
            //     // {
            //     //     X_ = -X_;
            //     //     Y_ = -Y_;
            //     // }
            Y_ = Z_.cross(X_);
            V_(0,0) = X_(0);
            V_(0,1) = X_(1);
            V_(0,2) = X_(2);
            V_(1,0) = Y_(0);
            V_(1,1) = Y_(1);
            V_(1,2) = Y_(2);
            V_(2,0) = Z_(0);
            V_(2,1) = Z_(1);
            V_(2,2) = Z_(2);
        //     // PRE_X_(0) = X_(0);
        //     // PRE_X_(1) = X_(1);
        //     // PRE_X_(2) = X_(2);



            Eigen::Quaterniond q(V_);
            //q.normalize();
            pose.orientation.w = q.w();
            pose.orientation.x = q.x();
            pose.orientation.y = q.y();
            pose.orientation.z = q.z();     
            // ROS_WARN_STREAM("\n"<<V);
            // ROS_WARN_STREAM("\nw"<<"\n"<<q.w());
            // ROS_WARN_STREAM("\nx"<<"\n"<<q.x());
            // ROS_WARN_STREAM("\ny"<<"\n"<<q.y());
            // ROS_WARN_STREAM("\nz"<<"\n"<<q.z());
            // ROS_WARN_STREAM("\n"<<"\n"<< pose.orientation);


            static tf2_ros::TransformBroadcaster broadcaster1;
            static tf2_ros::TransformBroadcaster broadcaster2;

            geometry_msgs::TransformStamped tf_head;

            tf_head.header.frame_id = "world";
            tf_head.header.stamp = ros::Time::now();

             //  |----坐标系 ID
            tf_head.child_frame_id = "base_footprint";

            tf_head.transform.translation.x = link_states.pose[1].position.x;
            tf_head.transform.translation.y = link_states.pose[1].position.y;
            tf_head.transform.translation.z = link_states.pose[1].position.z;
        //     //  |--------- 四元数设
 
            tf_head.transform.rotation.x = link_states.pose[1].orientation.x;
            tf_head.transform.rotation.y = link_states.pose[1].orientation.y;
            tf_head.transform.rotation.z = link_states.pose[1].orientation.z;
            tf_head.transform.rotation.w = link_states.pose[1].orientation.w;

            geometry_msgs::TransformStamped tf_body;

            tf_body.header.frame_id = "world";
            tf_body.header.stamp = ros::Time::now();

            //  |----坐标系 ID
            tf_body.child_frame_id = "body";

            tf_body.transform.translation.x = pose.position.x;
            tf_body.transform.translation.y = pose.position.y;
            tf_body.transform.translation.z = pose.position.z;
            //  |--------- 四元数设

            tf_body.transform.rotation.x = pose.orientation.x;
            tf_body.transform.rotation.y = pose.orientation.y;
            tf_body.transform.rotation.z = pose.orientation.z;
            tf_body.transform.rotation.w = pose.orientation.w;

            broadcaster1.sendTransform(tf_head);
            broadcaster2.sendTransform(tf_body);

        }


        //  5-3.广播器发布数据
       


        for (int number = 1; number < 17; number++)
        {
            std_msgs::Float64 JointMessage;
            
                     
            if (number % 2 == 1)
            {
                JointMessage.data = pre.alphaH * cos(4 * pi * omega * theta + 2 * number * pi / 10);
                //JointMessage.data = 0.0; 
            }
            else
            {
                JointMessage.data = pre.alphaW * cos(2 * pi * omega * theta + number * pi / 10) + pre.gamma;       
            }
            joint_pos_pub[number - 1].publish(JointMessage);
        }      

        // ROS_WARN_STREAM(cur_JointMessages[3] - cur_JointMessages[1]);
        // ROS_WARN_STREAM("a");
        // ROS_WARN_STREAM(0.0005*sin(cur_JointMessages[3] - cur_JointMessages[1] - pi / 8));
        // ROS_WARN_STREAM("b");
        

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
            ROS_WARN_STREAM("c");
            continue;
        }
        
        
    
   
    
    ros::spinOnce();//check for incoming messages, wait for callback
    loop_rate.sleep();

  //to loop over and over again
    /*if (cur.omega * theta >= 2 * pi){
        theta -= 2 * pi / cur.omega;
        transform = true;
        
        bool flag = client.call(modelState);
        if (flag)
        
        else
        {
            continue;
        }
      }*/
  }
  return 0;
}
