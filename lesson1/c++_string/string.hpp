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
      //string �еĵ���������ԭ��̬��ָ�����typedef�˶���
      typedef char* iterator;

    public:
      string(const char* str = "")//���캯��
      {
        if (str == nullptr)//���������Ϊ��ָ�룬��������Ϊ"",�����Ϳ��Է�ֹ�������
        {
          str = "";
        }
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity+1];//����ռ�,+1 ��Ŀ���Ƿ�'\0'
        strcpy(_str, str);//��str�е����ݿ�����ȥ
      }

      string(const string& s)//�������캯�����������
        :_size(s._size)
         ,_capacity(s._size)
    {
      _str = new char[_capacity + 1];
      strcpy(_str, s._str);
    }

      string& operator=(string& s)//��ֵ���������
      {
        if (this != &s)//��ֹ�Լ����Լ���ֵ
        {
          string temp(s._str);//���ù��캯����s���ַ�������һ�ݣ���ֹǳ��������
          swap(_str, temp._str);
        }
        return *this;
      }

      ~string()//��������
      {
        if (_str)//��Ϊ�ղŽ����ͷţ���������ͷ�
        {
          _size = 0;
          _capacity = 0;
          delete[] _str;
          _str = nullptr;
        }
      }

      size_t Size()const//�����ַ�������
      {
        return _size;
      }

      size_t Capacity()const//���ؿռ�������С
      {
        return _capacity;
      }

      bool Empty()const//�п�
      {
        return _size == 0;
      }

      iterator begin()//��������ע��������ķ�Χ����[begin,end))
      {
        return _str;//�����ַ����׵�ַ
      }

      iterator end()
      {
        return _str + _size;//�����ַ������һ��λ�ã���\0��
      }

      void Reserve(size_t newcapacity)//�����ռ��С
      {

        if (newcapacity > _capacity)//����¿ռ��С���ھɿռ��С�Ž���
        {
          char* strtemp = new char[newcapacity + 1];//��һ����Ϊ�˷�'\0'
          strcpy(strtemp, _str);//����Ԫ��
          delete[]_str;//�ͷ�ԭ�ռ�
          _str = strtemp;//ָ���¿ռ�
          _capacity = newcapacity;//�¿ռ��С����newcapacity+1��Ϊ�˺������string����һ��
        }
      }

      void Resize(size_t newsize,char ch = '\0')//�ѿռ�����Ч�ַ���������Ϊnewsize�ģ�����Ŀռ���ch���
      {
        size_t oldsize = Size();
        if (newsize < oldsize)//�����������Ч�ַ�����С��ԭ���ַ�����
        {
          _size = newsize;
          _str[_size] = '\0';
        }
        else
        {
          if (newsize > _capacity)//����������ַ��������ڿռ��������ͽ�������
          {
            Reserve(newsize);
          }
          memset(_str+_size, ch, newsize - oldsize);//��ԭ���ַ�����������ch
        }
        _size = newsize;
        _str[_size] = '\0';//�ǵü���\0
      }

      void Push_back(char ch)//��ԭ���ַ���ĩβ׷��һ���ַ�ch
      {
        if (_size == _capacity)//����
        {
          Reserve(_capacity * 2);
        }
        _str[_size++] = ch;
        _str[_size] = '\0';
      }

      string& operator+=(const char ch)//���������
      {
        if (_size == _capacity)
        {
          Reserve(_capacity * 2);
        }
        Push_back(ch);
        return *this;
      }

      string& operator+=(const char* str)//����+=
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

      string& operator+=(const string& s)//����+=
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

      void Append(const char* str)//׷���ַ���
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

      void Clear()//�ѿռ�����Ч�ַ��������
      {
        _size = 0;
        _str[_size] = '\0';
      }

      void Swap(string& s)//������string�����е����ݽ�����ע��Ҫȫ������
      {
        swap(_str, s._str);
        swap(_size, s._size);
        swap(_capacity, s._capacity);
      }

      const char* C_str()const//���ص�ǰ�����C��ʽ�ַ���
      {
        return _str;
      }

      char& operator[](size_t index)//���������
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

      int Find(char ch, size_t pos = 0)const//��pos��ʼ����ǰ�������ַ�������ch���±�
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

      int rFind(char ch, size_t pos = -1)const//��pos��ʼ���Ӻ���ǰ���ַ�������ch���±�
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


      int Find(const char* str, size_t pos = 0)const//��pos��ʼ����ǰ�������ַ���������str���±�
      {
        assert(pos >= 0 && pos <_size);
        return strstr(_str + pos,str) - _str;
      }

      int rFind(const char* str, size_t pos = -1)const//��pos��ʼ���Ӻ���ǰ���ַ���������str���±�
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

      iterator Erase(size_t pos)//posɾ���ַ�
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
      

      string& Insert(size_t pos,char ch)//��pos�����ַ�ch
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
      //string& Insert(size_t pos, char* str)//��pos�����ַ���str
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
      char* _str;//����ַ���
      size_t _size;//�ַ�������
      size_t _capacity;//�ַ�������
      static size_t npos;//��̬����npos����׼��ģ��
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

