#! usr/bin/env python

import rospy
from plumbing_server_client.srv import Addints,AddintsRequest,AddintsResponse

def doNums(request):
    num1 = request.num1
    num2 = request.num2
    sum = num1+num2
    response = AddintsResponse()
    response.sum = sum
    rospy.loginfo("服务器解析的数据：%d，%d，和为：%d",num1,num2,sum)
    return response

if __name__ == "__main__":
    rospy.init_node("shangJia")
    server = rospy.Service("addints",Addints,doNums)    

    rospy.spin()
