#include "ros/ros.h"

void cb(const ros::TimerEvent event)
{
    ROS_INFO("----------");
    ROS_INFO("函数要调用的时刻：%.2f",event.current_real.toSec());
}



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"time");
    ros::NodeHandle nh;
    //1970年1月1日开始计算
    ros::Time right_now = ros::Time::now();
    ROS_INFO("当前时刻：%.2f",right_now.toSec());
    ROS_INFO("当前时刻：%.2d",right_now.sec);
    //设置时刻
    ros::Time t1(20,312345678);
    ros::Time t2(100.35);
    ROS_INFO("t1=%.2f,t2=%.2f",t1.toSec(),t2.toSec());

    //--------------------//
    ROS_INFO("------------持续时间-----------");

    //程序执行中停顿一定时间
    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠");
    ros::Duration du(0.5);
    du.sleep();
    ros::Time end = ros::Time::now();
    //时刻与时刻不能相加，只能相减  相减后数据类型变为duration
    ROS_INFO("结束休眠,总时长：%.2f",end.toSec()-start.toSec());

    ros::Duration du2(5);
    ros::Duration du3 = du + du2;
    ROS_INFO("du+du2=%.2f",du3.toSec());

    ROS_INFO("------------定时器-----------");
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);

    timer.start();
    ros::spin();

    return 0;
}



