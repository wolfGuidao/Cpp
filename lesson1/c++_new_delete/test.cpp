#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

//new --> operator new --> malloc
//delete --> operator delete --> free
class Test
{
  public:
    Test()
    {
      cout<<"this is Test()"<<endl;
    }

    ~Test()
    {
      cout<<"this is ~Test()"<<endl;
    }
};

void Func1()
{
  //注意new/delete和malloc/free的区别
  Test* t1 = new Test;
  delete t1;

  Test* t2 = (Test*)malloc(sizeof(Test));
  free(t2);
}

//设计一个类只在堆上创建对象
//屏蔽掉构造函数和拷贝构造函数，提供一个共有在堆上创建对象的方法
class HeapOnly
{
  public://static的目的是因为：构造函数和拷贝构造函数都是私有的，无法创建普通对象，如果不加static就无法
    //在类外访问该函数进行在堆上创建对象，加上static就可以直接用类名::来访问
    static HeapOnly* Create()
    {
      return new HeapOnly;
    }
  private://私有化的目的是防止用户自己再类外实现构造和拷贝构造
    //c++98
    HeapOnly(){}

    //不实现
    HeapOnly(const HeapOnly&);
    HeapOnly& operator=(HeapOnly const&);

    //c++11
    //= delete的意思是不生成默认的相关函数
    //HeapOnly(const HeapOnly&) = delete;
    //HeapOnly& operator=(HeapOnly const&) = delete;
};

//设计一个类，只能在栈上创建对象
//屏蔽掉operator new和定位new表达式
class StackOnly
{
  public:
    static StackOnly Create()
    {
      return StackOnly();
    }
  private:
    StackOnly(){}

    //屏蔽掉new和delete也就屏蔽掉定位new表达式,不实现
    void* operator new(size_t size);
    void operator delete(void* p);

};

void Func2()
{
  HeapOnly* a = HeapOnly::Create();
  StackOnly b = StackOnly::Create();
}

//单例模式
//
//饿汉模式：无论是否使用对象，直接先创建出来
//缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不定
//优点：简单
#if 0
class Singleton
{
  public:
    //只能返回指针或引用，不能返回普通变量，因为没有构造函数
    static Singleton* GetInstance()
    {
      return &m_instance;
    }
  private:
    //构造函数私有化
    Singleton(){}

    //拷贝构造和赋值运算符重载只声明不实现
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton&);

    //Singleton(const Singleton&) = delete;
    //Singleton& operator = (const Singleton&) = delete;
    
    static Singleton m_instance;
};
Singleton Singleton::m_instance;//在程序入口之前完成单例对象的初始化
#endif

#if 1
//懒汉模式：第一次使用该对象时创建对象
//缺点：复杂
//优点：进程启动无负载，多个单例实例对象启动顺序可以控制
class Singleton
{
  public:
    static Singleton* GetInstance()
    {
      if(nullptr == m_pInstance)
      {
        m_mtx.lock();//加锁
        if(nullptr == m_pInstance)
        {
          m_pInstance = new Singleton;
        }
        m_mtx.unlock();//解锁
      }
      return m_pInstance;
    }

    //内嵌自动回收资源类
    class CGarbo
    {
      public:
        ~CGarbo()
        {
          if(Singleton::m_pInstance)
          {
            cout<<"this is ~CGarbo"<<endl;
            delete Singleton::m_pInstance;
          }
        }
      private:

    };

    //定义一个静态成员变量，程序结束自动调用它的析构函数进行释放单例对象的资源
  static CGarbo garbo; 

  private:
    //构造函数私有
    Singleton(){}

    //防拷贝不实现
    Singleton(const Singleton&);//=delete
    Singleton& operator = (const Singleton&);

    static Singleton* m_pInstance;//单例对象指针
    static mutex m_mtx;//互斥锁

};

//初始化
Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_mtx;
Singleton::CGarbo garbo;

#endif


void Func3(int n)
{
  //Singleton* a = Singleton::GetInstance();
  //Singleton* b = Singleton::GetInstance();

  //cout<<"a: "<<&(*a)<<" b: "<<&(*b)<<endl;
  //cout<<Singleton::GetInstance()<<endl;
  //cout<<a<<endl;

  //cout<<Singleton::GetInstance()<<" : "<<Singleton::GetInstance()<<endl;

  cout<<Singleton::GetInstance()<<endl;

}

//申请4G空间，注意需要在64位操作系统下运行，因为32位操作系统内存只有4G空间，如果全部申请，那么内核就没有
//空间了
//void Func4()
//{
//  void* p = new char[0xffffffff];
//  cout<<"p: "<<p<<endl;
//}


int main()
{
  //Func1();
  //thread t1(Func3,10);
  //thread t2(Func3,11);

  //t1.join();
  //t2.join();

  cout<<Singleton::GetInstance()<<endl;

  //Func4();
  //Func5();
  //delete Singleton::GetInstance();

  return 0;
}
