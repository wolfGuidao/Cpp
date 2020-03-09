#pragma once
#include<vector>
#include"common.hpp"

template<class T>
struct HashNode 
{
  HashNode(const T& data = T())
    :_pNext(nullptr)
     ,_data(data)
  {}
  HashNode<T>* _pNext;
  T _data;              //哈希桶中的键值对
};

//声明
template<class T, class KorV, class DF = DFStr>
class HashBucket;

//KorV是用来适配键值对的情况和普通情况
//如果是键值对，就在对应的类中封装一个KorV的仿函数
//T是哈希桶内的每个节点数据类型
//DF是自己封装的一个仿函数类，因为在计算哈希地址的时候
//需要用date % capacity，字符就不能用来%，所以需要把字符串转换为整型
//封装一个哈希桶的迭代器类
template<class T, class KorV,class DF = DFStr>
struct Iterator 
{
  typedef HashNode<T> Node;
  typedef Iterator<T, KorV, DF> Self;

  Iterator(Node* pNode = nullptr, HashBucket<T, KorV, DF>* ht = nullptr)
    :_pNode(pNode)
     ,_ht(ht)
  {}

  //*
  T& operator*() 
  {
    return _pNode->_data;
  }

  //->
  T* operator->() 
  {
    return &(_pNode->_data);
  }

  //++a
  Self& operator++() 
  {
    Next();
    return *this;
  }

  //a++
  Self operator++(int) 
  {
    Self tmp(_pNode);
    Next();
    return tmp;
  }

  //a == b
  bool operator==(Self& t) 
  {
    return _pNode == t._pNode;
  }

  //a != b
  bool operator!=(Self& t) 
  {
    return _pNode != t._pNode;
  }

  void Next() 
  {
    //哈希桶中的每个桶不一定都是有数据的，有可能为NULL
    //如果当前节点的下一个为真就往下遍历
    if (_pNode->_pNext) 
    {
      _pNode = _pNode->_pNext;
    }
    else //代表走到当前桶的哈希链链的末尾，需要找下一个不为空的哈希桶
    {
      //我们根据当前节点的值和哈希函数就可以获取到当前节点的值所在
      //的哈希桶号，直接遍历下一个桶即可
      size_t addr = _ht->HashFunc(_pNode->_data);
      for (int i = addr + 1; i < _ht->_arr.size(); ++i) 
      {
        if (_ht->_arr[i]) 
        {
          _pNode = _ht->_arr[i];
          return;
        }
      }
      //代表没有下一个不为空的哈希桶，直接返回NULL
      _pNode = nullptr;
    }
  }
  Node* _pNode;
  HashBucket<T, KorV, DF>* _ht;//这里就是前面声明的目的，如果需要获取下一个哈希桶
  //那么就需要哈希函数，而哈希函数就在哈希桶中封装
};

//哈希桶
template<class T, class KorV, class DF>
class HashBucket 
{
  public:
    //哈希桶中的每个节点的类型
    typedef HashNode<T> Node;

    //返回值类型
    typedef HashBucket<T, KorV, DF> Self;

    //迭代器类型
    typedef Iterator<T, KorV, DF> iterator;

    //因为前面的迭代器类访问了我们的私有成员size,需要friend声明
    friend struct Iterator<T, KorV, DF>;

  public:
    HashBucket(size_t size = 11)
      :_size(0)
    {
      _arr.resize(size);
    }

    ~HashBucket() 
    {
      Clear();
    }

    //注意这里的返回值是一个键值对，因为unordered系列的底层都是哈希
    //所以一定要注意适配
    std::pair<iterator, bool> Insert(const T& data) 
    {
      //判满
      CheckCapacity();
      
      //根据待插入的元素计算哈希地址即哈希通号
      size_t addr = HashFunc(data);

      //查找是否有重复节点，unordered_map/unordered_set是不允许重复元素的
      Node* ptr = _arr[addr];
      while (ptr) 
      {
        //这里就用到KorV，因为data如果是键值对，需要把first拿出来比较
        if (KorV()(ptr->_data) == KorV()(data))   
          //找到重复，就构造一个键值对，因为哈希桶的迭代器成员有哈希节点和哈希桶，所以需要把
          //当前ptr这个节点和this这个哈希桶传过去，并和false构成键值对
          return make_pair(iterator(ptr, this), false);

        ptr = ptr->_pNext;
      }

      //没找到重复，开始插入
      ptr = new Node(data);
      ptr->_pNext = _arr[addr];
      _arr[addr] = ptr;
      ++_size;
      //同理插入成功也够制造一个键值对返回去
      return make_pair(iterator(ptr, this), true);
    }

    //删除函数
    size_t Erase(const T& data) 
    {
      //计算当前元素的哈希桶号
      size_t addr = HashFunc(data);

      //获取到当前哈希桶号当中的哈希链
      Node* ptr = _arr[addr];
      Node* pre = nullptr;

      //执行删除
      while (ptr) 
      {
        if (ptr->_data == data) 
        {
          if (!pre) //删除头结点
            _arr[addr] = ptr->_pNext;
          else //删除中间节点
            pre->_pNext = ptr->_pNext;

          delete ptr;
          --_size;
          return 1;
        }
        else 
        {
          pre = ptr;
          ptr = ptr->_pNext;
        }
      }
      return 0;
    }

    //查找
    iterator find(const T& data) const
    {
      size_t addr = HashFunc(data);
      Node* ptr = _arr[addr];
      while (ptr) 
      {
        //同理还是要用KorV来获取键值对的first,返回查找到元素位置的迭代器
        if (KorV()(ptr->_data) == KorV()(data))
          return iterator(ptr, this);

        ptr = ptr->_pNext;
      }
      return iterator(nullptr, this);
    }

    //返回桶的个数
    size_t size() const
    {
      return _size;
    }

    bool empty()const 
    {
      return _size == 0;
    }

    iterator begin() 
    {
      for (int i = 0; i < _arr.size(); ++i) 
      {
        if (_arr[i]) 
        {
          return iterator(_arr[i], this);
        }
      }
      return iterator(nullptr, this);
    }

    iterator end() 
    {
      return iterator(nullptr, this);
    }

    void Clear() 
    {
      for (size_t i = 0; i < _arr.size(); ++i) 
      {
        Node* ptr = _arr[i];
        while (ptr) 
        {
          _arr[i] = ptr->_pNext;
          delete ptr;
          ptr = _arr[i];
        }
      }
      _size = 0;
    }

    //统一外部的接口
    size_t bucket_count() const
    {
      return _arr.size();
    }

    //返回当前元素所在桶中元素的个数
    size_t bucket_size(size_t n) const
    {
      if (n >= _arr.size())
        return 0;

      size_t count = 0;
      Node* ptr = _arr[n];
      while (ptr) 
      {
        ++count;
        ptr = ptr->_pNext;
      }
      return count;
    }

    //返回当前元素的桶号
    size_t bucket(const T& data) 
    {
      return HashFunc(data);
    }

    void Swap(Self& t) 
    {
      _arr.swap(t._arr);
      std::swap(_size, t._size);
    }

  private:
    void CheckCapacity() 
    {    //扩容
      if (_size == _arr.size()) 
      {
        //获取下一个比当前空间大的素数
        size_t newSize = GetNextPrime(_arr.size());

        //注意不能用vector的默认扩容方式
        //vector的扩容方式为：申请空间----->拷贝元素---->释放旧空间
        //如果采用vector的默认扩容方式，1 : 那么在把就空间的元素拷贝到新空间后，原空间就是放掉
        //那么原哈希桶中的每个哈希链都被释放掉，而在新空间还在使用每个哈希链（简单来说就是浅拷贝）
        //2 : 因为发生扩容，那么capacity可定会发生变化，而哈希地址的计算方法是data % capacity 
        //新空间的容量已经发生改变，就会导致无法正确的获取到对应元素的桶号，即直接拷贝到响应位置的
        //哈希链是根据旧空间的大小计算出来的哈希地址，而不是根据新空间计算出来的哈希地址，

        //申请一个临时类类型的变量
        Self newBucket(newSize);
        for (size_t i = 0; i < _arr.size(); ++i) 
        {
          Node* ptr = _arr[i];
          while (ptr) 
          {
            //重新根据新空间的大小计算新的哈希地址
            size_t addr = newBucket.HashFunc(ptr->_data);

            //保存旧空间的某一条不为空的哈希链的首元素的下一个
            _arr[i] = ptr->_pNext;

            //改变当前哈希链的元素指向，让其指向新空间的新哈希地址处
            ptr->_pNext = newBucket._arr[addr];

            //更改哈希桶中的首地址
            newBucket._arr[addr] = ptr;
            ++newBucket._size;

            //把原来的下一个节点放到当前节点的位置，进行循环
            ptr = _arr[i];
          }
        }
        //最后交换
        Swap(newBucket);
      }
    }

    size_t HashFunc(const T data) const
    {
      //DF是为了解决字符串和整形数据的问题
      //KorV是为了解决适配问题，获取first元素
      return DF()(KorV()(data)) % _arr.size();
    }

  private:
    std::vector<Node*>  _arr;
    size_t _size;
};
