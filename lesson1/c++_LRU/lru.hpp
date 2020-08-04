/*************************************************************************
# File Name: lru.hpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月04日 星期二 23时33分23秒
*************************************************************************/
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


class LRUCache {
public:
    
    LRUCache(int capacity)
    :_capacity(capacity)
    {   
         
    }

    int get(int key) 
    {
        auto it = lru_ump.find(key);

        //如果没有找到
        if(it == lru_ump.end())
        {
            return -1;
        }
        else 
        {
            //根据key获取他在list中对迭代器
            pair<int,int> temp = *lru_ump[key];

            //删除已存在对key
            lru_list.erase(lru_ump[key]);

            //重新插入key到list的前面
            lru_list.push_front(temp);

            //更新key在ump中的位置
            lru_ump[key] = lru_list.begin();

            //返回value
            return temp.second;
        }
    }

    void put(int key, int value) 
    {
        auto it = lru_ump.find(key);
         
        //如果没找到了
        if(it == lru_ump.end())
        {
            //如果list已经满了，需要淘汰key
            if(lru_list.size() == _capacity)
            {
                //取list中最后一个
                auto temp = lru_list.back();

                //分别在ump和list中删除
                lru_ump.erase(temp.first);
                lru_list.pop_back();
            }
            //插入新数据key在list的前面
            lru_list.push_front(pair<int ,int >(key,value));

            //ump中插入新数据key在list中的位置迭代器
            lru_ump[key] = lru_list.begin();
        }
        //找到了，就换到list的队头
        else 
        {
            //删除list的旧位置值
            lru_list.erase(lru_ump[key]);

            //list中插入在list的头部
            lru_list.push_front(make_pair(key,value));

            //更新在ump中的迭代器值
            lru_ump[key] = lru_list.begin();
        }
    }

private:
    int _capacity;
    //哈希表，注意第二个是list的迭代器，代表key在list中的位置
    unordered_map<int,list<pair<int ,int>>::iterator> lru_ump;

    //双向链表
    list< pair<int ,int>>lru_list;
};


