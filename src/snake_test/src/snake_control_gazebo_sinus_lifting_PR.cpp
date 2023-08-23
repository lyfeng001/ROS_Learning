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

#define updateRate 1000
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
  ros::Publisher joint19_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint19_position_controller/command", 1000);
  ros::Publisher joint20_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint20_position_controller/command", 1000);
  ros::Publisher joint21_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint21_position_controller/command", 1000);
  ros::Publisher joint22_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint22_position_controller/command", 1000);
  ros::Publisher joint23_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint23_position_controller/command", 1000);
  ros::Publisher joint24_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint24_position_controller/command", 1000);
  ros::Publisher joint25_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint25_position_controller/command", 1000);
  ros::Publisher joint26_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint26_position_controller/command", 1000);
  ros::Publisher joint27_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint27_position_controller/command", 1000);
  ros::Publisher joint28_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint28_position_controller/command", 1000);
  ros::Publisher joint29_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint29_position_controller/command", 1000);
  ros::Publisher joint30_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint30_position_controller/command", 1000);
  ros::Publisher joint31_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint31_position_controller/command", 1000);
  ros::Publisher joint32_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint32_position_controller/command", 1000);
  ros::Publisher joint33_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint33_position_controller/command", 1000);
  ros::Publisher joint34_pos_pub = n.advertise<std_msgs::Float64>("/snake/joint34_position_controller/command", 1000);



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
    std_msgs::Float64 joint19;
    std_msgs::Float64 joint20;
    std_msgs::Float64 joint21;
    std_msgs::Float64 joint22;
    std_msgs::Float64 joint23;
    std_msgs::Float64 joint24;
    std_msgs::Float64 joint25;
    std_msgs::Float64 joint26;
    std_msgs::Float64 joint27;
    std_msgs::Float64 joint28;
    std_msgs::Float64 joint29;
    std_msgs::Float64 joint30;
    std_msgs::Float64 joint31;
    std_msgs::Float64 joint32;
    std_msgs::Float64 joint33;
    std_msgs::Float64 joint34;

    double amp1 = 0.60;
    double amp2 = 0.20;

    
    if (generate == false){
      joint1.data = amp1*(1 - exp(-theta))*sin(theta);
      joint2.data = 1.5708*(1 - exp(-theta));
      joint3.data = amp2*(1 - exp(-theta))*sin(2 * theta);
      joint4.data = -1.5708*(1 - exp(-theta));
      joint5.data = amp1*(1 - exp(-theta))*sin(theta + 2 * pi / 8);
      joint6.data = 1.5708*(1 - exp(-theta));
      joint7.data = amp2*(1 - exp(-theta))*sin(2 * theta + 2 * pi / 4);
      joint8.data = -1.5708*(1 - exp(-theta));
      joint9.data = amp1*(1 - exp(-theta))*sin(theta + 4 * pi / 8);
      joint10.data = 1.5708*(1 - exp(-theta));
      joint11.data = amp2*(1 - exp(-theta))*sin(2 * theta + 4 * pi / 4);
      joint12.data = -1.5708*(1 - exp(-theta));
      joint13.data = amp1*(1 - exp(-theta))*sin(theta + 6 * pi / 8);
      joint14.data = 1.5708*(1 - exp(-theta));
      joint15.data = amp2*(1 - exp(-theta))*sin(2 * theta + 6 * pi / 4);
      joint16.data = -1.5708*(1 - exp(-theta));
      joint17.data = amp1*(1 - exp(-theta))*sin(theta + 8 * pi / 8);
      joint18.data = 1.5708*(1 - exp(-theta));
      joint19.data = amp2*(1 - exp(-theta))*sin(2 * theta + 8 * pi / 4);
      joint20.data = -1.5708*(1 - exp(-theta));
      joint21.data = amp1*(1 - exp(-theta))*sin(theta + 10 * pi / 8);
      joint22.data = 1.5708*(1 - exp(-theta));
      joint23.data = amp2*(1 - exp(-theta))*sin(2 * theta + 10 * pi / 4);
      joint24.data = -1.5708*(1 - exp(-theta));
      joint25.data = amp1*(1 - exp(-theta))*sin(theta + 12 * pi / 8);
      joint26.data = 1.5708*(1 - exp(-theta));
      joint27.data = amp2*(1 - exp(-theta))*sin(2 * theta + 12 * pi / 4);
      joint28.data = -1.5708*(1 - exp(-theta));
      joint29.data = amp1*(1 - exp(-theta))*sin(theta + 14 * pi / 8);
      joint30.data = 1.5708*(1 - exp(-theta));
      joint31.data = amp2*(1 - exp(-theta))*sin(2 * theta + 14 * pi / 4);
      joint32.data = -1.5708*(1 - exp(-theta));
      joint33.data = amp1*(1 - exp(-theta))*sin(theta);
      joint34.data = 1.5708*(1 - exp(-theta));
    }
   else{
      joint1.data = amp1*sin(theta);
      joint2.data = 1.5708;
      joint3.data = amp2*sin(2 * theta);
      joint4.data = -1.5708;
      joint5.data = amp1*sin(theta + 2 * pi / 8);
      joint6.data = 1.5708;
      joint7.data = amp2*sin(2 * theta + 2 * pi / 4);
      joint8.data = -1.5708;
      joint9.data = amp1*sin(theta + 4 * pi / 8);
      joint10.data = 1.5708;
      joint11.data = amp2*sin(2 * theta + 4 * pi / 4);
      joint12.data = -1.5708;
      joint13.data = amp1*sin(theta + 6 * pi / 8);
      joint14.data = 1.5708;
      joint15.data = amp2*sin(2 * theta + 6 * pi / 4);
      joint16.data = -1.5708;
      joint17.data = amp1*sin(theta + 8 * pi / 8);
      joint18.data = 1.5708;
      joint19.data = amp2*sin(2 * theta + 8 * pi / 4);
      joint20.data = -1.5708;
      joint21.data = amp1*sin(theta + 10 * pi / 8);
      joint22.data = 1.5708;
      joint23.data = amp2*sin(2 * theta + 10 * pi / 4);
      joint24.data = -1.5708;
      joint25.data = amp1*sin(theta + 12 * pi / 8);
      joint26.data = 1.5708;
      joint27.data = amp2*sin(2 * theta + 12 * pi / 4);
      joint28.data = -1.5708;
      joint29.data = amp1*sin(theta + 14 * pi / 8);
      joint30.data = 1.5708;
      joint31.data = amp2*sin(2 * theta + 14 * pi / 4);
      joint32.data = -1.5708;
      joint33.data = amp1*sin(theta);
      joint34.data = 1.5708;
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
    joint19_pos_pub.publish(joint19);
    joint20_pos_pub.publish(joint20);
    joint21_pos_pub.publish(joint21);
    joint22_pos_pub.publish(joint22);
    joint23_pos_pub.publish(joint23);
    joint24_pos_pub.publish(joint24);
    joint25_pos_pub.publish(joint25);
    joint26_pos_pub.publish(joint26);
    joint27_pos_pub.publish(joint27);
    joint28_pos_pub.publish(joint28);
    joint29_pos_pub.publish(joint29);
    joint30_pos_pub.publish(joint30);
    joint31_pos_pub.publish(joint31);
    joint32_pos_pub.publish(joint32);
    joint33_pos_pub.publish(joint33);
    joint34_pos_pub.publish(joint34);

    
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
