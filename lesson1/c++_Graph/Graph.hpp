/*************************************************************************
# File Name: Graph.hpp
# Author: wolf
# Mail: wolfguidao@163.com 
# Created Time: 2020年07月18日 星期六 12时23分37秒
 *************************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

namespace matrix 
{

    template<class V,class W,bool D = false>
        class Graph 
        {
            public:
                Graph(const V* a,int n)
                {
                    _vertexs.reserve(n);
                    _edge.resize(n);
                    for(int i = 0;i < n;i++)
                    {
                        _edge[i].resize(n,W());
                        _vertexs.push_back(a[i]);
                        _vertexsIndexMap[a[i]] = i;
                    }
                }

                void AddEdge(const V& src,const V& dest,const W& w)
                {
                    int srcIndex;
                    int descIndex;
                    try 
                    {
                        srcIndex = GetVertexsIndex(src);
                        descIndex = GetVertexsIndex(dest);
                    }
                    catch(string er)
                    {
                        cout<<"非法顶点"<<endl;
                        exit(1);
                    }

                    _edge[srcIndex][descIndex] = w;
                    if(false == D)
                    {
                        _edge[descIndex][srcIndex] = w;
                    }
                }

                void DFS(const V& src)
                {
                    int srcIndex;
                    try 
                    {
                        srcIndex = GetVertexsIndex(src);
                    }
                    catch(string ex)
                    {
                        cout<<ex<<endl;
                        exit(1);
                    }

                    vector<bool> visted(_vertexs.size(),false);
                    _DFS(srcIndex,visted);
                    cout<<endl;
                }

                void BFS(const V& src)
                {
                    int srcIndex;
                    try 
                    {
                        srcIndex = GetVertexsIndex(src);
                    }
                    catch(string ex)
                    {
                        cout<<ex<<endl;
                        exit(1);
                    }

                    vector<bool> visted(_vertexs.size(),false);

                    queue<int> q;

                    q.push(srcIndex);
                    visted[srcIndex] = true;

                    while(!q.empty())
                    {
                        int front = q.front();
                        q.pop();
                        cout<<front<<" : "<<_vertexs[front]<<" ";

                        for(int i = 0;i < _edge[front].size();i++)
                        {
                            if(_edge[front][i] != W() && visted[i] == false)
                            {
                                q.push(i);
                                visted[i] = true;
                            }
                        }
                    }
                    cout<<endl;
                }

                void Print()
                {
                    for(int i = 0;i < _edge.size();i++)
                    {
                        cout<<"[";
                        for(int j = 0;j < _edge[0].size();j++)
                        {
                            cout<<_edge[i][j]<<" ";
                        }
                        cout<<"]"<<endl;
                    }
                }

            private:
                void _DFS(int srcIndex,vector<bool> visted)
                {
                    visted[srcIndex] = true;
                    cout<<srcIndex<<" : "<<_vertexs[srcIndex]<<" -> ";
                    for(int i = 0;i < _edge[srcIndex].size();i++)
                    {
                        if(_edge[srcIndex][i] != W() && visted[i] == false)
                        {
                            _DFS(i,visted);
                        }
                    }
                }

                int GetVertexsIndex(const V& v)
                {
                    //for(size_t i = 0;i < _vertexs.size();i++)
                    //{
                    //    if(_vertexs[i] == v)
                    //    {
                    //        return i;
                    //    }
                    //}

                    //throw string("非法顶点");

                    if(_vertexsIndexMap.find(v) != _vertexsIndexMap.end())
                    {
                        return _vertexsIndexMap[v];
                    }
                    else 
                    {
                        throw string("非法顶点");
                        //return -1;
                    }
                }

            private:
                //顶点的集合
                vector<V> _vertexs;

                //边的集合：邻接矩阵
                vector<vector<W>> _edge;

                //通过顶点找下标；保存映射关系
                unordered_map<V,int> _vertexsIndexMap;        
        };//end of class Graph 
}//end of namespace matrix 

namespace linktable 
{
    template<class W>
        struct LinkEdge
        {
            LinkEdge(const int& src,const int& dest,const W& w)
                :_src(src)
                 ,_dest(dest)
                 ,_w(w)
                 ,_next(nullptr)
            {

            }

            int _src;
            int _dest;
            W _w;
            LinkEdge<W>* _next;
        };

    template<class V,class W,bool D = false>
        class Graph 
        {
            typedef LinkEdge<W> Edge;
            public:
            Graph(const V* a,int n)
            {
                _vertexs.reserve(n);
                _linktable.resize(n,nullptr);

                for(int i = 0;i < n;i++)
                {
                    _vertexs.push_back(a[i]);
                    _vertexsIndexMap[a[i]] = i;
                }
            }

            void AddEdge(const V& src,const V& dest,const W& w)
            {
                int srcIndex;
                int descIndex;
                try 
                {
                    srcIndex = GetVertexsIndex(src);
                    descIndex = GetVertexsIndex(dest);
                }
                catch(string ex)
                {
                    cout<<"非法边界"<<endl;
                    exit(1);
                }

                _AddEdge(srcIndex,descIndex,w);
                if(false == D)
                {
                    _AddEdge(descIndex,srcIndex,w);
                }
            }

            void Print()
            {
                for(size_t i = 0;i < _linktable.size();i++)
                {
                    Edge* cur = _linktable[i];
                    while(cur)
                    {
                        cout<<i<<" : "<<" src: "<<cur->_src<<" dest: "<<cur->_dest<<" w: "<<cur->_w<<"       ";                        
                        cur = cur->_next;
                    }
                    cout<<endl;
                }
            }

            private:
            void _AddEdge(const int srcIndex,const int destIndex,const W& w)
            {
                Edge* edge = new Edge(srcIndex,destIndex,w);

                edge->_next = _linktable[srcIndex];
                _linktable[srcIndex] = edge;
            }

            int GetVertexsIndex(const V& v)
            {
                if(_vertexsIndexMap.find(v) != _vertexsIndexMap.end())
                {
                    return _vertexsIndexMap[v];
                }
                else 
                {
                    throw string("非法顶点");
                    //return -1;
                }
            }

            private:
            vector<V> _vertexs;

            //边的集合：邻接表
            vector<Edge*> _linktable;

            unordered_map<V,int> _vertexsIndexMap;
        };//end if class Graph
}//end of namespace linktable 

