#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

namespace wolf
{
  class string
  {
    public:
      //string 中的迭代器就是原生态的指针进行typedef了而已
      typedef char* iterator;

    public:
      string(const char* str = "")//构造函数
      {
        if (str == nullptr)//如果传进来为空指针，就让他改为"",这样就可以放止程序崩溃
        {
          str = "";
        }
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity+1];//申请空间,+1 的目的是放'\0'
        strcpy(_str, str);//把str中的内容拷贝过去
      }

      string(const string& s)//拷贝构造函数；采用深拷贝
        :_size(s._size)
         ,_capacity(s._size)
    {
      _str = new char[_capacity + 1];
      strcpy(_str, s._str);
    }

      string& operator=(string& s)//赋值运算符重载
      {
        if (this != &s)//防止自己给自己赋值
        {
          string temp(s._str);//调用构造函数把s的字符串拷贝一份，防止浅拷贝问题
          swap(_str, temp._str);
        }
        return *this;
      }

      ~string()//析构函数
      {
        if (_str)//不为空才进行释放，否则会多次释放
        {
          _size = 0;
          _capacity = 0;
          delete[] _str;
          _str = nullptr;
        }
      }

      size_t Size()const//返回字符串个数
      {
        return _size;
      }

      size_t Capacity()const//返回空间容量大小
      {
        return _capacity;
      }

      bool Empty()const//判空
      {
        return _size == 0;
      }

      iterator begin()//迭代器（注意迭代器的范围都是[begin,end))
      {
        return _str;//返回字符串首地址
      }

      iterator end()
      {
        return _str + _size;//返回字符串最后一个位置，即\0处
      }

      void Reserve(size_t newcapacity)//调整空间大小
      {

        if (newcapacity > _capacity)//如果新空间大小大于旧空间大小才进行
        {
          char* strtemp = new char[newcapacity + 1];//多一个是为了放'\0'
          strcpy(strtemp, _str);//拷贝元素
          delete[]_str;//释放原空间
          _str = strtemp;//指向新空间
          _capacity = newcapacity;//新空间大小不是newcapacity+1是为了和类库中string保持一致
        }
      }

      void Resize(size_t newsize,char ch = '\0')//把空间中有效字符个数调整为newsize的，多余的空间用ch填充
      {
        size_t oldsize = Size();
        if (newsize < oldsize)//如果调整后有效字符个数小于原有字符个数
        {
          _size = newsize;
          _str[_size] = '\0';
        }
        else
        {
          if (newsize > _capacity)//如果调整后字符个数大于空间容量，就进行扩容
          {
            Reserve(newsize);
          }
          memset(_str+_size, ch, newsize - oldsize);//从原有字符后面进行填充ch
        }
        _size = newsize;
        _str[_size] = '\0';//记得加上\0
      }

      void Push_back(char ch)//在原来字符串末尾追加一个字符ch
      {
        if (_size == _capacity)//判满
        {
          Reserve(_capacity * 2);
        }
        _str[_size++] = ch;
        _str[_size] = '\0';
      }

      string& operator+=(const char ch)//运算符重载
      {
        if (_size == _capacity)
        {
          Reserve(_capacity * 2);
        }
        Push_back(ch);
        return *this;
      }

      string& operator+=(const char* str)//重载+=
      {
        if(_capacity - _size < strlen(str) - 1)
        {
          Reserve(_capacity * 2);
        }
        for(size_t i = 0;i < strlen(str);++i)
        {
          _str[_size] = str[i];
          _size++;
        }
        _str[_size] = '\0';
        return *this;
      }

      string& operator+=(const string& s)//重载+=
      {
        if(_capacity - _size < s._size - 1)
        {
          Reserve(_capacity * 2);
        }
        for(size_t i = 0;i < s._size;++i)
        {
          _str[_size] = s._str[i];
          _size++;
        }
        _str[_size] = '\0';
        return *this;
      }

      void Append(const char* str)//追加字符串
      {
        if(_capacity - _size < strlen(str) - 1)
        {
          Reserve(_capacity * 2);
        }
        for(size_t i = 0;i < strlen(str);++i)
        {
          _str[_size] = str[i];
          _size++;
        }
        _str[_size] = '\0';
      }

      void Clear()//把空间中有效字符个数清空
      {
        _size = 0;
        _str[_size] = '\0';
      }

      void Swap(string& s)//把两个string对象中的内容交换，注意要全部交换
      {
        swap(_str, s._str);
        swap(_size, s._size);
        swap(_capacity, s._capacity);
      }

      const char* C_str()const//返回当前对象的C格式字符串
      {
        return _str;
      }

      char& operator[](size_t index)//运算符重载
      {
        assert(index < _size && index >= 0);
        return _str[index];
      }

      const char& operator[](size_t index)const
      {
        assert(index < _size && index >= 0);
        return _str[index];
      }

      bool operator>(const string& s)const
      {
        int min = strlen(_str) > strlen(s._str) ? strlen(s._str) : strlen(_str);
        for(int i = 0;i < min;i++)
        {
          if(_str[i] > s._str[i])
          {
            return true;
          }
          else if(_str[i] < s._str[i])
          {
            return false;
          }
          else
          {
            i++;
          }
        }

        if(strlen(_str) == strlen(s._str) || strlen(_str) < strlen(s._str))
        {
          return false;
        }
        else if(strlen(_str) > strlen(s._str))
        {
          return true;
        }
        return true;
      }
      bool operator==(const string& s)const
      {
        if(strlen(_str) != strlen(s._str))
        {
          return false;
        }
        int min = strlen(_str);
        for(int i = 0;i < min;i++)
        {
          if(_str[i] > s._str[i])
          {
            return false;
          }
          else if(_str[i] < s._str[i])
          {
            return false;
          }
          else
          {
            i++;
          }
        }

        return true;
      }
      bool operator>=(const string& s)const
      {
        return this->operator>(s) || this->operator==(s);
      }
      bool operator<(const string& s)const
      {
        return !this->operator>(s) && !this->operator==(s);
      }
      bool operator<=(const string& s)const
      {
        this->operator<(s) || this->operator==(s);
        return true;
      }

      bool operator!=(const string& s)const
      {
        return !this->operator==(s);
      }

      int Find(char ch, size_t pos = 0)const//从pos开始，从前往后找字符，返回ch的下标
      {
        assert(pos >= 0 && pos < _size);
        for (size_t i = pos;i < _size;i++)
        {
          if (_str[i] == ch)
          {
            return i;
          }
        }
        return -1;
      }

      int rFind(char ch, size_t pos = -1)const//从pos开始，从后往前找字符，返回ch的下标
      {
        if (pos == npos)
        {
          pos = _size - 1;
        }
        for (size_t i = pos;i >= 0;i--)
        {
          if (_str[i] == ch)
          {
            return i;
          }
        }
        return npos;
      }


      int Find(const char* str, size_t pos = 0)const//从pos开始，从前往后找字符串，返回str的下标
      {
        assert(pos >= 0 && pos <_size);
        return strstr(_str + pos,str) - _str;
      }

      int rFind(const char* str, size_t pos = -1)const//从pos开始，从后往前找字符串，返回str的下标
      {
        if(pos == npos)
        {
          pos =_size -1;
        }
        else if(pos < 0 || pos >_size)
        {
          return npos;
        }
        char* newstr = new char[_size + 1];
        strcpy(newstr,_str);
        newstr[pos] = '\0';
        return strstr(newstr,str) - newstr;
      }

      iterator Erase(size_t pos)//pos删除字符
      {
        assert(pos < _size && pos >= 0);
        int i = pos;
        while(_str[i] != '\0')
        {
          if(_str[i + 1] != '\0')
          {
            _str[i] = _str[i + 1];
            i++;
          }
          else
          {
            break;
          }
        }
        _str[i] = '\0';
        _size = _size - 1;
        iterator it = this->begin() + pos;
        if(it == this->end())
        {
          it = this->begin();
        }
        return it;
      }
      

      string& Insert(size_t pos,char ch)//在pos处插字符ch
      {
        if(_size == _capacity)
        {
          Reserve(_capacity * 2);
        }
        if(pos < 0 || pos > _size)
        {
          perror("insert is error!\n");
          return *this;
        }
        size_t i = _size;
        while(i != pos)
        {
          if(i - 1 >= 0)
          {
            _str[i] = _str[i - 1];
            i--;
          }   
          else
          {
            return *this;
          }
        }
        _str[i] = ch;
        _size++;
        _str[_size] = '\0';
        return *this;
      }
      //string& Insert(size_t pos, char* str)//在pos处插字符串str
      //{
      //  if(_size + strlen(str) == _capacity)
      //  {
      //    Reserve(_capacity * 2);
      //  }
      //  if(pos < 0 || pos > _size)
      //  {
      //    perror("insert is error!\n");
      //    return *this;
      //  }
      //  for(size_t i = strlen(str) - 1;i >= 0;i--)
      //  {
      //    Insert(pos,str[i]);
      //  }
      //  return *this;
      //}

      friend ostream& operator<<(ostream& _cout, const string& s);
      friend istream& operator>>(istream& _cin, const string& s);

    private:
      char* _str;//存放字符串
      size_t _size;//字符串个数
      size_t _capacity;//字符串容量
      static size_t npos;//静态变量npos，标准库模仿
  };//class string is end
  size_t wolf::string::npos = -1;
  ostream& operator<<(ostream& _cout, const string& s)
  {
    _cout << s.C_str();
    return _cout;
  }
  istream& operator>>(istream& _cin, const string& s)
  {
    _cin >> s._str;
    return _cin;
  }

}//nameapace wolf is end

