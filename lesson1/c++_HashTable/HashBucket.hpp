#pragma once
#include"Common.hpp"
#include<vector>

template<class T>
struct HashNode
{
  HashNode(const T& val = T())
    :next_(nullptr)
     , val_(val)
  {}

  HashNode<T> *next_;
  T val_;
};


template<class T, class DF = DFInt>
class HashBucket 
{
  typedef HashNode<T> Node;

  public:
  HashBucket(size_t capacity = 5)
    :size_(0)
  {
    //vec_.resize(GetNextPrime(capacity));
    vec_.resize(capacity);
    //      
  }

  bool InsertUnique(const T& val) 
  {
    CheckCapacity();    //判断是否扩容

    //通过哈希函数计算哈希地址
    size_t addr = HashAddr(val);

    //查找哈希桶的哈希链表中是否存在相同的元素，保证插入元素唯一
    Node* ptr = vec_[addr];
    while (ptr) 
    {
      if (ptr->val_ == val)
        return false;

      ptr = ptr->next_;
    }

    //new出一个节点，连接在Hash链的头部 
    ptr = new Node(val);
    ptr->next_ = vec_[addr];

    //更新相同哈希地址处的哈希节点的地址
    vec_[addr] = ptr;
    ++size_;

    return true;
  }

  bool InsertEqual(const T& val) 
  {   
    //可插入重复
    CheckCapacity();    //判断是否扩容

    //直接连接在哈希链的头部
    size_t addr = HashAddr(val);
    Node* ptr =  new Node(val);
    ptr->next_ = vec_[addr];

    //更新相同哈希地址处的哈希链的地址
    vec_[addr] = ptr;
    ++size_;
    return true;
  }

    //删除哈希桶中的哈希链中的元素
  bool eraseUnique(const T& val) 
  {
    //通过元素计算其在哈希桶中的哈希链的地址
    size_t addr = HashAddr(val);

    //删除
    Node *ptr = vec_[addr];
    Node *pre = nullptr;
    while (ptr) 
    {
      if (ptr->val_ == val) 
      {
        if (!pre)
          vec_[addr] = ptr->next_;
        else
          pre->next_ = ptr->next_;

        delete ptr;
        --size_;
        return true;
      }
      else 
      {
        pre = ptr;
        ptr = ptr->next_;
      }
    }
    return false;
  }

     //删除全部
  bool eraseEqual(const T& val) 
  {   
    size_t addr = HashAddr(val);
    Node *ptr = vec_[addr];
    Node *pre = nullptr;
    while (ptr) 
    {
      if (ptr->val_ == val) 
      {
        if (!pre) 
        {
          vec_[addr] = ptr->next_;
          delete ptr;
          ptr = vec_[addr];
        }
        else 
        {
          pre->next_ = ptr->next_;
          delete ptr;
          ptr = pre->next_;
        }
        --size_;
      }
      else 
      {
        pre = ptr;
        ptr = ptr->next_;
      }
    }
    return true;
  }

  //查找元素
  Node* find(const T& val) const
  {
    //计算哈希地址
    size_t addr = HashAddr(val);

    Node *ptr = vec_[addr];
    while (ptr) 
    {
      if (ptr->val_ == val)
        return ptr;

      ptr = ptr->next_;
    }
    return nullptr;
  }

  size_t size()const 
  {
    return size_;
  }

  bool empty()const 
  {
    return 0 == size_;
  }

  void printHashBucket() 
  {
    for (size_t i = 0; i < vec_.size(); ++i) 
    {
      std::cout << "vec_[" << i << "]:";
      Node* ptr = vec_[i];
      while (ptr) 
      {
        std::cout << ptr->val_ << "--->";
        ptr = ptr->next_;
      }
      std::cout << "NULL" << std::endl;
    }
  }

  private:
  size_t HashAddr(const T& val) const
  {
    return DF()(val) % vec_.size();
  }

  void CheckCapacity() 
  {
    if (size_ == vec_.size()) 
    {
      HashBucket<T, DF> newHB(GetNextPrime(vec_.size()));
      for (size_t i = 0; i < vec_.size(); ++i) 
      {
        Node* ptr = vec_[i];
        while(ptr) 
        {
          vec_[i] = ptr->next_;
          size_t addr = newHB.HashAddr(ptr->val_);
          ptr->next_ = newHB.vec_[addr];
          newHB.vec_[addr] = ptr;
          ptr = vec_[i];
        }
      }
      vec_.swap(newHB.vec_);
    }
  }
  size_t size_;
  std::vector<Node*> vec_;
};
