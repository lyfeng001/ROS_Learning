#! usr/bin/env python

import rospy


if __name__ == "__main__":
    rospy.init_node("param_del_p")
    rospy.delete_param("radius_p")
    
