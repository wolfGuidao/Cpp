#include<iostream>

using namespace std;

#if 0
class Base
{
  public:
  Base(int pri,int pro,int pub)
  {
    cout<<"this is Base"<<endl;
    _pri=pri;
    _pro=pro;
    _pub=pub;
  }

  void PrintBase()
  {
    cout<<_pri<<_pro<<_pub<<endl;
  }

  ~Base()
  {
    cout<<"this is ~Base"<<endl;
  }

  private:
    int _pri;
  protected:
    int _pro;
  public:
    int _pub;
};

//继承权限
class Derived : public  Base
{
  //访问权限，限制是否可以在类外访问
  public:
    Derived(int _a,int _b,int _c)
      :Base(_a,_b,_c)
    {
      cout<<"this is Derived"<<endl;
      a=_a;
      b=_b;
      c=_c;
    }
    void Print()
    {
      cout<<a<<b<<c<<endl;
      cout<<_pub<<endl;
      //cout<<_pri<<endl;//只有基类的私有成员不可以在类内访问
      cout<<_pro<<endl;
    }

    ~Derived()
    {
      cout<<"this is ~Derived"<<endl;
    }

  public:
    int a;
  protected:
    int b;
  private:
    int c;
};

void Func1()
{
  //验证继承
  Derived d(10,20,30);
  cout<<sizeof(Derived)<<endl;
  d.PrintBase();
  cout<<d.a;//类中公有成员可以在类外访问
  //cout<<d.b;//类中保护成员不可以在类外访问
  // cout<<d.c;//类中私有成员不可以在类外访问
  //cout<<d._pri;//继承体系基类中私有成员不可以在类外访问
  //cout<<d._pro;继承体系基类中保护成员不可以在类外访问
  cout<<d._pub;//继承体系基类中共有成员可以在类外访问
}

void Func2()
{
  //Derived a(10,20,30);
  //a.PrintBase();
  //cout<<"Base: "<<sizeof(Base)<<" Derived: "<<sizeof(Derived)<<endl;
  
  Derived a1(10,20,30);
  
  //基类的 对象/引用/指针 ‘指向’派生类后只能访问属于基类的部分，访问不到派生类的成员
  Base b1 = a1;
  Base& b2 = a1;
  Base* b3 = &a1;

  b1.PrintBase();
  b2.PrintBase();
  b3->PrintBase();

  Base* b4 = new Derived(10,20,30); 
  //b4->Print();//出错
  //b4->a;
  b4->_pub;
  
  //基类的对象不能赋值给派生类对象

  //基类的指针可以通过强制转化赋值给派生类
  Derived* a2 = (Derived*)b3;
  a2->Print();

  //注意
  Derived* a3 = (Derived*)&b1;//可能有内存越界问题
  a3->Print();

  Base b5(10,20,30);
  //Derived* a4 = (Derived*)b5;//这种强转是错误的
}

class A
{
  public:

    friend void Print();

    void fun()
    {
      cout<<"this is A::fun()"<<endl;
    }

    static int sta;//静态成员可以继承，但是整个继承体系中只有一份，地址是一样的

  private:

    int a;
};

int A::sta = 999;

class B : public A
{
  public:
    void fun()
    {
      cout<<"this is B::fun()"<<endl;
    }

  private:

    int b;
};

void Print()
{
  cout<<"this is test friend"<<endl;
  A a1;
  a1.a;

  B b1;
  //b1.b;//友元不能继承
}

void Func3()
{
  B b1;
  b1.fun();

  A* a1 = &b1;
  a1->fun();
  A& a2 = b1;
  a2.fun();
  A a3 = b1;
  a3.fun();

  B* b2 = (B*)a1;
  b2->fun();
  
  B* b3 = (B*)&a3;
  b3->fun();

  b1.A::fun();


  cout<<"this is test static: "<<a3.sta<<endl;;
  cout<<"test static A& : "<<&a3.sta<<" B& : "<<&b1.sta<<endl;
}

#endif

class A
{
  public:
    int _a;
};

//class B : public A
class B : virtual public A
{
public:
int _b;
};

// class C : public A
class C : virtual  public A
{
public:
int _c;
};

class D : public B, public C
{
public:
int _d;
};

void Func4()
{
  B b;
  C c;
  D d;
  d.B::_a = 1;
  d.C::_a = 2;//采用虚拟继承后，在派生类中，最基类的变量只存一份，如果发生修该，结果会覆盖
  d._b = 3;
  d._c = 4;
  d._d = 5;
  cout<<"d.B::_a = 1 "<<d.B::_a<<" d.C::_a = 2 "<<d.C::_a<<endl;

  cout<<"sizeof: "<<" A: "<<sizeof(A)<<" B: "<<sizeof(B)<<" C: "<<sizeof(C)<<" D: "<<sizeof(D)<<endl;

  int* str = (int*)&b;
  cout<<*str<<endl;

  //cout<<d._a<<endl;//整个对象模型中只有一份，就解决了菱形继承的冗余和二义性
}
int main()
{
  //Func3();
  Func4();
  return 0;
}
