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
    }

    //关键字，就是存储的数据
    K _key[M];

    //指向孩子节点的指针
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
    typedef Node* pNode;
    
    public:
    BTree()
        :_pRoot(NULL)
    {}

    bool Insert(K& key)
    {
        if (_pRoot == NULL)     //无根节点
        {
            _pRoot = new Node();
            _pRoot->_key[0] = key;
            _pRoot->_size = 1;
            return true;
        }

        pair<pNode, int> ret = Find(key);
        if (ret.second >= 0)
            return false;
        pNode pCur = ret.first;
        pNode pSub = NULL;
        while (1)
        {
            _Insert(pCur, key, pSub);
            size_t size = pCur->_size;
            if (size < M)
                return true;
            else
            {
                size_t mid = size >> 1;
                pNode tmp = new Node();
                for (size_t i= mid + 1; i < size; i++)
                {
                    tmp->_key[tmp->_size] = pCur->_key[i];
                    tmp->_pSub[tmp->_size] = pCur->_pSub[i];
                    if (tmp->_pSub[tmp->_size])
                        tmp->_pSub[tmp->_size]->_pParent = tmp;
                    tmp->_size++;
                }
                tmp->_pSub[tmp->_size] = pCur->_pSub[pCur->_size];

                if (tmp->_pSub[tmp->_size])
                    tmp->_pSub[tmp->_size]->_pParent = tmp;
                pCur->_size -= (tmp->_size + 1);//处理size

                if (pCur == _pRoot)//如果当前结点是根结点，还需要再处理
                {
                    _pRoot = new Node;
                    _pRoot->_key[0] = pCur->_key[mid];
                    _pRoot->_pSub[0] = pCur;
                    pCur->_pParent = _pRoot;
                    _pRoot->_pSub[1] = tmp;
                    tmp->_pParent = _pRoot;
                    _pRoot->_size = 1;
                    return true;
                }
                else
                {
                    key = pCur->_key[mid];
                    pCur = pCur->_pParent;
                    pSub = tmp;
                }
            }
        }
    }

    pair<pNode, int> Find(const K& key)
    {
        pNode pCur = _pRoot;
        pNode pParent = NULL;

        while (pCur)
        {
            size_t i = 0;
            while (i < pCur->_size)
            {
                if (key == pCur->_key[i])
                    return pair<pNode, int>(pCur, i);
                else if (key < pCur->_key[i])
                    break;
                else
                    i++;
            }
            pParent = pCur;
            pCur = pCur->_pSub[i];
        }
        return make_pair(pParent, -1);//没找到返回-1
    }
    private:
    void _Insert(pNode pCur, const K& key, pNode pSub)
    {
        //直接插入的思想
        int end = pCur->_size - 1;
        while (key < pCur->_key[end] && end >= 0)
        {
            pCur->_key[end + 1] = pCur->_key[end];
            pCur->_pSub[end + 2] = pCur->_pSub[end + 1];
            end--;
        }

        pCur->_key[end + 1] = key;
        pCur->_pSub[end + 2] = pSub;
        if (pSub)
            pSub->_pParent = pCur;
        pCur->_size += 1;
    }
    private:
    Node *_pRoot;
};

//int main()
//{
//    int arr[] = { 53, 75, 139, 49, 145, 36, 101 };
//    BTree<int> b;
//    size_t size = sizeof(arr) / sizeof(arr[0]);
//    for (size_t i = 0; i < 7; i++)
//        b.Insert(arr[i]);
//
//    system("pause");
//    return 0;
//}
