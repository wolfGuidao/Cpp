#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

namespace wolf
{
#if 0
  //1.浅拷贝
  class string
  {
    public:
      string(const char* str = "")
      {
        if(str == nullptr)
        {
          str = ""; 
        }
        _str = new char[strlen(str) + 1];  
        strcpy(_str,str);
      }

      string(const string& s)
      {
        _str = s._str;
      }

      string& operator=(const string& s)
      {
        _str = s._str;
        return *this;
      }

      ~string()
      {
        if(_str)
        {
          delete[] _str;
          _str = nullptr;
        }
      }

    private:
      char* _str;

  };
#endif

#if 0
  //2.第一种深拷贝
  class string
  {
    public:
      string(const char* str = "")
      {
        if(str == nullptr)
        {
          str = ""; 
        }
        _str = new char[strlen(str) + 1];  
        strcpy(_str,str);
        cout<<"this is string(cosnt char*)"<<endl;
      }

      string(const string& s)
      {
        _str = new char[strlen(s._str) + 1];//直接申请新空间
        strcpy(_str,s._str);//拷贝元素
        cout<<"this is string(cosnt string&)"<<endl;

      }

      string& operator=(const string& s)
      {
        if(this != &s)//防止自己给自己赋值
        {
          char* temp = new char[strlen(s._str) + 1];//申请临时空间
          strcpy(temp,s._str);//把元素内容拷贝到临时空间
          delete[] _str;//释放对象的原来空间的资源
          _str = temp;//将原指针指向临时空间
        }
        //出operator = 作用域后，系统自动释放temp在栈上的空间，但是它原本指向的空间现在已经有指针指向
        //不会造成内存泄漏
        
        cout<<"this is operator = "<<endl;
        return *this;
      }

      ~string()
      {
        if(_str)
        {
          delete[] _str;
          _str = nullptr;
        cout<<"this is ~string()"<<endl;
        }
      }

    private:
      char* _str;

  };
#endif

#if 0
  //第二种深拷贝
  class string
  {
    public:
      string(const char* str = "")
      {
        if(str == nullptr)
        {
          str = ""; 
        }
        _str = new char[strlen(str) + 1];  
        strcpy(_str,str);
        cout<<"this is string(cosnt char*)"<<endl;
      }

      string(const string& s)
        :_str(nullptr)//最好初始化位空，因为下面经过交换后如果不初始化为nullptr，就可能指向任意空间，
         //最后在释放temp的时候就有可能报错
      {
        string temp(s._str);//那s._str重新构造一个临时对象，注意此处千万不要使用拷贝构造，会造成
        //无限递归
        Swap(_str,temp._str);//把_str和temp的空间资源进行交换
        //出该作用域后，自动调用析构来回收临时对象temp，但是此时为temp管理的空间指向nullptr，
        //就不用释放空间，直接回收相应资源即可
        cout<<"this is string(cosnt string&)"<<endl;
      }

      string& operator=(const string& s)
      {
        if(this != &s)
        {
          string temp(s);//此处就可以调用拷贝构造来构造一个临时对象
          Swap(_str,temp._str);//完成交换后，出该作用域时，释放临时对象temp也就释放_str原来指向的空间，
          //不用手动释放
        }
          cout<<"this is operator = "<<endl;
        return *this;
      }
      
      //string& operator=(const string s)
      //{
      //  //if(this != &s)
      //  //{
      //  Swap(_str,s._str);
      //  //}
      //  cout<<"this is operator = "<<endl;
      //  return *this;
      //  //缺陷是无法检查是否是自己给自己赋值，因为如果根据上面的判断，那么在传参时发生了临时拷贝
      //  //地址肯定不一样，所以就无法判断是否是自己给自己赋值
      //}

      ~string()
      {
        if(_str)
        {
          delete[] _str;
          _str = nullptr;
        }
        cout<<"this is ~string()"<<endl;
      }

      void Swap(const char* _str,const char* str)
      {
        const char* temp = _str;
        _str = str;
        str = temp;
      }

    private:
      char* _str;

  };
#endif

#if 1
  //4.采用 浅拷贝 + 引用计数 解决浅拷贝问题，并解决引用计数的缺陷写时拷贝
  class string
  {
    public:
      string(const char* str = "")
      {
        if(str == nullptr)
        {
          str = "";
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str,str);
        _pCount = new int;
        *_pCount = 1;
        cout<<"this is string(char*)"<<endl;
      }

      string (const string& s)
      {
        _str = s._str;
        _pCount = s._pCount;
        (*_pCount)++;
        cout<<"this is string(string&)"<<endl;
      }

      string& operator=(const string& s)
      {
        if(this != &s)
        {
          //s1 = s2
          if(--(*_pCount) == 0)
          {
            delete[] _str;
            delete _pCount;
          }
          _str = s._str;
          _pCount = s._pCount;
          (*_pCount)++;
        }
        cout<<"this is operator="<<endl;
          return *this;
      }

      ~string()
      {
        if(_str && (--(*_pCount) == 0))
        {
          delete[] _str;
          _str = nullptr;
          delete _pCount;
          _pCount = nullptr;
        }
        cout<<"this is ~string()"<<endl;
      }

      int GetpCount()
      {
        return *_pCount;
      }

      void Swap(string& s1,string& s2)
      {
        swap(s1._str,s2._str);
        swap(s1._pCount,s2._pCount);
      }

      //分离
      char& operator[](int index)
      {
        assert(index >= 0 && index < strlen(_str));
        if(GetpCount() > 1)
        {
          string temp(_str);
          Swap(*this,temp);
          cout<<"分离"<<endl;
        }
        return _str[index];
      }

    char* GetStr()
    {
      return _str;
    }

    private:
      char* _str;
      int* _pCount;
  };

#endif

}

wolf::string s1("hello wolf");

void Func2()
{
  wolf::string s4(s1);
  cout<<"count s4: "<<s4.GetpCount()<<endl;
  wolf::string s5(s4);
  cout<<"count s4: "<<s4.GetpCount()<<" s5: "<<s5.GetpCount()<<endl;
}

void Func1()
{
  cout<<"pCount s1: "<<s1.GetpCount()<<endl;
  wolf::string s2(s1);
  cout<<"pCount s1: "<<s1.GetpCount()<<" s2: "<<s2.GetpCount()<<endl;
  Func2();
  wolf::string s3;
  s3.operator=(s2);
  cout<<"pCount s1: "<<s1.GetpCount()<<" s2: "<<s2.GetpCount()<<" s3: "<<s3.GetpCount()<<endl;

  cout<<" s1: "<<s1.GetStr()<<" s2: "<<s2.GetStr()<<" s3: "<<s3.GetStr()<<endl;
  s3[5] = 'c';
  cout<<" s1: "<<s1.GetStr()<<" s2: "<<s2.GetStr()<<" s3: "<<s3.GetStr()<<endl;
}

int main()
{
  Func1();
  return 0;
}
