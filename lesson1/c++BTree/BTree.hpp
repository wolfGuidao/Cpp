#include<iostream>
using namespace std;

template<class K,int M = 3>
struct BTreeNode
{
    BTreeNode()
        :_pParent(NULL)
         , _size(0)
    {
        for (size_t i = 0; i <= M; i++)
        {
            _pSub[i] = NULL;
        }

        _pParent = NULL;

        _size = 0;
    }

    //关键字，就是存储的数据
    //多给一个空间是为了方便分裂，因为在插入的时候我们需要判断其位置进行分裂
    //少一个会越界访问；总结多给一个空间的目的是让其先插入进去，在进行分裂判断
    //如果不多个一个空间，那么如果判断需要分裂，那么关键字的位置就不好判断
    K _key[M];

    //指向孩子节点的指针
    //左孩子等于关键字的下标，右孩子是关键字下标 + 1
    BTreeNode<K, M> *_pSub[M + 1];

    //指向父亲节点的指针
    BTreeNode<K, M> *_pParent;

    //记录关键字的个数
    size_t _size;
};


template<class K,int M = 3>
class BTree
{
    typedef BTreeNode<K, M> Node;

    public:
    BTree()
        :_pRoot(NULL)
    {
    }

    bool Insert(K& key)
    {
        //还没有开始插入
        if (_pRoot == NULL)     //无根节点
        {
            _pRoot = new Node();
            _pRoot->_key[0] = key;
            _pRoot->_size = 1;
            return true;
        }

        //Find查找key关键字，判断是否已经存在
        pair<Node*, int> ret = Find(key);
        if (ret.second >= 0)
            return false;

        Node* pCur = ret.first;

        //保存孩子指针
        Node* pSub = NULL;
        while (1)
        {
            _Insert(pCur, key, pSub);
            size_t size = pCur->_size;
            //不需要分裂
            if (size < M)
            {
                return true;
            }
            //需要分裂
            else
            {
                //找到拷贝区间的分界线，即把mid右边的关键字拷走组成新节点
                size_t mid = size >> 1;

                //开始拷贝
                Node* tmp = new Node();
                for (size_t i = mid + 1;i < size;i++)
                {
                    //拷贝关键字
                    tmp->_key[tmp->_size] = pCur->_key[i];

                    //拷贝孩子指针
                    tmp->_pSub[tmp->_size] = pCur->_pSub[i];

                    //防止影响
                    pCur->_key[i] = K();
                    pCur->_pSub[i] = nullptr;

                    //更新指针指向
                    if (tmp->_pSub[tmp->_size])
                        tmp->_pSub[tmp->_size]->_pParent = tmp;

                    //一箭双雕：既是tmp的下标移动又是tmp节点的size大小
                    tmp->_size++;
                }

                //因为当i == size时，跳出循环，我们每次拷贝孩子指针时只拷贝了左孩子，
                //最后还剩下一个右孩子需要靠背
                tmp->_pSub[tmp->_size] = pCur->_pSub[pCur->_size];
                pCur->_pSub[pCur->_size] = nullptr;

                //同样更新指针指向
                if (tmp->_pSub[tmp->_size])
                    tmp->_pSub[tmp->_size]->_pParent = tmp;

                //改变pCur的size大小，因为其已经被拷贝一半元素出去了
                pCur->_size -= (tmp->_size + 1);

                //如果当前结点是根结点，还需要再处理
                if (pCur == _pRoot)//pCur ->_pParent == nullptr
                {
                    _pRoot = new Node;
                    
                    //把pcur当中mid位置的元素上移到新节点当中
                    _pRoot->_key[0] = pCur->_key[mid];

                    //更新孩子指针
                    _pRoot->_pSub[0] = pCur;
                    pCur->_pParent = _pRoot;

                    _pRoot->_pSub[1] = tmp;
                    tmp->_pParent = _pRoot;

                    //更新新根结点的size
                    _pRoot->_size = 1;
                    return true;
                }
                else
                {
                    //在父亲节点当中插入mid位置的关键字
                    key = pCur->_key[mid];
                    pCur = pCur->_pParent;

                    pSub = tmp;
                }
            }
        }
    }

    void Inorder()
    {
        _Inorder(_pRoot);
        cout<<endl;
    }

    //查找函数
    //查找关键字key的同时返回节点和下标
    pair<Node*, int> Find(const K& key)
    {
        Node* pCur = _pRoot;
        Node* pParent = NULL;

        //开始查找
        while (pCur)
        {
            size_t i = 0;
            while (i < pCur->_size)
            {
                //如果key == pCur->_key[i]，直接返回找到的节点和其对应的下标
                if (key == pCur->_key[i])
                    return pair<Node*, int>(pCur, i);
                //如果key 比pCur->_key[i]小,可以直接确定他在左孩子当中
                //直接break
                else if (key < pCur->_key[i])
                    break;
                //代表key 比pCur->_key[i]大，那么肯定在他的右边，注意注意注意：
                //不一定是pCur->_key[i]的右孩子，因为他是多叉树，需要继续往后判断
                else
                    i++;
            }

            //走到这里有两种情况：
            //1.i >= pCur->size 了：代表找完所有的_key[]数组，没找到比key大的关键字
            //那么就需要从最后一个关键字的右孩子递归往下找
            //2.break出来的：break出来的代表找到一个关键字比key大，那么就在该关键字的左孩子
            // 
            //关键字下标和孩子指针数足的下标关系：
            //_key[i]的左孩子等于_pSub[i];_key[i]的右孩子等于_pSub[i + 1];  
            // 
            //那么对于第一种情况，我们需要去最后一个关键字的右边，因为在循环内部已经把i++过了，
            //   所以pCur = pCur->_pSub[i];并不是i + 1
            //那么对于第二种情况，我们需要去i的左边，即：pCur = pCur->_pSub[i];
            pParent = pCur;
            pCur = pCur->_pSub[i];
        }
        //返回父亲节点和-1
        return make_pair(pParent, -1);//没找到返回-1
    }

    private:
    //插入函数，先不管是否需要分裂，先插进去，然后在考虑是否需要分裂
    // Node* pCur : 插入关键字位置的父亲指针；
    // const K& key：关键字；
    // Node* pSub：
    void _Insert(Node* pCur, const K& key, Node* pSub)
    {
        //直接插入排序的思想
        //因为end前的所有元素已经有序
        int end = pCur->_size - 1;
        while (key < pCur->_key[end] && end >= 0)
        {
            //搬移数据
            pCur->_key[end + 1] = pCur->_key[end];

            //搬移孩子指针
            pCur->_pSub[end + 2] = pCur->_pSub[end + 1];

            end--;
        }

        //代表找到合适的位置，插入即可
        pCur->_key[end + 1] = key;

        //放孩子指针
        pCur->_pSub[end + 2] = pSub;

        //更新指针指向
        if (pSub)
            pSub->_pParent = pCur;


        pCur->_size += 1;
    }

    void _Inorder(Node* root)
    {
        if(root == nullptr)
        {
            return ;
        }

        int i = 0;
        while(i < root->_size)
        {
            _Inorder(root->_pSub[i]);
            cout<<root->_key[i]<<" ";
            i++;
        }

        _Inorder(root->_pSub[i]);
    }

    private:
    Node *_pRoot;
};

