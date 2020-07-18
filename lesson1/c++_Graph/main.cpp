/*************************************************************************
# File Name: main.cpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月18日 星期六 12时52分55秒
*************************************************************************/
#include "Graph.hpp"

int main()
{
    string a[4] = {"a","b","c","d"};
    matrix::Graph<string,int> graph(a,4);
    //linktable::Graph<string,int> graph(a,4);
    graph.AddEdge("a","b",999);
    graph.AddEdge("c","d",666);
    graph.DFS("a");
    return 0;
}
