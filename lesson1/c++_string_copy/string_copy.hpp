#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

//解决浅拷贝问题：

#if 0
//(一)、深拷贝
namespace wolf
{
    class string
    {
        public:
            string(const char* str = "")//构造函数
                :_str(new char[strlen(str) + 1])
                {
                    if (str == nullptr)
                    {
                        str = "";
                    }
                    strcpy(_str, str);
                }

            string(const string& s)//拷贝构造函数
                :_str(nullptr)
            {
                //_str=s._str,这样会造成浅拷贝
                string strtemp(s._str);
                swap(_str, strtemp._str);
            }

            string& operator=(const string& s)//赋值运算符重载
            {
                if (this != &s)//防止自己给自己赋值
                {
                    string strtemp(s._str);
                    swap(_str, strtemp._str);
                }
                return *this;
            }

            ~string()//析构函数
            {
                if (_str)
                {
                    delete[] _str;
                    _str = nullptr;
                }
            }
        private:
            char* _str;
    };
}

#endif

//(二)、浅拷贝+引用计数解决浅拷贝问题：
//通过这种方法解决主要思想是：
//1.怎么解决多次释放一份资源问题：此时是和教室里最后一个人走关灯一样，如果我们知道当前共有多少个对象共享一份资源，
//当一个对象准备释放时，如果发现还有对象使用这份资源，就不释放，此时就解决一份资源多次释放问题
//2.怎么知道当前共有多少个对象共享这份资源：引用计数

#if 0
//一、拷贝构造函数的解决方法：
//错解1：在成员中定义一个int型变量，用来记录共享这份资源的对象的个数
namespace wolf
{
    class string
    {
        public:
            string(const char* str = "")//构造函数
                :_str(new char[strlen(str) + 1])
                {
                    if (str == nullptr)
                    {
                        str = "";
                    }
                    _count = 1;//因为一旦通过构造函数来构造一个对象，说明这个对象的资源只有它自己用，还没来得及共享，就把_count置为1
                    strcpy(_str, str);
                }

            string(string& s)//拷贝构造函数
                :_str(s._str)//在拷贝构造函数中采用浅拷贝的方式
                 ,_count(++s._count)//string s1("wolf");string s2(s1);此时有对象s2通过拷贝构造函数共享s1这个对象的资源时，
                 //就把s1._count加1，表明现在除了s1自己外还有别人共享这份资源，然后把s1._count赋值给需要共享的对象s2，
                 //此时s2._count也记录了当前共享一份资源的对象的个数；
        {

        }

            string& operator=(const string& s)//赋值运算符重载
            {
                if (this != &s)//防止自己给自己赋值
                {
                    //.....
                }
                return *this;
            }

            ~string()//析构函数
            {
                if (_str&&(--_count==0))//_count-1==0的意思是除去自己这个对象使用这份资源外，如果不为0，表明除了自己
                    //没有其他对象共享这份资源，此时释放就不会引起一份资源被多次释放的问题，反之_count-1！=0就表示
                    //还有对象使用这份资源，此时就不能释放。
                {
                    delete[] _str;
                    _str = nullptr;
                }
            }

            int Getpcount()
            {
                return _count;
            }

        private:
        public:
            char* _str;
            int _count;
    };
}
//string s1("wolf");string s2(s1);通过调试发现这种放法是错误的，因为当s2释放后，s2._count确实减少了，
//但是当我们去释放s1时，s1的s2._count仍为2，这样s2就没有释放，最终导致资源泄露

#endif

#if 0
//错解2：因为第一种方法放法主要是_count不同步造成的，所以采用static修饰_count的方法
namespace wolf
{
    class string
    {
        public:
            string(const char* str = "")//构造函数
                :_str(new char[strlen(str) + 1])
                {
                    if (str == nullptr)
                    {
                        str = "";
                    }
                    _count = 1;//因为一旦通过构造函数来构造一个对象，说明这个对象的资源只有它自己用，还没来得及共享，所以就把_count置为1
                    strcpy(_str, str);
                }

            string(string& s)//拷贝构造函数
                :_str(s._str)//在拷贝构造函数中采用浅拷贝的方式
            {
                _count++;//
            }

            string& operator=(const string& s)//赋值运算符重载
            {
                if (this != &s)//防止自己给自己赋值
                {
                    //.......
                }
                return *this;
            }

            ~string()//析构函数
            {
                if (_str && (--_count == 0))//_count-1==0的意思是除去自己这个对象使用这份资源外，如果为0，表明除了自己
                    //没有其他对象共享这份资源，此时释放就不会引起一份资源被多次释放的问题，反之_count-1！=0就表示
                    //还有对象使用这份资源，此时就不能释放。
                {
                    delete[] _str;
                    _str = nullptr;
                }
            }
        private:
        public:
            char* _str;
            static int _count;
    };
    int string::_count = 0;
}
//这种方法有一个严重的问题：就是因为_count时静态的，是所有对象共享的，当执行string s1("wolf guidao");
//string s2(s1);是完全没有问题的，但一旦执行string  s3;因为s3是另外通过构造函数创建的对象，使用的是另外一份资源，
//没有和s1s2共享，此时_count=1；这样就会影响到s1s2的释放问题,计数因该和资源个数保持一致。

#endif

#if 0
//正解：如果每一份资源都有自己的一个计数，这样计数就和资源个数保持一致，所以采用共享计数的方法
namespace wolf
{
    class string
    {
        public:
            string(const char* str = "")//构造函数
                :_str(new char[strlen(str) + 1])
                ,_pcount(new int (1))//在堆上申请一个空间并初始化为1；
                {
                    if (str == nullptr)
                    {
                        str = "";
                    }
                    strcpy(_str, str);
                }

            string(string& s)//拷贝构造函数
                :_str(s._str)//在拷贝构造函数中采用浅拷贝的方式
                 ,_pcount(s._pcount)//共享同一份资源的计数
        {
            ++(*_pcount);
        }

            string& operator=(const string& s)//赋值运算符重载
            {
                if (this != &s)//防止自己给自己赋值
                {
                    //.........
                }
                return *this;
            }

            ~string()//析构函数
            {
                if (_str && (--(*_pcount) == 0))//_pcount-1==0的意思是除去自己这个对象使用这份资源外，如果为0，表明除了自己
                    //没有其他对象共享这份资源，此时释放就不会引起一份资源被多次释放的问题，反之_pcount-1！=0就表示
                    //还有对象使用这份资源，此时就不能释放。
                {
                    delete[] _str;
                    _str = nullptr;
                    delete _pcount;
                    _pcount = nullptr;
                }
            }

            int Getpcount()
            {
                return *_pcount;
            }

        private:
            char* _str;
            int* _pcount;
    };
}
//执行string s1("wolf guidao");string s2(s1);通过这种方法每份资源都有自己的计数空间，如果有其他对象s2共享这份
//资源s1，同时也就共享了这份资源的计数；string  s3;s3是另外一份资源，s3的资源内容和计数空间都是另外一份，就不会
//共享s1的内容和s1的资源计数，这种方法就解决了上面一种法方法的问题。

#endif

#if 0
//二、赋值运算符重载的解决方法：
//经过上面的铺垫就很容易的到赋值运算符重载的解决方法
namespace wolf
{
    class string
    {
        public:
            string(const char* str = "")//构造函数
                :_str(new char[strlen(str) + 1])
                , _pcount(new int(1))//在堆上申请一个空间并初始化为1；
                {
                    if (str == nullptr)
                    {
                        str = "";
                    }
                    strcpy(_str, str);
                }

            string(string& s)//拷贝构造函数
                :_str(s._str)//在拷贝构造函数中采用浅拷贝的方式
                 , _pcount(s._pcount)//共享同一份资源的计数
        {
            ++(*_pcount);
        }
            //1.s3 = s2;如果赋值成功，s2，s3就会共享同一份资源，s2那份资源就多一个共享对象，所以共享s2那份资源的计数加1
            //2.s3原来的那份资源就不会再使用，所以要释放s3，那么共享s3这份资源的对象就少一份，所以就因该把共享s3的计数减1
            //如果把s3的计数减1后刚好为0，表示只有s3使用者一份资源，那么为了防止资源泄露，需要手动释放
            string& operator=(const string& s)//赋值运算符重载
            {
                //此时_pcount为s3，s._pcount为s2
                if (this != &s)//防止自己给自己赋值
                {
                    if (--(*_pcount) == 0)
                    {
                        delete[] _str;
                        delete _pcount;
                    }
                    _str = s._str;
                    _pcount = s._pcount;
                    ++(*_pcount);
                }
                return *this;
            }

            ~string()//析构函数
            {
                if (_str && (--(*_pcount) == 0))//_pcount-1==0的意思是除去自己这个对象使用这份资源外，如果为0，表明除了自己
                    //没有其他对象共享这份资源，此时释放就不会引起一份资源被多次释放的问题，反之_pcount-1！=0就表示
                    //还有对象使用这份资源，此时就不能释放。
                {
                    delete[] _str;
                    _str = nullptr;
                    delete _pcount;
                    _pcount = nullptr;
                }
            }
        private:
            char* _str;
            int* _pcount;
    };
}
#endif

//以上解决浅拷贝的方法也有其问题：如果修改对象s3中的资源时s3[0] = 'W';，就发现其他和其共享资源的对象s1,s2也发生了
//改变，相当于一改全改接下来就是想怎么解决这一问题。
//三、解决浅拷贝+引用计数的缺陷：写时拷贝copy on write(COW)（这里只针对部分）
//string s1("wolf guidao");string s2(s1);string  s3;s3 = s2;前面的代码都是没有问题的，但是s3[0] = 'W';就会出现问题，
//如果想解决这个问题；就因该进行判断，如果有其他对象s1，s2共享这份资源，就应该另外申请空间把s3对象分离出来，且把共
//享的这份资源拷贝一份，避免一改全改的问题，这就是写时拷贝。如果没有其他对象和s3共享同一份资源，就不用分离。

//分离对象的时机：所有的写操作或可能会引起写操作都应分离

#if 1
namespace wolf
{
    class string
    {
        public:
            string(const char* str = "")//构造函数
                :_str(new char[strlen(str) + 1])
                , _pcount(new int(1))//在堆上申请一个空间并初始化为1；
                {
                    if (str == nullptr)
                    {
                        str = "";
                    }
                    strcpy(_str, str);
                }

            string(string& s)//拷贝构造函数
                :_str(s._str)//在拷贝构造函数中采用浅拷贝的方式
                 , _pcount(s._pcount)//共享同一份资源的计数
        {
            ++(*_pcount);
        }
            //1.s3 = s2;如果赋值成功，s2，s3就会共享同一份资源，s2那份资源就多一个共享对象，所以共享s2那份资源的计数加1
            //2.s3原来的那份资源就不会再使用，所以要释放s3，那么共享s3这份资源的对象就少一份，所以就因该把共享s3的计数减1
            //如果把s3的计数减1后刚好为0，表示只有s3使用者一份资源，那么为了防止资源泄露，需要手动释放
            string& operator=(const string& s)//赋值运算符重载
            {
                //此时_pcount为s3，s._pcount为s2
                if (this != &s)//防止自己给自己赋值
                {
                    if (--(*_pcount) == 0)
                    {
                        delete[] _str;
                        delete _pcount;
                    }
                    _str = s._str;
                    _pcount = s._pcount;
                    ++(*_pcount);
                }
                return *this;
            }

            ~string()//析构函数
            {
                if (_str && (--(*_pcount) == 0))//_pcount-1==0的意思是除去自己这个对象使用这份资源外，如果为0，表明除了自己
                    //没有其他对象共享这份资源，此时释放就不会引起一份资源被多次释放的问题，反之_pcount-1！=0就表示
                    //还有对象使用这份资源，此时就不能释放。
                {
                    delete[] _str;
                    _str = nullptr;
                    delete _pcount;
                    _pcount = nullptr;
                }
            }
            char& operator[](size_t index)//下标运算符重载
            {
                //该操作可能会改变当前对象的内容，从而引起其他共享对象内容的改变，所以因该采用分离当前对象操作
                if (Getpcount() > 1)//满足条件就表示有其他对象共享资源，就因该分离
                {
                    string strtemp(_str);
                    this->Swap(strtemp);
                }
                return _str[index];
            }
            //执行s3[0] = 'W'时，因为s1，s2和其共享一份资源，临时对象strtemp._str指向原本s3共享的那份_str，
            //strtemp._pcount指向_pcount，当出该函数时，根据_pcount的值看是否要释放资源。
            //最后当释放对象s3时，因为strtemp是通过构造函数string strtemp(_str);来创建的，所以strtrmp._pcount=1，经过
            //交换后s3._pcount=1；所以s3可以正常释放。

            void Swap(string& s)//交换两个对象
            {
                swap(_str, s._str);//交换字符串内容
                swap(_pcount, s._pcount);//交换资源计数
            }

            //private:
        public:
            int Getpcount()
            {
                return *_pcount;
            }

            char* _str;
            int* _pcount;
    };
}
#endif
