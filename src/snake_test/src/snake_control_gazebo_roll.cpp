// created by cherryblossomnight on 2022/10/27
// it write to 18 joint snake robot 
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"
#include <nav_msgs/Path.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>

#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>

#define updateRate 2000
#define pi 3.1415926
#define precision 1000

int main(int argc, char **argv){
  ros::init(argc, argv, "snake_control_gazebo");
  setlocale(LC_ALL,"");
  ros::NodeHandle n;
  ros::Publisher joint1_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint1_position_controller/command", 1000);
  ros::Publisher joint2_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint2_position_controller/command", 1000);
  ros::Publisher joint3_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint3_position_controller/command", 1000);
  ros::Publisher joint4_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint4_position_controller/command", 1000);
  ros::Publisher joint5_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint5_position_controller/command", 1000);
  ros::Publisher joint6_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint6_position_controller/command", 1000);
  ros::Publisher joint7_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint7_position_controller/command", 1000);
  ros::Publisher joint8_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint8_position_controller/command", 1000);
  ros::Publisher joint9_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint9_position_controller/command", 1000);
  ros::Publisher joint10_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint10_position_controller/command", 1000);
  ros::Publisher joint11_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint11_position_controller/command", 1000);
  ros::Publisher joint12_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint12_position_controller/command", 1000);
  ros::Publisher joint13_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint13_position_controller/command", 1000);
  ros::Publisher joint14_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint14_position_controller/command", 1000);
  ros::Publisher joint15_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint15_position_controller/command", 1000);
  ros::Publisher joint16_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint16_position_controller/command", 1000);
  ros::Publisher joint17_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint17_position_controller/command", 1000);
  ros::Publisher joint18_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint18_position_controller/command", 1000);



  ros::Rate loop_rate(updateRate);

  int count = 0;
  double theta = 0;
  bool generate = false;
  
  tf::TransformListener listener(ros::Duration(3));
  ROS_INFO("haha");
  while(ros::ok()){
    count++;
    
    theta += 2*pi/precision;
// pack position
    ros::Time current_time = ros::Time::now();
    //calc point

    std_msgs::Float64 joint1;
    std_msgs::Float64 joint2;
    std_msgs::Float64 joint3;
    std_msgs::Float64 joint4;
    std_msgs::Float64 joint5;
    std_msgs::Float64 joint6;
    std_msgs::Float64 joint7;
    std_msgs::Float64 joint8;
    std_msgs::Float64 joint9;
    std_msgs::Float64 joint10;
    std_msgs::Float64 joint11;
    std_msgs::Float64 joint12;
    std_msgs::Float64 joint13;
    std_msgs::Float64 joint14;
    std_msgs::Float64 joint15;
    std_msgs::Float64 joint16;
    std_msgs::Float64 joint17;
    std_msgs::Float64 joint18;

    double amp1 = 0.40;
    double amp2 = 0.40;

    
    if (generate == false){
      joint1.data = amp1*(1 - exp(-theta))*sin(theta);
      joint2.data = 1.5708*(1 - exp(-theta));
      joint3.data = amp2*(1 - exp(-theta))*cos(theta);
      joint4.data = -1.5708*(1 - exp(-theta));
      joint5.data = amp1*(1 - exp(-theta))*sin(theta);
      joint6.data = 1.5708*(1 - exp(-theta));
      joint7.data = amp2*(1 - exp(-theta))*cos(theta);
      joint8.data = -1.5708*(1 - exp(-theta));
      joint9.data = amp1*(1 - exp(-theta))*sin(theta);
      joint10.data = 1.5708*(1 - exp(-theta));
      joint11.data = amp2*(1 - exp(-theta))*cos(theta);
      joint12.data = -1.5708*(1 - exp(-theta));
      joint13.data = amp1*(1 - exp(-theta))*sin(theta);
      joint14.data = 1.5708*(1 - exp(-theta));
      joint15.data = amp2*(1 - exp(-theta))*cos(theta);
      joint16.data = -1.5708*(1 - exp(-theta));
      joint17.data = amp1*(1 - exp(-theta))*sin(theta);
      joint18.data = 1.5708*(1 - exp(-theta));
    }
   else{
      joint1.data = amp1*sin(theta);
      joint2.data = 1.5708;
      joint3.data = amp2*cos(theta);
      joint4.data = -1.5708;
      joint5.data = amp1*sin(theta);
      joint6.data = 1.5708;
      joint7.data = amp2*cos(theta);
      joint8.data = - 1.5708;
      joint9.data = amp1*sin(theta);
      joint10.data = 1.5708;
      joint11.data = amp2*cos(theta);
      joint12.data = -1.5708;
      joint13.data = amp1*sin(theta);
      joint14.data = 1.5708;
      joint15.data = amp2*cos(theta);
      joint16.data = -1.5708;
      joint17.data = amp1*sin(theta);
      joint18.data = 1.5708;
    }
   
   
    joint1_pos_pub.publish(joint1);
    joint2_pos_pub.publish(joint2); 
    joint3_pos_pub.publish(joint3);
    joint4_pos_pub.publish(joint4);
    joint5_pos_pub.publish(joint5);
    joint6_pos_pub.publish(joint6);
    joint7_pos_pub.publish(joint7);
    joint8_pos_pub.publish(joint8);
    joint9_pos_pub.publish(joint9);
    joint10_pos_pub.publish(joint10);
    joint11_pos_pub.publish(joint11);
    joint12_pos_pub.publish(joint12);
    joint13_pos_pub.publish(joint13);
    joint14_pos_pub.publish(joint14);
    joint15_pos_pub.publish(joint15);
    joint16_pos_pub.publish(joint16);
    joint17_pos_pub.publish(joint17);
    joint18_pos_pub.publish(joint18);

    
    ros::spinOnce();//check for incoming messages, wait for callback
    loop_rate.sleep();

  //to loop over and over again
    if(count==precision){
      theta = 0;
      count = 0;
      generate = true;
      }
  }
  return 0;
}
