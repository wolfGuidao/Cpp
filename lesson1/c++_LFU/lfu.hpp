/*************************************************************************
# File Name: lfu.hpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年08月04日 星期二 23时31分22秒
*************************************************************************/
#include <iostream>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

/*
struct Node 
{
	//频率
    int cnt;

	//时间
    int time;

	//数据
    int key, value;

	//构造
    Node(int _cnt, int _time, int _key, int _value)
    :cnt(_cnt)
    , time(_time)
    , key(_key)
    , value(_value)
    {}
    
    //自定义比较规则：以频率为第一关键字，时间为第二关键字
    bool operator < (const Node& rhs) const 
    {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache 
{
    // 缓存容量
    int capacity;
	
	//时间戳
	int time;

	//关键字和数据信息的哈希索引
    unordered_map<int, Node> key_table;

	//平衡搜索树
    set<Node> S;
    
public:
    LFUCache(int _capacity) 
    {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) 
    {
        if (capacity == 0) 
        	return -1;
        
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) 
        	return -1;
        
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        
        //更新哈希表当中key对应的缓存数据
        it -> second = cache;

		//返回
        return cache.value;
    }
    
    void put(int key, int value) 
    {
        if (capacity == 0) 
        	return;
        
        auto it = key_table.find(key);
        if (it == key_table.end()) 
        {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) 
            {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else 
        {
            // 这里和 get() 函数类似
            //代表找到了key，取对应的缓存数据
            Node cache = it -> second;

			//在红黑树S中删除旧的缓存数据
            S.erase(cache);

			//在旧的缓存基础上更新缓存数据
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;

			//重新把缓存数据插到红黑树S当中
            S.insert(cache);

			//跟新哈希表对应key的缓存数据
            it -> second = cache;
        }
    }
};
*/

// 缓存的节点信息
struct Node 
{
	//数据
    int key, val;
    
	//频率
	int freq;

    Node(int _key,int _val,int _freq)
    : key(_key)
    , val(_val)
    , freq(_freq)
    {}
    
};
class LFUCache 
{
	//缓存的最小频率
    int minfreq;

	//容量
	int capacity;

	//哈希表；key为关键字key，value为key在freq_table中的位置
    unordered_map<int, list<Node>::iterator> key_table;

	//哈希表；key为缓存数据的频率，value为缓存数据的链
    unordered_map<int, list<Node>> freq_table;
    
public:
    LFUCache(int _capacity) 
    {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) 
    {
        if (capacity == 0) 
        	return -1;
        
        auto it = key_table.find(key);
        //没找到就直接返回
        if (it == key_table.end()) 
        	return -1;
        
		//代表找到了，取key对应的缓存数据在freq_table中某条链上的位置
		list<Node>::iterator node = it -> second;
		
		//保存旧的缓存数据
        int val = node -> val, freq = node -> freq;
        
        //把旧的缓存数据从freq_table对应频率的链上删除
        freq_table[freq].erase(node);
        
        // 如果删除后，当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) 
        {
            freq_table.erase(freq);
            if (minfreq == freq) 
            	minfreq += 1;
        }
        
        // 插入到 freq + 1 中频率的链头，因为该缓存数据get了一次
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));

		//同时更新该缓存数据在key_table中的信息
        key_table[key] = freq_table[freq + 1].begin();
        
        return val;
    }
    
    void put(int key, int value) 
    {
        if (capacity == 0) 
        	return;
        auto it = key_table.find(key);
        //如果没找到该缓存数据，就需要插入缓存，但是需要判断满否？
        if (it == key_table.end()) 
        {
            // 如果缓存已满，需要进行删除操作
            if (key_table.size() == capacity) 
            {
                // 通过最小缓存频率 minFreq 拿到其在 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();

				//把使用最少最旧的缓存数据在key_table和freq_table中淘汰掉
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();

				//如果删除后对应频率的链表为空，也需要在freq_table中删除
                if (freq_table[minfreq].size() == 0) 
                {
                    freq_table.erase(minfreq);
                }
            }
		
			//执行插入缓存操作：在freq_table中频率为1的链头插入新的缓存数据 
            freq_table[1].push_front(Node(key, value, 1));

			//在key_table中保存该缓存数据在链的迭代器
            key_table[key] = freq_table[1].begin();

			//更新最小的频率
            minfreq = 1;
        } 
        else 
        {
        	//代表找到了缓存数据
            // 与 get 操作基本一致，除了需要更新缓存的值
            //取该缓存数据在freq_table中某条链的迭代器
            list<Node>::iterator node = it -> second;

			//从迭代器中取到该缓存的频率
            int freq = node -> freq;

			//从freq_table中对应链删除该缓存
            freq_table[freq].erase(node);

			//同样需要判断删除后该链是否为空
            if (freq_table[freq].size() == 0) 
            {
                freq_table.erase(freq);
                if (minfreq == freq) 
                	minfreq += 1;
            }

			//把该缓存数据放大freq_table的频率 + 1 的链头
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));

			//同时更新该缓存数据在key_table中的位置
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

