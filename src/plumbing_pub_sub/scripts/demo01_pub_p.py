#! /usr/bin/env python
import sys
sys.path.append("/home/f/catkin_us/src/plumbing_pub_sub/scripts")


import rospy
from std_msgs.msg import String
import tools


if __name__ == "__main__":

    rospy.init_node("erGouZi")
    pub = rospy.Publisher("che",String,queue_size=10)

    rospy.loginfo("num=%d",tools.num)
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