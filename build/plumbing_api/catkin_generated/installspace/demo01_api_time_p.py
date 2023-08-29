#! usr/bin/env python

import rospy

def doMsg(event):
    rospy.loginfo("----------------")
    rospy.loginfo("time:%.2f",event.current_real.to_sec())


if __name__ == "__main__":
    rospy.init_node("time")
    # get time
    right_now = rospy.Time.now()
    rospy.loginfo("当前时刻：%.2f",right_now.to_sec())
    rospy.loginfo("当前时刻：%d",right_now.secs)


    time1 = rospy.Time(100)
    rospy.loginfo(time1.to_sec())

    #---------------停顿---------------
    du1 = rospy.Duration(1)
    du2 = rospy.Duration(2)
    rospy.loginfo("start sleep")
    rospy.sleep(du1)
    rospy.loginfo("end sleep")


    timer = rospy.Timer(rospy.Duration(1), doMsg)
    rospy.spin()



