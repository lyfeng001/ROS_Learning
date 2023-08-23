// created by zion on 2018/8/1
// it write to 7 joint snake and make snake end goes a ellipse
#include "ros/ros.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/JointState.h"

#include <nav_msgs/Path.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>

#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>

#define updateRate 200
#define pi 3.1415926
#define precision 1000


int main(int argc, char **argv){
  ros::init(argc, argv, "snake_control_rviz");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<sensor_msgs::JointState>("joint_states", 1000);

  ros::Rate loop_rate(updateRate);

  int count = 0;
  double theta = 0;
  
  tf::TransformListener listener(ros::Duration(3));

  while(ros::ok()){
    count++;
    theta += pi*2/precision;
// pack position
    ros::Time current_time = ros::Time::now();
    std_msgs::Header head;
    sensor_msgs::JointState circlePoint;
    head.stamp = current_time;
    circlePoint.header = head;
    //calc point
    circlePoint.name.push_back("joint1");
    circlePoint.name.push_back("joint2");
    circlePoint.name.push_back("joint3");
    circlePoint.name.push_back("joint4");
    circlePoint.name.push_back("joint5");
    circlePoint.name.push_back("joint6");
    circlePoint.name.push_back("joint7");
    circlePoint.name.push_back("joint8");
    circlePoint.name.push_back("joint9");
    circlePoint.name.push_back("joint10");
    circlePoint.name.push_back("joint11");
    circlePoint.name.push_back("joint12");
    circlePoint.name.push_back("joint13");
    circlePoint.name.push_back("joint14");
    circlePoint.name.push_back("joint15");
    circlePoint.name.push_back("joint16");
    circlePoint.name.push_back("joint17");
    circlePoint.name.push_back("joint18");

    circlePoint.position.push_back(sin(theta));
    circlePoint.position.push_back(1.40);
    circlePoint.position.push_back(cos(theta));
    circlePoint.position.push_back(2.07);
    circlePoint.position.push_back(sin(theta));
    circlePoint.position.push_back(1.00);
    circlePoint.position.push_back(cos(theta));
    circlePoint.position.push_back(0);
    circlePoint.position.push_back(sin(theta));
    circlePoint.position.push_back(1.05);
    circlePoint.position.push_back(cos(theta));
    circlePoint.position.push_back(1.89);
    circlePoint.position.push_back(sin(theta));
    circlePoint.position.push_back(0.42);
    circlePoint.position.push_back(cos(theta));
    circlePoint.position.push_back(0.87);
    circlePoint.position.push_back(sin(theta));
    circlePoint.position.push_back(1.36);

    
    pub.publish(circlePoint);
    
    ros::spinOnce();//check for incoming messages, wait for callback
    
    loop_rate.sleep();

  //to loop over and over again
    if(!count%precision){
      theta = 0;
      }
  }
  return 0;
}
