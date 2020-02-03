#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdlib.h>
using namespace std;

template<class T>
bool IsEqual(T left,T right)
{
  return left == right;
}

void Func1()
{
  cout<<"4 == 4 : ? "<<IsEqual(4,4)<<endl;
  cout<<"a == a : ? "<<IsEqual('a','a')<<endl;
  cout<<"hello == hello : ? "<<IsEqual("hello","hello")<<endl;
  const char* p1 = "hello";
  const char* p2 = "hello";//可以直接用 == 判断字符串相等了？？？？？？
  if(IsEqual(p1,p2))
  {
    cout<<p1<<endl;
  }
  else
  {
    cout<<p2<<endl;
  }

  if(p1 == p2)
  {
    cout<<" == "<<p1<<endl;
  }
  else
  {
    cout<<" != "<<" p1: "<<p1<<" p2: "<<p2<<endl;
  }
}

//全特化
template<class T1,class T2>
class Date
{
  public:
  Date()
  {
    cout<<"this is Date(T1,T2)"<<endl;
  }
  private:
    T1 _d1;
    T2 _d2;
};

template<>
class Date<int,char>
{
  public:
    Date()
    {
      cout<<"this is Date<int,char>"<<endl;
    }
  private:
    int _d1;
    char _d2;
};

void Func2()
{
  Date<int,int> d1;
  Date<int,char> d2;
  Date<char,int> d3;
}

//通用的拷贝函数
template<class T>
void Copy( T* dst, T* src, size_t size, bool IsPODType)
{
  if(IsPODType)
    memcpy(dst, src, sizeof(T)*size);
  else
  {
    for(size_t i = 0; i < size; ++i)
      dst[i] = src[i];
  }
}

class Date1{};

void Func3()
{
  char* p1 = "hello wolf i am  guidao";
  char* p2;
  cout<<"p1: "<<p1<<endl;
  //Copy(p2,p1,strlen(p1),true);
  //cout<<"p2: "<<p2<<endl;
  cout<<typeid(Date1).name()<<endl;
}

//类型萃取
//
// 代表内置类型
 struct TrueType
 {
 static bool Get(){return true;}
 };
 // 代表自定义类型
 struct FalseType
 {
 static bool Get(){return false;}
 };

template<class T>
struct TypeTraits
{ typedef FalseType IsPODType;  };

template<>
struct TypeTraits<char>
{ typedef TrueType IsPODType; };
template<>
struct TypeTraits<short>
{ typedef TrueType IsPODType; };
template<>
struct TypeTraits<int>
{ typedef TrueType IsPODType;  };
template<>
struct TypeTraits<long>
{ typedef TrueType IsPODType;  };

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
  if(TypeTraits<T>::IsPODType::Get())
  {
    memcpy(dst, src, sizeof(T)*size);
    cout<<"this is truetype"<<endl;
  }
  else
  {
    for(size_t i = 0; i < size; ++i)
      dst[i] = src[i];
    cout<<"this is falsetype"<<endl;
  }
}
void Func4()
{
  int a1[] = {1,2,3,4,5,6,7,8,9,0};
  int a2[10];
  Copy(a2, a1, 10);
  string s1[] = {"1111", "2222", "3333", "4444"};
  string s2[4];
  Copy(s2, s1, 4);
}


int main()
{
  //Func1(); 
  //Func2(); 
  //Func3(); 
  Func4();

  return 0;
}
