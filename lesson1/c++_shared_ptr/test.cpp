#include <memory>
#include <iostream>
using namespace std;

class Date
{
    public:
        Date() { cout << "Date()" << endl; }
        ~Date(){ cout << "~Date()" << endl; }
        int _year;
        int _month;
        int _day;

};

void Func1()
{
    //auto_ptr的思想是管理权转移
    auto_ptr<Date> ap(new Date);
    ap.operator->()->_year = 2020;
    ap.operator->()->_month = 1;
    ap.operator->()->_day = 15;

    auto_ptr<Date> cap(ap);
    cap.operator->()->_day = 16;

    //cout<<ap.operator->()->_year<<endl;//此处会出错
    cout<<cap.operator->()->_year<<endl;
}

template<class T>
class AutoPtr
{
    public:
        AutoPtr(T* ptr= nullptr)
            :_ptr(ptr)
        {}

        ~AutoPtr()
        {
            if(_ptr)
            {
                delete _ptr;
            }
        }

        //一旦发生拷贝，那么就相当于两个对象同时管理一个空间，那么就会有资源释放问题
        //一旦发生拷贝，就将ap中的资源转移到当前对象中，然后让ap与资源断开联系，解决因拷贝导致崩溃问题
        AutoPtr(AutoPtr<T>& ap)
            :_ptr(ap._ptr)
        {
            ap._ptr = nullptr;
        }

        AutoPtr<T>& operator=(AutoPtr<T>& ap)
        {
            if(this != &ap)
            {
                if(_ptr)
                {
                    delete _ptr;
                }
                _ptr = ap._ptr;
                ap._ptr = nullptr;
            }
            return *this;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

    private:
        T* _ptr;
};

void Func2()
{
    int* arr = new int;
    AutoPtr<int> ar(arr);
    *ar = 999;
    cout<<*ar<<endl;
}


//unique_ptr的思想是禁止拷贝
template<class T>
class UniquePtr
{
    public:
        UniquePtr(T * ptr = nullptr)
            : _ptr(ptr)
        {}
        ~UniquePtr()
        {
            if(_ptr)
                delete _ptr;

        }
        T& operator*() {return *_ptr;}
        T* operator->() {return _ptr;}
    private:
        //C++98防拷贝的方式：只声明不实现+声明成私有
        UniquePtr(UniquePtr<T> const &);
        UniquePtr & operator=(UniquePtr<T> const &);
        // C++11防拷贝的方式：delete
        //UniquePtr(UniquePtr<T> const &) = delete;
        //UniquePtr & operator=(UniquePtr<T> const &) = delete;

    private:
        T * _ptr;
};

void Func3()
{
    UniquePtr<int> un(new int);
    //UniquePtr<int> cun(un);
}

#include <thread>
#include <mutex>
template <class T>

//shared_ptr的思想是引用计数

class SharedPtr
{
    public:
        SharedPtr(T* ptr = nullptr)
            : _ptr(ptr)
              , _pRefCount(new int(1))
              , _pMutex(new mutex)
    {}

        ~SharedPtr() 
        {
            Release();
        }

        SharedPtr(const SharedPtr<T>& sp)
            : _ptr(sp._ptr)
              , _pRefCount(sp._pRefCount)
              , _pMutex(sp._pMutex)
    {
        AddRefCount();
    }

        // sp1 = sp2
        SharedPtr<T>& operator=(const SharedPtr<T>& sp)
        {
            //if (this != &sp)
            if (_ptr != sp._ptr)
            {
                // 释放管理的旧资源
                Release();
                // 共享管理新对象的资源，并增加引用计数
                _ptr = sp._ptr;
                _pRefCount = sp._pRefCount;
                _pMutex = sp._pMutex;
                AddRefCount();
            }
            return *this;
        }

        T& operator*() 
        {
            return *_ptr;
        }

        T* operator->() 
        {
            return _ptr;
        }

        int UseCount() 
        {
            return *_pRefCount;
        }

        T* Get() 
        { 
            return _ptr;
        }

        void AddRefCount()
        {
            // 加锁或者使用加1的原子操作
            _pMutex->lock();
            ++(*_pRefCount);
            _pMutex->unlock();
        }
    private:

        void Release()
        {
            bool deleteflag = false;

            _pMutex->lock();
            if (--(*_pRefCount) == 0)
            {
                delete _ptr;
                delete _pRefCount;
                deleteflag = true;
            }
            _pMutex->unlock();
            if(deleteflag == true)
                delete _pMutex;
        }
    private:
        int* _pRefCount; // 引用计数
        T* _ptr; // 指向管理资源的指针
        mutex* _pMutex; // 互斥锁
};

void Func4()
{
    SharedPtr<int> sh(new int); 
    SharedPtr<int>csh(sh);
    *sh = 999;
    cout<<*sh<<endl;
    *csh = 666;
    cout<<*csh<<endl;
    cout<<"& sh: "<<sh.Get()<<" csh: "<<csh.Get()<<endl;
}

//shared_ptr的循环引用问题及解决方法
struct ListNode
{
    int _data;
    //shared_ptr<ListNode> _prev;
    //shared_ptr<ListNode> _next;
    weak_ptr<ListNode> _prev;
    weak_ptr<ListNode> _next;
    ~ListNode(){ cout << "~ListNode()" << endl;  }

};

void Func5()
{
    shared_ptr<ListNode> node1(new ListNode);
    shared_ptr<ListNode> node2(new ListNode);

    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;

    node1->_next = node2;
    node2->_prev = node1;

    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;

}

//删除器
template<class T>
struct FreeFunc 
{
    void operator()(T* ptr)
    {
        cout << "free:" << ptr << endl;
        free(ptr);
    }
};
template<class T>
struct DeleteArrayFunc 
{
    void operator()(T* ptr)
    {
        cout << "delete[]" << ptr << endl;
        delete[] ptr;
    }
};

int main()
{
    //Func1();
    //Func2();
    //Func3();
    //Func4();
    Func5();
    return 0;
}
