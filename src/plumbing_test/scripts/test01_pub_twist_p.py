#! usr/bin/env python

import rospy
from geometry_msgs.msg import Twist


if __name__ == "__main__":
    rospy.init_node("control")
    pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
    
    rate = rospy.Rate(10)
    twist = Twist()
    twist.angular.x = 0
    twist.angular.y = 0
    twist.angular.z = 2
    twist.linear.x = 0
    twist.linear.y = 5
    twist.linear.z = 0
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep()
    




