#! usr/bin/env python

import rospy
from turtlesim.srv import *


if __name__ == "__main__":
    rospy.init_node("fuwu")
    client = rospy.ServiceProxy("/spawn",Spawn)
    request = SpawnRequest()
    request.x = 4.5
    request.y = 2.0
    request.theta = 3.14
    request.name = "turtle3"
    client.wait_for_service()
    try:
        client.call(request)
        rospy.loginfo("生成乌龟的名字是：%s",request.name)
    except Exception as e:
        rospy.logerr("请求处理异常")



