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

#define updateRate 1000
#define pi 3.1415926
#define precision 1000
// A bool variable expresses whether gait coefficients have changed and the 
// movement of the snake need to be transformed
bool transform = false;
snake_test::Serpentine pre, cur;

void SerTran(const snake_test::Serpentine::ConstPtr& in) {
    // Exchage Serpentine gait coefficients
    // Assign current coefficients to previous coefficients
    // Assign command coefficients to current coefficients
    //
    // Snake_urdf::Serpentine:
    // float alpha (0, 0.38) -> cornor control
    // float omega (0, 1] -> frequency(velocity) control
    // float gamma [-0.15, 0.15] -> swerve control
    // pre.alpha = cur.alpha;
    // pre.omega = cur.omega;
    // pre.gamma = cur.gamma;
    // cur.alpha = in->alpha;
    // cur.omega = in->omega;
    // cur.gamma = in->gamma;
    
    transform = false;
}

int main(int argc, char **argv){
  ros::init(argc, argv, "snake_control_gazebo");
  setlocale(LC_ALL,"");
  ros::NodeHandle n;
  std::vector<ros::Publisher> joint_pos_pub;
  ros::Subscriber sub = n.subscribe<snake_test::Serpentine>("/snake/sermessage", 10, SerTran);
  //Initial previous and current coefficients
//   pre.alpha = 0.0;
//   pre.omega = 1.0;
//   pre.gamma = 0.0;
//   cur.alpha = 0.45;
//   cur.omega = 1.0;
//   cur.gamma = 0.0;
  

  for (int i = 1; i < 35; i++)
      joint_pos_pub.push_back(n.advertise<std_msgs::Float64>("/snake/joint" + std::to_string(i) + "_position_controller/command", 1000));

  ros::Rate loop_rate(updateRate);

  double theta = 0;
  
  tf::TransformListener listener(ros::Duration(3));
  ROS_INFO("haha");
  while(ros::ok()){
    theta += 2 * pi / precision;
// pack position
    ros::Time current_time = ros::Time::now();
    //calc point
   
    
    if (transform == false){
        // If the cofficients haven't been transformed 
        // make the transformation by using exponential function
        for (int number = 1; number < 35; number++)
        {
            
            std_msgs::Float64 JointMessage;           
            if (number % 2 == 0)
                JointMessage.data = 0;
            else
                // JointMessage.data = (pre.alpha + (cur.alpha - pre.alpha) / (exp(-2 * pi) - 1) * (exp(-theta) - 1)) 
                //                      * cos((pre.omega + (cur.omega - pre.omega) / (exp(-2 * pi) - 1) * (exp(-theta) - 1)) * theta + number * pi / 9)
                //                      + (pre.gamma + (cur.gamma - pre.gamma) / (exp(-2 * pi) - 1) * (exp(-theta) - 1));
            joint_pos_pub[number - 1].publish(JointMessage);
        }      
    }
    else{
        for (int number = 1; number < 35; number++)
        {
            std_msgs::Float64 JointMessage;
            if (number % 2 == 0)
                JointMessage.data = 0.0;
            else
            {
                // JointMessage.data = cur.alpha * cos(cur.omega * theta + number * pi / 9) + cur.gamma ;
            }
            joint_pos_pub[number - 1].publish(JointMessage);
        }
    }
   
    
    ros::spinOnce();//check for incoming messages, wait for callback
    loop_rate.sleep();

  //to loop over and over again
    // if (cur.omega * theta >= 2 * pi){
    //   theta -= 2 * pi / cur.omega;
    //   transform = true;
    //   }
  }
  return 0;
}
