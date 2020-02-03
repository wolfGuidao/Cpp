#include "vector.hpp"
#include <iostream>
#include <algorithm>
#include <string>

//void Func1()
//{
//  wolf::vector<int> v1(5,1);
//  v1.Print();
//
//  cout<<"size: "<<v1.size()<<" capacity: "<<v1.capacity()<<endl;
//
//  string s1("wolf guidao");
//  wolf::vector<string> v2(1,s1);
//  v2.Print();
//
//  int arr[] = {1,2,3,4,5,6,7,8,9,0};
//  wolf::vector<int> v3(arr,arr + 3);
//  v3.Print();
//  wolf::vector<char> v4(s1.begin(),s1.end());
//  v4.Print();
//
//  wolf::vector<int> v5;
//  v5.reserve(5);
//  cout<<"size: "<<v5.size()<<" capacity: "<<v5.capacity()<<endl;
//  v5.reserve(15);
//  cout<<"size: "<<v5.size()<<" capacity: "<<v5.capacity()<<endl;
//  v5.reserve(30);
//  cout<<"size: "<<v5.size()<<" capacity: "<<v5.capacity()<<endl;
//  v5.resize(29,1);
//  v5.Print();
//  cout<<"size: "<<v5.size()<<" capacity: "<<v5.capacity()<<endl;
//  v5.push_back(2);
//  v5.push_back(3);
//  cout<<"size: "<<v5.size()<<" capacity: "<<v5.capacity()<<endl;
//  v5.Print();
//}
//
//void Func2()
//{
//  wolf::vector<int> v1(5,1);
//  wolf::vector<int> v2(v1);
//  v1.Print();
//  v2.Print();
//  cout<<"v1 -> size: "<<v1.size()<<" capcacity: "<<v1.capacity()<<endl;
//  cout<<"v2 -> size: "<<v2.size()<<" capcacity: "<<v2.capacity()<<endl;
//  wolf::vector<int> v3;
//  v3 = v2;
//  v3.Print();
//  cout<<"v3 -> size: "<<v3.size()<<" capcacity: "<<v3.capacity()<<endl;
//  v3.insert(v3.begin() + 2,2);
//  v3.Print();
//  //v3.insert(v3.end() + 1,999);
//  v3.erase(v3.begin() + 2);
//  v3.Print();
//  v3.erase(v3.end() - 1);
//  v3.Print();
//  v3[0] = 99;
//  v3[1] = 999;
//  v3.Print();
//
//}
//
//void Func3()
//{
//  wolf::vector<wolf::vector<int>> vv;
//  wolf::vector<int> v1(5,1);
//  wolf::vector<int> v2(5,2);
//  wolf::vector<int> v3(5,3);
//  wolf::vector<int> v4(5,4);
//  vv.push_back(v1);
//  vv.push_back(v2);
//  vv.push_back(v3);
//  vv.push_back(v4);
//  for(auto it : vv)
//  {
//    for(auto e : it)
//    {
//      cout<<e<<" ";
//    }
//    cout<<endl;
//  }
//

typedef struct testsort
{
  const char* name;
  int less;
}testsort;

void Sort(testsort* arr,int len)
{
  for(int i = 1;i < len;i++)
  {
    for(int j = 0;j < len - i;j++)
    {
      if(arr[j].less > arr[j + 1].less)
      {
        testsort temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void Func4()
{
  testsort s1 = {"s1",90};
  testsort s2 = {"s2",60};
  testsort s3 = {"s3",80};
  testsort s4 = {"s4",30};
  testsort s5 = {"s5",10};

  testsort arr[] {s1,s2,s3,s4,s5};

  Sort(arr,5);
  //sort(arr,arr + sizeof(arr) / sizeof(testsort));
  
  for(int i = 0;i < 5;i++)
  {
    cout<<" name: "<<arr[i].name<<" less: "<<arr[i].less;
  }
  cout<<endl;

}

//注意迭代器失效问题
//void Func5()
//{
//  //杨辉三角
//  
//  int num;
//  cin>>num;
//
//  wolf::vector<wolf::vector<int>> vv;
//  wolf::vector<int> v;
//
//  vv.resize(num);
//  for(int i = 0;i < num;i++)
//  {
//    vv[i].resize(i + 1,0);
//    vv[i][0] = 1;
//    vv[i][i] = 1;
//  }
//
//  for(int i = 0;i < vv.size();i++)
//  {
//    for(int j = 0;j < vv[i].size();j++)
//    {
//      if(vv[i][j] == 0)
//      {
//        vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//      }
//    }
//  }
//
//  for(auto it : vv)
//  {
//    for(auto e : it)
//    {
//      cout<<e<<"  ";
//    }
//    cout<<endl;
//  }
//
//}

int main()
{
  //Func1();
  //Func2();
  //Func3();
  Func4();
  //Func5();
  return 0;
}
