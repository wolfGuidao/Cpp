#include <bits/stdc++.h>
using namespace std;

namespace eraze 
{
    class UnionFind     
    {                                   
        public:        
            UnionFind(size_t N)       
            {          
                _arr.resize(N,-1);
            }                  

            //找根
            int FindRoot(int x)
            {                              
                while(_arr[x] >= 0)
                {                              
                    x = _arr[x];               
                }

                return x;
            }

            //合并并查集
            void Union(int x1,int x2)
            {
                int root1 = FindRoot(x1);
                int root2 = FindRoot(x2);

                if(root1 != root2)
                {
                    _arr[root1] += _arr[root2];
                    _arr[root2] = root1;
                }

            }      

            size_t SetSize()
            {
                size_t n = 0;
                for(size_t i = 0;i < _arr.size();i++)
                {
                    if(_arr[i] < 0)
                        n++;
                }
                return n;
            }
        private:      
            vector<int> _arr;
    };          
}

namespace structnode 
{
    struct DLinkedNode 
    {
        int key; 
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
        DLinkedNode()
            : key(0)
              , value(0)
              , prev(nullptr)
              , next(nullptr) 
        {}

        DLinkedNode(int _key, int _value)
            : key(_key)
              , value(_value)
              , prev(nullptr)
              , next(nullptr) 
        {}
    };

    class LRUCache 
    {
        private:
            unordered_map<int, DLinkedNode*> cache;
            DLinkedNode* head;
            DLinkedNode* tail;
            int size;
            int capacity;

        public:
            LRUCache(int _capacity): capacity(_capacity), size(0) 
        {
            // 使用伪头部和伪尾部节点
            head = new DLinkedNode();
            tail = new DLinkedNode();
            head->next = tail;
            tail->prev = head;
        }

            int get(int key)
            {
                if (!cache.count(key)) 
                {
                    return -1;
                }

                // 如果 key 存在，先通过哈希表定位，再移到头部
                DLinkedNode* node = cache[key];
                moveToHead(node);
                return node->value;
            }

            void put(int key, int value) 
            {
                if (!cache.count(key)) 
                {
                    // 如果 key 不存在，创建一个新的节点
                    DLinkedNode* node = new DLinkedNode(key, value);
                    // 添加进哈希表
                    cache[key] = node;
                    // 添加至双向链表的头部
                    addToHead(node);
                    ++size;
                    if (size > capacity) 
                    {
                        // 如果超出容量，删除双向链表的尾部节点
                        DLinkedNode* removed = removeTail();
                        // 删除哈希表中对应的项
                        cache.erase(removed->key);
                        // 防止内存泄漏
                        delete removed;
                        --size;
                    }
                }
                else
                {
                    // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
                    DLinkedNode* node = cache[key];
                    node->value = value;
                    moveToHead(node);
                }
            }

            void addToHead(DLinkedNode* node) 
            {
                node->prev = head;
                node->next = head->next;
                head->next->prev = node;
                head->next = node;
            }

            void removeNode(DLinkedNode* node) 
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            void moveToHead(DLinkedNode* node) 
            {
                removeNode(node);
                addToHead(node);
            }

            DLinkedNode* removeTail() 
            {
                DLinkedNode* node = tail->prev;
                removeNode(node);
                return node;
            }
    };
}

namespace list 
{
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
}
