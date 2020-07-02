#pragma once
#include<vector>
#include"Common.hpp"

//用来标记哈希表中的元素状态
enum State { EMPTY, EXIST, DELETE  };
//            空     存在   删除

//元素类
template<class T>
struct Elem 
{
  Elem(const T& val = T())
    :val_(val)
     , state_(EMPTY)
  {}

  T val_;//元素的值
  State state_;//元素的状态
};

template<class T, class DF = DFInt, bool isLine = true>
class HashTable 
{
  public:
    HashTable(size_t capacity = 5)
      :size_(0)
       ,total_(0)
    {
    //vec_.resize(GetNextPrime(capacity));
        vec_.resize(capacity);
    }

    //向哈希表中插入元素
    bool Insert(const T& num) 
    {
      CheckCapacity();//检查是否需要扩容

      //计算哈希地址
      size_t addr = HashAddr(num);

      size_t i = 0;

      //删除状态的元素是不可以插入新元素的，因为如果插入新元素下次查找哈希表就无法
      //正确查找
      while (vec_[addr].state_ != EMPTY) 
      {
        //如果对应哈希地址处的元素状态不是空，就代表是存在或者为删除
        if (vec_[addr].state_ == EXIST && vec_[addr].val_ == num)
          return false;

        if (isLine) 
        {   //线程探测
          ++addr;

          //如果走到满了，就回到哈希表的起始处，继续循环判断
          if (addr == vec_.size())
            addr = 0;
        }
        else 
        {      //二次探测
          ++i;
          addr = addr + 2 * i + 1;

          //进行循环判断
          addr %= vec_.size();
        }
      }

      //代码走到这里代表找到合适的插入位置即空状态的位置
      vec_[addr].val_ = num;
      vec_[addr].state_ = EXIST;

      ++size_;
      ++total_;
      return true;
    }

    //查找
    int Find(const T& num) 
    {
      //计算哈希地址
      size_t addr = HashAddr(num);

      size_t i = 0;
      while (vec_[addr].state_ != EMPTY) 
      {
        if (vec_[addr].state_ == EXIST && vec_[addr].val_ == num)
          return addr;

        if (isLine) 
        {   //线程探测
          ++addr;
          if (addr == vec_.size())
            addr = 0;
        }
        else 
        {      //再次哈希
          ++i;
          addr = addr + 2 * i + 1;
          addr %= vec_.size();
        }
      }

      //否则就是没找到
      return -1;
    }

    //删除元素
    bool Erase(const T& num) 
    {
      int addr = Find(num);
      if (addr != -1) 
      {
        vec_[addr].state_ = DELETE;
        --size_;
        return true;
      }
      return false;
    }

    size_t Size() const
    {
      return size_;
    }

  private:
    void CheckCapacity() 
    {
      //注意哈希表的满并不是真正的满了
      if (1.0*(total_ + 1) / vec_.size() >= 0.7) 
      {
        size_t newCapacity = GetNextPrime(vec_.size());

        HashTable<T,DF,isLine> newTH(newCapacity);
        for (const auto& e : vec_) 
        {
          if (e.state_ == EXIST)
            newTH.Insert(e.val_);
        }
        Swap(newTH);
      }
    }

    void Swap(HashTable<T,DF,isLine>& ht) 
    {
      vec_.swap(ht.vec_);
      total_ = size_;     //没有存在删除状态的数据了 更新total ,size不变  不需要交换
    }

    size_t HashAddr(const T& num) 
    {
      return DF()(num) % vec_.size();
    }

  private:

    size_t size_;
    size_t total_;
    std::vector<Elem<T>> vec_;
};
