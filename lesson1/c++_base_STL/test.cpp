#include <iostream>
using namespace std;

int Add(int left,int right)
{
  cout<<"this is int add(int,int)"<<endl;
  return left + right;
}

double Add(int left,double right)
{
  cout<<"this is double add(int,double)"<<endl;
  return left + right;
}

template<class T>
//template<typename T>
T Add(T left,T right)
{
  cout<<"this is STL Add(T,T)"<<endl;
  return left + right;
}

template<class T1,class T2>
T2 Add(T1 left,T2 right)
{
  cout<<"this is STL Add(T1,T2)"<<endl;
  return left + right;
}

void Func1()
{
  int a = 1;
  int b = 2;
  double c = 3.0;
  double d = 4.0;
  char e = 'e';
  char f = 'f';

  //函数在编译阶段根据传入的实参类型来推演生成对应类型的函数代码以供调用，
  //不同的类型推演出来的函数代码是不一样的，各自有一份专门处理对应类型的代码，不在同一个函数地址
  //即如果传入类型是int型，就生成一份int型代码；如果传入double型，就生成double型代码
  cout<<Add(a,b)<<endl;
  cout<<Add(c,d)<<endl;
  cout<<Add((int)e,(int)f)<<endl;

  //注意隐式实例化的模板参数一般不进行类型转化
  //Add(a,c);//这样就会报错,解决方法：1.用户自己强转；2.显式实例化
  cout<<Add(a,(int)c)<<endl; 
  cout<<Add<int>(a,c)<<endl;

}


void Func2()
{
  //测试模板的调用规则，优先调用用户自己写的匹配函数，如果用户没有提供对应类型的函数则再去调用STL生成
  //对应类型的函数，如果STL可以生成比用户自定义的函数类型更加匹配就优先调用STL进行生成对应类型的函数
  int a1 = 1;
  int a2 = 2;
  double b1 = 11.1;
  double b2 = 22.2;

  Add(a1,a2);
  Add(b1,b2);
  Add(a1,b1);
  Add(b1,a1);
}

int main()
{
  //Func1();
  Func2();
  return 0;
}
