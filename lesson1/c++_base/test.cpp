#include <iostream>
using namespace std;

int Add(int a,int b)
{
  return a + b;
}

double Add(double a,double b)
{
  return a + b;
}

//const 构成函数重载待定
//int Add(int a,int b)const
//{
//  return a + b;
//}
//
//const int Add(const int a,const int b)
//{
//  return a + b;
//}


//缺省参数不构成函数重载
//void TestFun(int a = 10)
//{
//  cout<<"TestFun(int (a))"<<a<<endl;
//}
//
//void TestFun(int a)
//{
//  cout<<"TestFun"<<endl;
//}


//测试函数重载
void Func1()
{
  cout<<Add(1,2)<<endl;
  cout<<Add(3.0,4.0)<<endl;
  //cout<<sum(1,2)<<endl;
}

int& TestRefReturn(int& a)
{
  a += 10;
  return a;
}

int & TestRefReturn1(int a,int b)
{
  //栈空间的引用，会出错
  int c = a + b;
  return c;
}

struct A
{
  int a[10000];
};

void Test1(A a)
{

}

void Test2(A& a)
{

}

void Test3(A* a)
{

}


//测试引用
void Func2()
{
  //引用一旦引用一个实体后就不能再引用其他实体
  //说明引用底层是和指针常量一样,即:int* const eg;
  
  //cosnt类型的引用可以引用既可以引用const型变量也可以引用非condt型引用
  //非const类型的引用只可以引用非const型引用
  int a = 5;
  const int b = 6;

  int& ra = a;
  const int& rra = a;

  //int& rb = b;
  const int& rrb = b;


  //注意以引用作为返回值的区别
  
  //不能返回栈上的空间（函数内的局部变量）
  //如果要以引用做返回值，需要返回的变量不受函数控制，即函数结束该变量的生命周期依然存在
  
  cout<<TestRefReturn(a)<<endl;
  //cout<<TestRefReturn1(a,b)<<endl;//以引用作为返回值返回栈上的变量，报段错误
  
  //传值、传引用、传指针的效率
  A test;
  size_t begin1 = clock();
  for(size_t i = 0;i < 10000; ++i)
  {
    Test1(test);
  }
  size_t end1 = clock();
  cout<<"Test1:"<<end1 - begin1<<endl;

  size_t begin2 = clock();
  for(size_t i = 0;i < 10000; ++i)
  {
    Test2(test);
  }
  size_t end2 = clock();
  cout<<"Test2:"<<end2 - begin2<<endl;

  size_t begin3 = clock();
  for(size_t i = 0;i < 10000; ++i)
  {
    Test3(&test);
  }
  size_t end3 = clock();
  cout<<"Test3:"<<end3 - begin3<<endl;
}

void f(int)
{
  cout<<"f(int)"<<endl;
}

void f(int*)
{
  cout<<"f(int*)"<<endl;
}

void Func3()
{
  f(0);
  //f(NULL);//有歧义
  f((int*)NULL);
  f(nullptr);
}

int main()
{
  //Func1();
  //Func2();
  Func3();
  return 0;
}
