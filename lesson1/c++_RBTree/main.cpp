#include "RBTree.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    RBTree<int> rb;
    rb.Insert(5);
    rb.Insert(8);
    rb.Insert(16);
    rb.Insert(0);
    cout<<rb.IsValidRBTree()<<endl;;

    return 0;
}
