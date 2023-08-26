#! usr/bin/env python

import rospy


if __name__ == "__main__":
    rospy.init_node("param_del_p")
    try:
        rospy.delete_param("radius_p")
    except Exception as e:
        rospy.loginfo("被删除的参数不存在！！")


