#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

namespace wolf
{
  template<class T>
  struct ListNode
  {
    ListNode(const T& val = T())
    {
      _pPre = nullptr;
      _pNext = nullptr;
      _val = val;
    }

    ListNode<T>* _pPre;
    ListNode<T>* _pNext;
    T _val;
  };//struct listnode is end

  template<class T,class Ref,class Ptr>
  class ListIterator
  {
    typedef ListNode<T> Node;
    typedef ListIterator<T,Ref,Ptr> Self;

    public:
    ListIterator(Node* pNode = nullptr)
    {
      _pNode = pNode;
    }

    ListIterator(const Self& l)
    {
      _pNode = l._pNode;
    }

    ~ListIterator()
    {
      if(_pNode)
      {
        delete _pNode;
        _pNode = nullptr;
      }
    }

    T& operator*()
    {
      return _pNode->_val;
    }

    T* operator->()
    {
      return &(_pNode->_val);
    }

    Self& operator++()
    {
      _pNode = _pNode->_pNext;
      return *this;
    }

    //栈上的空间不能作为引用的返回值
    Self operator++(int)
    {
      Self temp(*this);
      _pNode = _pNode->_pNext;
      return temp;
    }

    Self& operator--()
    {
      _pNode = _pNode->_pPre;
      return *this;
    }

    //栈上的空间不能作为引用的返回值
    Self operator--(int)
    {
      Self temp(*this);
      _pNode = _pNode->_pPre;
      return temp;
    }

    bool operator!=(const Self& l)
    {
      return _pNode != l._pNode;
    }

    bool operator==(const Self& l)
    {
      return !operator!=(l);
    }
  
    private:
    public:

    Node* _pNode;

  };//class ListIterator is end

  template<class T>
  class list
  {
    public:
    typedef ListNode<T> Node;
    typedef ListIterator<T,T&,T*> iterator;
    typedef ListIterator<T,const T&,const T&> const_iterator;

    list()
    {
      CreateHead();
      cout<<__LINE__<<endl;
    }

    list(int n,const T& value = T())
    {
      cout<<__LINE__<<endl;
      CreateHead();
      cout<<__LINE__<<endl;
      cout<<__LINE__<<endl;
      for(int i = 0;i < n;i++)
      {
      cout<<__LINE__<<endl;
        push_back(value);
      cout<<__LINE__<<endl;
      }
      cout<<__LINE__<<endl;
    }

    template<class Iterator>
    list(Iterator first,Iterator last)
    {
      CreateHead();
      while(first != last)
      {
        push_back(*first);
        ++first;
      }
    }

    list(const list& l)
    {
      CreateHead();

      list<T> temp(l.cbegin(),l.cend());
      this->Swap(temp);
    }

    list<T>& operator=(const list<T> l)
    {
      this->Swap(l);
      return *this;
    }

    ~list()
    {
      Clear();
      delete _pHead;
      _pHead = nullptr;
    }

    void Clear()
    {
      auto it = begin();
      while(it != end())
      {
        Node* pCur = it._pNode;
        it++;
        delete pCur;
        
      }
    }

    void Print()
    {
      auto it = begin();
      cout<<__LINE__<<endl;
      while(it != end())
      {
        cout<<*it<<"->";
        it++;
      }
      cout<<endl;
    }

    void Swap(const list<T>& l)
    {
      swap(_pHead,l._pHead);
    }

    void push_back(const T& val)
    {
      cout<<__LINE__<<endl;
      insert(end(),val);
      cout<<__LINE__<<endl;
    }

    void pop_back()
    {
      erase(--end());
    }

    void push_front(const T& val)
    {
      insert(begin(),val);
    }

    void pop_front()
    {
      erase(begin());
    }

    iterator insert(iterator pos,const T& val)
    {
      cout<<__LINE__<<endl;
      Node* node = new Node(val);
      Node* pCur = pos._pNode;
      cout<<__LINE__<<endl;

      node->_pPre = pCur->_pPre;
      cout<<__LINE__<<endl;
      node->_pNext = pCur;
      cout<<__LINE__<<endl;
      node->_pPre->_pNext = node;
      cout<<__LINE__<<endl;
      pCur->_pPre = node;
      cout<<__LINE__<<endl;

      return iterator(node);
    }

    iterator erase(iterator pos)
    {
      Node* pDel = pos._pNode;
      Node* pRet = pDel->_pPre;

      pDel->_pPre->_pNext = pDel->_pNext;
      pDel->_pNext->_pPre = pDel->_pPre;

      delete pDel;

      return iterator(pRet);
    }

    iterator begin()
    {
      return iterator(_pHead->_pNext);
    }

    iterator end()
    {
      return iterator(_pHead);
    }

    const_iterator cbegin()
    {
      return const_iterator(_pHead->_pNext);
    }

    const_iterator cend()
    {
      return const_iterator(_pHead);
    }

    private:

    void CreateHead()
    {
      cout<<__LINE__<<endl;
      _pHead = new Node;
      _pHead->_pNext = _pHead;
      _pHead->_pPre = _pHead;
    }

    Node* _pHead;//头节点

  };//class list is end
}//namespace wolf is end
