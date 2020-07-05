/*************************************************************************
  > File Name: main.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年07月05日 星期日 13时27分24秒
 ************************************************************************/

#include "BTree.hpp"


int main()
{
    int arr[] = { 53, 75, 139, 49, 145, 36, 101 };
    BTree<int> b;

    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        b.Insert(arr[i]);

    b.Inorder();
    return 0;
}
