#! usr/bin/env python
import rospy
from std_msgs.msg import String

def doMsg(msg):
    rospy.loginfo("我订阅的数据：%s",msg.data)



if __name__ == "__main__":
    rospy.init_node("mei")
    sub = rospy.Subscriber("che",String,doMsg,queue_size=10)
    rospy.spin()