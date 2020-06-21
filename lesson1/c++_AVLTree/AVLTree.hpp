#pragma once
#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
    //T如果是内置类型，那么T()就是0，如果T是自定义类型，T()相当于Date(),即该Date类必须提供无参的构造函数
    AVLTreeNode(const T& data = T())
        :_pLeft(nullptr)
         ,_pRight(nullptr)
         ,_data(data)
         ,_bf(0)
         ,_pParent(nullptr)
    {

    }
    AVLTreeNode<T>* _pLeft;
    AVLTreeNode<T>* _pRight;
    AVLTreeNode<T>* _pParent;
    T _data;
    int _bf;//记录平衡因子
};

template<class T>
class AVLTree
{
    typedef AVLTreeNode<T> Node;

    public:
    AVLTree()
        :_pRoot(nullptr)
    {}

    ~AVLTree()
    {
        Destory(_pRoot);
    }

    bool Insert(const T& data)
    {
        //AVL树可能是空树
        if(nullptr == _pRoot)
        {
            _pRoot = new Node(data);
            return true;
        }

        //AVL树非空
        //先按照二叉搜索树的方式插入新节点
        Node* pCur = _pRoot;
        Node* pParent = nullptr;

        //循环找到插入pCur节点的位置
        while(pCur)
        {
            //保存双亲节点，方便插入
            pParent = pCur;

            if(data < pCur->_data)
            {
                //如果插入数据比当前节点的值小，说明应该查到当前节点的左子树中
                pCur = pCur->_pLeft;
            }
            else if(data > pCur->_data)
            {
                //如果插入数据比当前节点的值大，说明应该查到当前节点的右子树中
                pCur = pCur->_pRight;
            }
            else
            {
                //如果插入数据比当前节点的值相等，说明当前数据已存在，不用插入
                return false;
            }
        }

        //找到叶子节点，插入新节点
        pCur = new Node(data);
        if(data < pParent->_data)
        {
            pParent->_pLeft = pCur;
        }
        else
        {
            pParent->_pRight = pCur;
        }

        //注意节点中加了_pParent指针所以插入节点后需要更新
        pCur->_pParent = pParent;

        //更新平衡因子
        //如果插入节点之前：pParent的平衡因子情况
        //0--->pParent是叶子节点---->pCur可能插在pParent的左侧|右侧--->插入pCur后对整棵树有影，需要向上调整
        //1--->pParent只有右孩子--->pCur只能插在pParent的左侧--->没影响，不用调整---->插入后pParent的平衡因子为0
        //-1--->pParent只有左孩子--->pCur只能插在pParent的右侧--->没影响，不用调整--->插入后pParent的平衡因子为0
        while(pParent)
        {
            //更新pParent节点的平衡因子,这里规定 平衡因子 = 右子树高度 - 左子树高度
            if(pCur == pParent->_pLeft)
            {
                //如果节点插在pParent的左子树上，就直接把平衡因子--即可
                pParent->_bf--;
            }
            else
            {
                //如果节点插在pParent的左子树上，就直接把平衡因子++即可
                pParent->_bf++;
            }

            if(0 == pParent->_bf)
            {
                //如果插入完成后，pParent节点的平衡因子等于0,说明插入之前pParent节点的平衡因子为1/-1，插入节点后，刚好保持平衡，
                //所以插入新节点是对整棵树是没有任何影响的，所以直接返回
                return true;
            }
            else if(-1 == pParent->_bf || 1 == pParent->_bf)
            {
                //说明插入之前pParent节点的平衡因子是0，导致插入节点后平衡因子变为1/-1,代表插入新节点后对整棵树是有影响的，
                //所以需要向上进行更新整棵树的平衡因子
                pCur = pParent;
                pParent = pCur->_pParent;
            } 
            else
            {
                //到这里说明pParent的平衡因子为+2/-2，代表是经过平衡因子调整后，导致pParent的平衡因子变为2/-2，注意单纯插入节点是不会出现2/-2的
                //情况的，只能是插入节点后向上更新平衡因子导致的
                //说明pParent节点已经违反AVL树的性质,需要调整,即要对 以pParent为根节点 进行旋转调整
                //左单旋：新节点插在较高右子树的右侧
                //右单旋：新节点插在较高左子树的左侧
                //左右双旋：
                //右左双旋：
                if(pParent->_bf == 2)
                {
                    //如果parent的平衡因子==2，说明右子树较高
                    //还需要根据当前插入节点的位置来判断是单纯的左单旋还是右左双旋
                    //如果当前节点的品衡因子是+1：因为pParent的平衡因子==2，也就是右子树比较高，而当前节点的平衡因子==+1，也就代表当前节点
                    //和pParent节点在同一侧；那么就只进行左单旋即可
                    if(pCur->_bf == 1)
                    {
                        //单旋
                        RotateL(pParent);
                    }
                    //说明当前节点和pParent节点在不在同一侧，就是出现‘‘拐的情况，这种必须进行右左双旋才可以
                    else
                    {
                        //-1,
                        RotateRL(pParent);
                    }
                }
                else//-2
                {
                    //如果parent的平衡因子==-2，说明左子树较高
                    //和pParent==2的情况道理相同
                    //当前节点和pParent节点在同一侧
                    if(pCur->_bf == -1)
                    {
                        RotateR(pParent);
                    }
                    //当前节点和pParent节点不在同一侧
                    else
                    {
                        RotateLR(pParent);
                    }
                }
                break;//新节点插入经过旋转后，这棵树的高度并没有增加，所以就不用向上继续调整了
            }
        }
        return true;
    }

    void Inorder()
    {
        _Inorder(_pRoot);
    }

    bool IsValidAVLTree()
    {
        return _IsValidAVLTree(_pRoot);
    }

    private:

    //右单旋：说明左子树比较高
    void RotateR(Node* pParent)
    {
        //pParent节点的左孩子节点
        Node* pSubL = pParent->_pLeft;
        //pParnet节点的左孩子节点的右孩子节点
        Node* pSubLR = pSubL->_pRight;

        //链接，改变左右孩子指针指向,双亲
        pParent->_pLeft = pSubLR;//1
        if(pSubLR)
        {
            pSubLR->_pParent = pParent;//更新双亲
        }

        pSubL->_pRight = pParent;//2

        //用来保存pParent的双亲
        Node* pPParent = pParent->_pParent;

        pSubL->_pParent = pPParent;//更新双亲
        pParent->_pParent = pSubL;//更新双亲

        if(pPParent == nullptr)//更新双亲
        {
            //说明子树原来pParent为根节点
            _pRoot = pSubL;
        }
        else
        {
            //说明子树原来pParent不是根节点，只是某个子树，那么就只需分两种情况
            if(pPParent->_pLeft == pParent)
            {
                pPParent->_pLeft = pSubL;
            }
            else
            {
                pPParent->_pRight = pSubL;
            }
        }

        //更新平衡因子
        pParent->_bf = pSubL->_bf = 0;
    }

    //左单旋
    void RotateL(Node* pParent)
    {
        Node* pSubR = pParent->_pRight;
        Node* pSubRL = pSubR->_pLeft;

        pParent->_pRight = pSubRL;
        if(pSubRL)
        {
            pSubRL->_pParent = pParent;
        }

        pSubR->_pLeft = pParent;
        Node* pPParent = pParent->_pParent;
        pSubR->_pParent = pPParent;
        pParent->_pParent = pSubR;

        if(pPParent == nullptr)
        {
            _pRoot = pSubR;
        }
        else
        {
            if(pPParent->_pLeft == pParent)
            {
                pPParent->_pLeft = pSubR;
            }
            else
            {
                pPParent->_pRight = pSubR;
            }
        }

        pParent->_bf = pSubR->_bf = 0;
    }

    //右左双旋
    void RotateRL(Node* pParent)
    {
        //保存调整前的平衡因子，方便更新
        Node* pSubR = pParent->_pRight;
        Node* pSubRL = pSubR->_pLeft;
        int bf = pSubRL->_bf;

        RotateR(pParent->_pRight);
        RotateL(pParent);

        //需要更新部分节点的平衡因子
        if(bf == 1)
        {
            pParent->_bf = -1;
        }
        else if(bf == -1)
        {
            pSubR->_bf = 1;
        }

    }

    //左右双旋
    void RotateLR(Node* pParent)
    {
        //保存调整前的平衡因子，方便更新
        Node* pSubL = pParent->_pLeft;
        Node* pSubLR = pSubL->_pRight;
        int bf = pSubLR->_bf;

        RotateL(pParent->_pLeft);
        RotateR(pParent);

        if(bf == 1)
        {
            pSubL->_bf = -1;
        }
        else if(bf == -1)
        {
            pParent->_bf = 1;
        }
    }

    //遍历
    void _Inorder(Node* pRoot)
    {
        if(pRoot)
        {
            _Inorder(pRoot->_pLeft);
            cout<<pRoot->_data<<" ";
            _Inorder(pRoot->_pRight);
        }
    }

    //检测
    bool _IsValidAVLTree(Node* pRoot)
    {
        if(nullptr == pRoot)
        {
            return true;
        }
        int leftHight = Hight(pRoot->_pLeft);
        int rightHight = Hight(pRoot->_pRight);
        int bf = rightHight - leftHight;

        if(abs(bf) <= 1 && bf == pRoot->_bf)
        {
            return _IsValidAVLTree(pRoot->_pLeft)&&
                _IsValidAVLTree(pRoot->_pRight);
        }
        else 
        {
            return false;
        }
    }

    int Hight(Node* pRoot)
    {
        if(pRoot == nullptr)
        {
            return 0;
        }

        int leftHight = Hight(pRoot->_pLeft);
        int rightHight = Hight(pRoot->_pRight);

        return leftHight > rightHight ? leftHight + 1 : rightHight + 1;
    }

    void Destory(Node* pRoot)
    {
        if(pRoot)
        {
            Destory(pRoot->_pLeft);
            Destory(pRoot->_pRight);
            delete pRoot;
            pRoot = nullptr;
        }
    }

    private:

    Node* _pRoot;
};

//AVL树的构建步骤：
//1.插入节点：a.是第一次插入，把插入节点作为根结点；b.不是第一次插入节点，请看第2步
//2.调节平衡因子：插入节点后，树的结构并没有被破坏，但是需要注意向上调节平衡因子
//3.树的结构被破坏，需要进行旋转：
//4.旋转：单旋，双旋;注意单旋和和双旋平衡因子的调整问题
