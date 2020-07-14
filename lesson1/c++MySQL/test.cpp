/*************************************************************************
# File Name: test.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月14日 星期二 18时16分26秒
*************************************************************************/
#include <iostream>
#include "MySQL.hpp"
using namespace std;

int main()
{
    MySQLDB mysql("127.0.0.1","root","","blog_system",3306);

    bool ret = mysql.Connect();
    if(!ret)
    {
        cout<<"connect error"<<endl;
    }
    //char sql[1024 * 10] = "desc blog_table";
    //ret = mysql.Select(sql);
    //if(!ret)
    //{
    //    cout<<"select error"<<endl;
    //}
    
    char sql[1024 * 10] = {0};
    char title[]="test";
    char content[]="这不知道是一个什么正文";
    int tag_id=1;
    char date[]="\"2099-09-9 20:20:20\"";    
    sprintf(sql,"insert into blog_table values(null,'%s','%s',%d,'%s')",title,content,tag_id,date);
    mysql.insert(sql);
    mysql.Select("select* from blog_table");
    return 0;
}
