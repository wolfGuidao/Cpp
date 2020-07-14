/*************************************************************************
# File Name: main.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月14日 星期二 20时19分30秒
*************************************************************************/

#include <iostream>
#include <string>
#include "Redis.h"
using namespace std;

int main()
{
    Redis* rh = new Redis();
    int ret;

    //连接测试
    //cout << "错误测试: " << "地址错误" << endl;
    //ret = rh->connect("127.0.0.0", 6379, "137126");
    //if (ret != M_REDIS_OK)
    //    cout << "redis error: " << rh->getErrorMsg() << endl;

    //cout << "错误测试: " << "端口错误" << endl;
    //ret = rh->connect("127.0.0.1", 1234, "linesum");
    //if (ret != M_REDIS_OK)
    //    cout << "redis error: " << rh->getErrorMsg() << endl;

    //cout << "错误测试: " << "密码错误" << endl;
    //ret = rh->connect("127.0.0.1", 6479, "linsum");
    //if (ret != M_REDIS_OK)
    //    cout << "redis error: " << rh->getErrorMsg() << endl;


    ret = rh->connect("127.0.0.1", 6379, "");
    if (ret != M_REDIS_OK)
    {
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }


    //set测试
    //cout << "错误测试: " << "set不带value参数" << endl;
    //ret = rh->setValue("key11", "");
    //if (ret != M_REDIS_OK)
    //    cout << "redis error: " << rh->getErrorMsg() << endl;


    //cout << "测试: " << "key11 : value11" << endl;
    //ret = rh->setValue("key11", "value11");
    //if (ret != M_REDIS_OK)
    //{
    //    cout << "redis error: " << rh->getErrorMsg() << endl;
    //    return ret;
    //}

    //cout << "测试: " << "key22 : value22" << endl;
    //ret = rh->setValue("key22", "value22");
    //if (ret != M_REDIS_OK)
    //{
    //    cout << "redis error: " << rh->getErrorMsg() << endl;
    //    return ret;
    //}


    ////get测试
    //string str;
    ////cout << "错误测试: " << "get不带key参数" << endl;
    ////ret = rh->getValue("key1111", str);
    ////if (ret != M_REDIS_OK)
    ////    cout << "redis error: " << rh->getErrorMsg() << endl;

    //cout << "测试: " << "get : key11" << endl;
    //ret = rh->getValue("key11", str);
    //if (ret != M_REDIS_OK)
    //{
    //    cout << "redis error: " << rh->getErrorMsg() << endl;
    //    return ret;
    //}
    //else
    //    cout << "value : " << str << endl;



    ////print测试
    //cout << "测试: " << "printAll" << endl;
    //ret = rh->printAll();
    //if (ret != M_REDIS_OK)
    //{
    //    cout << "redis error: " << rh->getErrorMsg() << endl;
    //    return ret;
    //}


    ////del测试
    ////cout << "错误测试: " << "删除不存在的key" << endl;
    ////ret = rh->delKey("key1111");
    ////if (ret != M_REDIS_OK)
    ////    cout << "redis error: " << rh->getErrorMsg() << endl;


    //cout << "测试: " << "删除key11" << endl;
    //ret = rh->delKey("key11");
    //if (ret != M_REDIS_OK)
    //{
    //    cout << "redis error: " << rh->getErrorMsg() << endl;
    //    return ret;
    //}

    rh->setValue("wolf","999");
    string result;
    rh->getValue("wolf",result);
    cout<<result<<endl;
    delete rh;
    return 0;
}
