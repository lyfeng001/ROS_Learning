#!/usr/bin/env python3

import rospy
from plumbing_pub_sub.msg import Person

def doPerson(person):
    rospy.loginfo("订阅到的消息：%s,%d,%.2f",person.name,person.age,person.height)

if __name__ == "__main__":
    rospy.init_node("jiaZhang")
    sub = rospy.Subscriber("liaotian",Person,doPerson,queue_size=10)
    rospy.spin()
    