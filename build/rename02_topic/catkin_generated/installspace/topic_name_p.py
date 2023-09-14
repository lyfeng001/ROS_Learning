#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("hello")

    # global
    # pub = rospy.Publisher("/chatter",String,queue_size=10)

    # relative
    pub = rospy.Publisher("chatter",String,queue_size=10)
    
    # private
    pub = rospy.Publisher("~chatter",String,queue_size=10)


    while not rospy.is_shutdown():
        pass


