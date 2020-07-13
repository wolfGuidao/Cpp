#include <bits/stdc++.h>
using namespace std;


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
            while(_arr[x] > 0)
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

