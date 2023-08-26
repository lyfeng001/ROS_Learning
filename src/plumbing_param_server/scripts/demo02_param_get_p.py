#! usr/bin/env python

import rospy


if __name__ == "__main__":
    rospy.init_node("param_get_p")
    # 1.1
    radius = rospy.get_param("radius",0.5)
    radius2 = rospy.get_param("radius222", 0.8)
    rospy.loginfo("radius=%.2f",radius)
    rospy.loginfo("radius2=%.2f",radius2)
    # 1.2
    radius3 = rospy.get_param("radius",0.5)
    radius4 = rospy.get_param("radius222", 0.8)
    rospy.loginfo("radius3=%.2f",radius3)
    rospy.loginfo("radius4=%.2f",radius4)
    # 1.3
    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo("name=%s",name)
    # 1.4
    flag1 = rospy.has_param("radius_p")
    if flag1:
        rospy.loginfo("radius_p exist")
    else:
        rospy.loginfo("radius_p not exist")

    flag2 = rospy.has_param("radius_ppp")
    if flag2:
        rospy.loginfo("radius_ppp exist")
    else:
        rospy.loginfo("radius_ppp not exist")
    # 1.5
    key = rospy.search_param("radius_p")
    rospy.loginfo("key=%s",key)




