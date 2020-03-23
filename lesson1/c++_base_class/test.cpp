#include <iostream>
using namespace std;

//注意类的大小计算方法
class fun1
{
  public:
    void f()
    {
      cout<<this<<" "<<_a<<" "<<endl;
    }

    void f1()
    {
      cout<<"test this is nullptr"<<endl;
    }
  private:
    int _a = 999;
};

class fun2
{
public:
  fun2()
  {

  }

  fun2(int a,int b)
    :_a(a)
     ,_b(b)
  {

  }

  //自定义的无参构造函数、全缺省的构造函数、编译器生成的构造函数都是默认构造函数 
  //默认构造函数只能有一个
  //fun2(int a = 1,int b = 2)
  //{

  //}
  
  //既可以访问static修饰的成员变量也可以访问非static修饰的成员变量
  void Get1()
  {
    cout<<_a<<" "<<_b<<" "<<_c<<endl;
  }

  //static修饰的成员函数不能访问非static的成员变量，只能访问static修饰的成员变量
  //static void Get2()
  //{
  //  cout<<_a<<" "<<_b<<" "<<_c<<endl;
  //}
private:
  int _a;
  int _b;
  static int _c;
};

int fun2::_c = 99;

void func1()
{
  cout<<sizeof(fun1)<<endl;

  fun1 f1;
  f1.f();

  //this指针为空
  fun1* f2 = nullptr;
  //访问类中的成员变量会出错
  //f2->f();
  //不访问类中的成员变量不会出错
  f2->f1();

  fun1* f3 = new fun1;
  f3->f();
  f3->f1();
}

void func2()
{
  cout<<sizeof(fun2)<<endl;
}

class Time
{
  public:
    friend class Date;
  private:
    int _h;
    int _m;
    int _s;
};

class Date
{
  friend ostream& operator<<(ostream& _cout,const Date& d);
  friend istream& operator>>(istream& _cin, Date& d);

  friend void Getcount(Date& d);
  public:
    Date(int year,int month,int day)
      :_year(year)
       ,_month(month)
       ,_day(day)
  {}

  void SetTime(int h,int m,int s)
  {
    _t._h = h;
    _t._m = m;
    _t._s = s;
    cout<<_t._h<<":"<<_t._m<<":"<<_t._s<<endl;
  }

  private:
    int _year;
    int _month;
    int _day;
    Time _t;
};

ostream& operator<<(ostream& _cout,const Date& d)
{
  _cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
  return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
  _cin>>d._year;
  _cin>>d._month;
  _cin>>d._day;
  return _cin;
}

void Getcount(Date& d)//友元函数也不能用cosnt修饰
{
  //cout<<this<<endl;//不是类的成员函数，没有this指针
  cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
}

void func3()
{
  Date d(2020,1,2);
  cin>>d;
  cout<<d;
  Getcount(d);
  d.SetTime(24,11,11);
  
}

int main()
{
  //func1();
  //func2();
  func3();
  return 0;
}
