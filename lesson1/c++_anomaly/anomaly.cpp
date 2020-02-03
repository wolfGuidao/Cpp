#include<iostream>
using namespace std;

//多态的条件：
//1.在继承体系下
//2.必须通过基类的 指针或者引用 来调用虚函数
//3.被调用的函数必须是虚函数且派生类必须对基类对应的虚函数进行重写（注意重写的要求，及特例协变和析构）

class Person 
{
  public:
    Person()
    {
      cout<<"this is Person!"<<endl;
    }

    //基类虚函数
    virtual void BuyTicket() 
    { 
      cout << "this is Person!!!" << endl;
    }

    virtual ~Person()
    {
      cout<<"this is ~Person!"<<endl;
    }

};

//继承体系下
class Student : public Person 
{
  public:
    Student()
    {
      cout<<"this is Student!"<<endl;
    }

    //派生类重写基类的虚函数
    virtual void BuyTicket() 
    { 
      cout << "this is Student!!!" << endl;
    }

    virtual ~Student()
    {
      cout<<"this is ~Student!"<<endl;
    }
};

//基类的指针或引用
void Func(Person& p)
{ 
  p.BuyTicket();  
}

//所以构成多态
//原理是：
//1.首先只要一个类中有虚函数,那么该类就会默认生成一个指针，叫虚函数指针，指向一张表，叫虚函数表，表中
//存放的内容是该类的虚函数地址
//2.在继承体系下，如果构成多态，那么基类首先根据类中虚函数的声明次序依次把虚函数地址放到虚函数表中，
//在派生类中，首先派生类先拷贝一份基类的虚函数表，如果构成多态，那么派生类肯定重写了基类的某个虚函数，那么
//就把派生类重写基类的虚函数地址替换虚函数表中相同偏移量位置处的虚函数地址，以此类推，完成派生类的
//虚函数表的构造
//3.在调用过程中，因为是基类的指针或引用，那么该指针或引用既可以指向基类，也可以指向派生类，所以，如果传递
//的参数是基类的对象，那么就相当于基类的指针指向基类的对象，在函数运行期间，就去基类的虚函数表中调用虚函数，
//如果传递的参数是派生类的对象，那么就相当于基类的指针指向派生类的对象（派生类中的基类部分），那么函数在运行
//期间就去派生类的虚函数表汇中调用虚函数，因为上面已经重写过虚函数，所以虚函数执行的结果是可以不一样的，
//也就构成了多态，根据参数的不同，从而执行不同的代码片段

void Func1()
{
  Person ps;
  Student st;
  Func(ps);
  Func(st);

  cout<<sizeof(Person)<<endl;
}

void Func2()
{
  Person* p1 = new Person;
  Person* p2 = new Student;
  delete p1;
  delete p2;

  cout<<"sizeof A: "<<sizeof(Person)<<" sizeof B: "<<sizeof(Student)<<endl;
}

class Base {
  public :
    virtual void func1() { cout<<"Base::func1" <<endl; }
    virtual void func2() {cout<<"Base::func2" <<endl;}
  private :
    int a;

};


class Derive :public Base {
  public :
    virtual void func1() {cout<<"Derive::func1" <<endl;}
    virtual void func3() {cout<<"Derive::func3" <<endl;}
    virtual void func4() {cout<<"Derive::func4" <<endl;}
  private :
    int b;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
  // 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
   cout << " 虚表地址>" << vTable << endl;
   for (int i = 0; vTable[i] != nullptr; ++i)
   {
      printf(" 第%d个虚函数地址 :0X%p,->", i, vTable[i]);
      VFPTR f = vTable[i];
      f();
   }
   cout << endl;
   
 }

void Func3()
{
  Base b;
  Derive d;
  VFPTR* vTableb = (VFPTR*)(*(int*)&b);
  PrintVTable(vTableb);
  VFPTR* vTabled = (VFPTR*)(*(int*)&d);
  PrintVTable(vTabled);
}

class Base1 {
  public:
    virtual void func1() {cout << "Base1::func1" << endl;}
    virtual void func2() {cout << "Base1::func2" << endl;}
  private:
    int b1;

};
class Base2 {
  public:
    virtual void func1() {cout << "Base2::func1" << endl;}
    virtual void func2() {cout << "Base2::func2" << endl;}
  private:
    int b2;

};

class Derive1 : public Base1, public Base2 {
  public:
    virtual void func1() {cout << "Derive::func1" << endl;}
    virtual void func3() {cout << "Derive::func3" << endl;}
  private:
    int d1;

};

void Func4()
{
  Derive1 d;
  Base1 b1;
  Base2 b2;

  VFPTR* vTableb3 = (VFPTR*)(*(int*)&b1);
  PrintVTable(vTableb3);

  VFPTR* vTableb4 = (VFPTR*)(*(int*)&b2);
  PrintVTable(vTableb4);

  VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
  PrintVTable(vTableb1);

  //在VS下运行
  VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
  PrintVTable(vTableb2);
  //cout<<"Base1:"<<sizeof(Base1)<<" Base2: "<<sizeof(Base2)<<" Derive1: "<<sizeof(Derive1)<<endl;
}

int main()
{
  //Func1();
  Func4();
  return 0;
}
