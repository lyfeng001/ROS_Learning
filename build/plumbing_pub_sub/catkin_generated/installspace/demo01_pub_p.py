#!/usr/bin/env python3

import rospy
from std_msgs.msg import String



if __name__ == "__main__":

    rospy.init_node("erGouZi")
    pub = rospy.Publisher("che",String,queue_size=10)
    msgs = String()
    rate = rospy.Rate(1)
    count = 0
    rospy.sleep(3)
    while not rospy.is_shutdown():
        count+=1
        msgs.data = "hello"+str(count)
        pub.publish(msgs)
        rospy.loginfo("发布的数据是：%s",msgs.data)
        rate.sleep()