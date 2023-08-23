#! /usr/bin/env python

import rospy
from plumbing_pub_sub.msg import Person


if __name__ == "__main__":
    rospy.init_node("banZhuRen")
    pub = rospy.Publisher("liaotian",Person,queue_size=10)
    person = Person()
    person.name = "aotuman"
    person.age = 8
    person.height = 1.85
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(person)
        rospy.loginfo("发布的消息：%s,%d,%.2f",person.name,person.age,person.height)
        rate.sleep()