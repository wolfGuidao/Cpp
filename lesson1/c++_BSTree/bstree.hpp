#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
using namespace std;

template<class T>
struct BSTNode
{
  BSTNode(const T& data = T())
    :_pLeft(nullptr)
     ,_pRight(nullptr)
     ,_data(data)
  {}

  BSTNode<T>* _pLeft;
  BSTNode<T>* _pRight;
  T _data;
};

template<class T>
class BSTree
{
  typedef BSTNode<T> Node;
  public:
    BSTree()
      :_pRoot(nullptr)
    {}

    ~BSTree()
    {
      Destory(_pRoot);
    }

    Node* Find(const T& data)
    {
        assert(_pRoot);
        
        Node* cur = _pRoot;
        while(cur)
        {
          if(cur->_data == data)
          {
            return cur;
          }
          else if(cur->_data > data)
          {
            cur = cur->_pLeft;
          }
          else
          {
            cur = cur->_pRight;
          }
        }
        cout<<"this bstree is no data node!"<<endl;
        return nullptr;
    }

    void Print()
    {
      Print(_pRoot);
      cout<<endl;
    }

    bool Insert(const T& data)
    {
      if(nullptr == _pRoot)
      {
        _pRoot = new Node(data);
        return true;
      }

      Node* cur = _pRoot;
      Node* pParent = nullptr;
      while(cur)
      {
        pParent = cur;
        if(cur->_data > data)
        {
          cur = cur->_pLeft;
        }
        else if(cur->_data < data)
        {
          cur = cur->_pRight;
        }
        else 
        {
          return false;
        }
      }
      cur = new Node(data);
      if(pParent ->_data > data)
      {
        pParent->_pLeft = cur;
      }
      else if(pParent->_data < data)
      {
        pParent->_pRight = cur;
      }
      
      return true;
    }

    bool Erase(const T& data)
    {
      if(_pRoot == nullptr)
      {
        return false;
      }

      Node* cur = _pRoot;//指向待删除节点
      Node* pParent = nullptr;//除根结点外，指向待删除结点的父亲节点
      //注意这里的循环，pParent开始是为空的，如果待删除结点刚好为根节点，就应该另外判断，否者会出错
      while(cur)
      {
        if(cur->_data == data)
        {
          break;
        }
        else if(cur->_data > data)
        {
          pParent = cur;
          cur = cur->_pLeft;
        }
        else 
        {
          pParent = cur;
          cur = cur->_pRight;
        }
      }
      //出while循环的方法有2种，1：break出来，代表找到待删除节点cur；2：cur == nullptr 出来，代表该树内没有
      //data节点

      if(cur == nullptr)
      {
        perror("this tree is no data");
        return false;//没找到data的节点
      }

      //走到这里代表找到待删除节点，就分情况删除即可

      //待删除节点没有左右孩子：直接删除
      if(cur->_pRight == nullptr && cur->_pLeft == nullptr)
      {
        return RLNULL(_pRoot,pParent,cur);
      }
      //待删除节点的右孩子为空：把待删除节点的父亲节点指向待删除节点的左孩子
      else if(cur->_pRight == nullptr && cur->_pLeft != nullptr)
      {
        return RNULL(_pRoot,pParent,cur);
      }
      //待删除节点的左孩子为空：把待删除结点的父亲节点指向待删除结点的右孩子
      else if(cur->_pLeft == nullptr && cur->_pRight != nullptr)
      {
        return LNULL(_pRoot,pParent,cur);
      }
      //待删除节点的左右孩子都不为空：两种方法：1：在其左子树中找最大的节点进行替换；2：在其右子树中
      //找最小节点进行替换。然后进行删除（这里采用第2种方法）
      else 
      {
        //输出型参数
        Node* pcur;//替换节点
        Node* ppParent;//代替换节点的父亲节点

        //找到替换节点
        GetNode(cur,ppParent,pcur);

        swap(cur->_data,pcur->_data);//把待删除节点和替换节点进行交换，然后删除替换节点，
        //就把原本待删除节点左右孩子都存在转化为只有右孩子或这没有右孩子的情况（因为找的替换节点是
        //右子树中最小的节点，根据二叉搜索树的性质，该节点一定在子树的最左边，所以找到的节点要么没有
        //孩子，要么只有右孩子，不可能有左孩子）

        if(pcur->_pRight)//有右孩子
        {
          return LNULL(_pRoot,ppParent,pcur);
        }

        //没有孩子
        return RLNULL(_pRoot,ppParent,pcur);
      }

      return true;
    }

  private:
    bool RLNULL(Node*& _pRoot,Node*& pParent,Node*& cur)
    {
      if(cur == _pRoot)
      {
        delete _pRoot;
        _pRoot = nullptr;
        return true;
      }
      
      if(pParent->_pLeft == cur)
      {
        pParent->_pLeft = nullptr;
      }
      else if(pParent->_pRight == cur)
      {
        pParent->_pRight = nullptr; 
      }

      delete cur;
      cur = nullptr;

      return true;
    }

    bool RNULL(Node*& _pRoot,Node*& pParent,Node*& cur)
    {
      if(cur == _pRoot)
      {
        Node* pcur = _pRoot->_pLeft;
        delete _pRoot;
        _pRoot = pcur;
        return true;
      }

      if(pParent->_pLeft == cur)
      {
        pParent->_pLeft = cur->_pLeft;
      }
      else if(pParent->_pRight == cur)
      {
        pParent->_pRight = cur->_pLeft; 
      }
      
      delete cur;
      cur = nullptr;
      return true;
    }

    bool LNULL(Node*& _pRoot,Node*& pParent,Node*& cur)
    {
      if(cur == _pRoot)
      {
        Node* pcur = _pRoot->_pRight;
        delete _pRoot;
        _pRoot = pcur;
        return true;
      }

      if(pParent->_pLeft == cur)
      {
        pParent->_pLeft = cur->_pRight;
      }
      else if(pParent->_pRight == cur)
      {
        pParent->_pRight = cur->_pRight; 
      }
      
      delete cur;
      cur = nullptr;
      return true;

    }

    void GetNode(Node* pRoot,Node*& pParent,Node*& cur)
    {

      cur = Inorder(pRoot->_pRight);

      //如果替换节点等于子树的根节点，直接返回替换节点的父亲节点
      if(cur->_data == pRoot->_pRight->_data)
      {
       pParent = pRoot; 
      }
      else //反之进行循环查找替换节点的父亲节点
      {
        Node* p = pRoot->_pRight;
        Node* temp = Inorder(pRoot->_pRight);

        Node* pp = p->_pLeft;

        while(pp->_data != temp->_data)
        {
          p = pp;
          pp = pp->_pLeft;
        }
        pParent = p;

      }
    }

    Node* Inorder(Node* pRoot)//找到替换节点
    {
      if(pRoot)
      {
        Node* cur = pRoot->_pLeft;//如果cur为空，代表子树的根节点没有左孩子，那么就可以直接返回
        if(cur == nullptr)
        {
          return pRoot;
        }
        //反之发明会子树的最左边的节点
        Inorder(cur);
        return cur;
      }
    }

    void Destory(Node*& pRoot)
    {
      if(pRoot)
      {
        Destory(pRoot->_pLeft );
        Destory(pRoot->_pRight);
        delete pRoot;
        pRoot = nullptr;
      }
    }

    void Print(Node* _pRoot)
    {
      if(_pRoot)
      {
        Print(_pRoot->_pLeft);
        cout<<_pRoot->_data<<" ";
        Print(_pRoot->_pRight);
      }
    }

    Node* _pRoot;
};

