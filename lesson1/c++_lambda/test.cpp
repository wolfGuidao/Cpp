#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void Func1()
{
  int a = 4;
  auto func = [&a]{return a + 3;};
  //cout<<func()<<endl;
  
  int b = 5;
  auto func1 = [&](int c){return c + b;};
  //cout<<func1(10)<<endl;
  
  auto func2 = [&](int c)->int{return b += c;};
  //cout<<func2(10)<<" "<<b<<endl;//并不改变b的值
  
  int x = 10;
  auto func3 = [x](int a)mutable{x *= 2;return a + x;};
  cout<<func3(2)<<" "<<x<<endl;
}

void Func2()
{
  vector<int> v1 = {2,1,4,7,3,8,0,1,4};
  for_each(v1.begin(),v1.end(),[](int val){
      cout<<" val: "<<val * 2;
      });
  cout<<endl;
}

int main()
{
  //Func1();
  Func2();
  return 0;
}
