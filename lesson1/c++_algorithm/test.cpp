#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Mul2
{
  public:
    void operator()(int& data)
    {
      data <<= 1;
    }
};

class Mod3
{
  public:
    bool operator()(int data)
    {
      return 0 == data % 3;
    }
};

class Test
{
  public:
    int operator()(int data)
    {
      return data + 2;
    }
};

void Func1()
{
  vector<int> v{1,2,3,4,5,6,7,8,9,0};
  for_each(v.begin(),v.end(),Mul2());

  for(auto e : v)
  {
    cout<<e<<" ";
  }
  cout<<endl;

  auto pos = remove_if(v.begin(),v.end(),Mod3());
  v.erase(pos,v.end());

  for_each(v.begin(),v.end(),[](int data){cout<<data<<" ";});
  cout<<endl;

  Test test;
  cout<<test.operator()(9)<<endl;
  cout<<test(10)<<endl;

}

class Less
{
  public:
    void operator()(int val)
    {
       cout<<"this is algorithm: "<<val<<endl;
    }
};

void Func2()
{
  vector<int> vv = {1,2,3,4,5,6,7,8,9,0};
  for(auto e : vv)
  {
    Less l;
    l(e);
  }
}

int main()
{
  //Func1();
  Func2();
  return 0;
}
