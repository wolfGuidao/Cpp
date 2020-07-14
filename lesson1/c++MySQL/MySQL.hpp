/*************************************************************************
# File Name: MySQL.hpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月14日 星期二 17时58分46秒
 *************************************************************************/
#pragma once 
#include <iostream>
#include <mysql/mysql.h>
#include "until.hpp"

class MySQLDB 
{
    public:
        MySQLDB(const char* ip,const char* user,const char* passwd,const char* db,uint16_t port)
        {
            bool ret = _Init();
            if(ret == false)
            {
                LOG(ERROR)<<"init error"<<std::endl;
            }

            _IP = ip;
            _USER = user;
            _PASSWD = passwd;
            _DB = db;
            _PORT = port;
            _UNIX_SOCKET = NULL;
            _CLIENT_FLAG = 0;

            mysql_set_character_set(_mysql,"utf8");
        }

        bool Connect()
        {
            if(mysql_real_connect(_mysql,_IP,_USER,_PASSWD,_DB,_PORT,_UNIX_SOCKET,_CLIENT_FLAG) == NULL)
            {
                LOG(ERROR)<<mysql_error(_mysql)<<std::endl;
                return false;
            }
            LOG(INFO)<<"数据库连接成功"<<std::endl;
            return true;
        }

        bool Select(const char* sql)
        {
            //执行sql语句
            bool ret = _Query(sql);
            if(ret == false)
            {
                return false;
            }

            //获取sql语句执行后的 结果集
            MYSQL_RES* result = mysql_store_result(_mysql);

            //获取结果集的总行数
            int rows = mysql_num_rows(result);

            //获取结果集的字段数（列数）
            int fields = mysql_num_fields(result);

            //遍历所有的行
            for(int i = 0;i < rows;i++)
            {
                //从结果集中获取下一行,调用一次获取一行数据，结束返回NULL
                MYSQL_ROW row = mysql_fetch_row(result);
                //打印每一行的所有字段（列）
                for(int j = 0;j < fields;j++)
                {
                    printf("%s\t",row[j]);
                }
                printf("\n");
            }

            //释放结果集
            mysql_free_result(result);
            LOG(INFO)<<"查询数据库成功"<<std::endl;
            return true;
        }

        bool insert(const char* sql)
        {
            bool ret = _Query(sql);
            if(ret == false)
            {
                LOG(ERROR)<<"增加数据失败"<<std::endl;
                return ret;
            }
            LOG(ERROR)<<"增加数据成功"<<std::endl;
            return true;
        }

        bool Del(const char* sql)
        {
            bool ret = _Query(sql);
            if(ret == false)
            {
                LOG(ERROR)<<"删除数据失败"<<std::endl;
                return ret;
            }
            LOG(ERROR)<<"删除数据成功"<<std::endl;
            return true;
        }

        bool Update(const char* sql)
        {
            bool ret = _Query(sql);
            if(ret == false)
            {
                LOG(ERROR)<<"更新数据失败"<<std::endl;
                return ret;
            }
            LOG(ERROR)<<"更新数据成功"<<std::endl;
            return true;
        }

        bool Alter(const char* sql)
        {
            bool ret = _Query(sql);
            if(ret == false)
            {
                LOG(ERROR)<<"更新表结构失败"<<std::endl;
                return ret;
            }
            LOG(ERROR)<<"更新表结构成功"<<std::endl;
            return true;
        }

        ~MySQLDB()
        {
            _Close();
        }

    private:
        bool _Query(const char* sql)
        {
            int ret = mysql_query(_mysql,sql);

            if(ret < 0)
            {
                LOG(ERROR)<<mysql_error(_mysql);
                _Close();
                return false;
            }
            return true;
        }

        bool _Init()
        {
            _mysql = mysql_init(NULL);
            if(_mysql == NULL)
            {
                LOG(ERROR)<<mysql_error(_mysql)<<std::endl;
                return false;
            }
            return true;
        }

        void _Close()
        {
            mysql_close(_mysql);
        }

    private:
        //数据库操作句柄
        MYSQL* _mysql;

        //ip
        const char* _IP;

        //登陆数据库的用户
        const char* _USER;

        //对应用户的密码
        const char* _PASSWD;

        //待操作的数据库
        const char* _DB;

        //端口号
        uint16_t _PORT;

        //下面两个使用默认值即可
        const char* _UNIX_SOCKET;
        unsigned long _CLIENT_FLAG;
};

