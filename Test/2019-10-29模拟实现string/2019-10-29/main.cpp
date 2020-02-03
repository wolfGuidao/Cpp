#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

namespace wolf
{
	class string
	{
	public:
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
			_str = new char[_capacity+1];//申请空间
			strcpy(_str, str);//把str中的内容拷贝过去
		}

		string(const string& s)//拷贝构造函数；采用深拷贝
			:_size(s._size)
			,_capacity(s._size+1)
		{
			_str = new char[_capacity];
			strcpy(_str, s._str);
		}

		string& operator=(string& s)//赋值运算符重载
		{
			if (this != &s)
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

		size_t Capacity()const//返回空间容量daxiao
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
			return _str + _size;//返回字符串最后一个位置，即\0出
		}

		void Reserve(size_t newcapacity)//调整空间大小
		{
			
			if (newcapacity > _capacity)//如果新空间大小大于旧空间大小才进行
			{
				char* strtemp = new char[newcapacity + 1];//多一个是为了放'\0'
				strcpy(strtemp, _str);
				delete[]_str;
				_str = strtemp;
				_capacity = newcapacity;//新空间大小不是newcapacity+1是为了和类库中string保持一致
			}
		}

		void Resize(size_t newsize,char ch)//把空间中有效字符个数调整为newsize的，多余的空间用ch填充
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

		string& operator+=(char ch)//运算符重载
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			Push_back(ch);
			_size = _size + 1;
			return *this;
		}

		void Append(const char* str);//追加字符串
		string& operator+=(const char* str);//运算符重载

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
			if (index < _size)
			{
				return _str[index];
			}
		}

		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;

		int Find(char ch, size_t pos = 0)const//从pos开始，从前往后找字符，返回ch的下标
		{
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


		int Find(char* str, size_t pos = 0)const//从pos开始，从前往后找字符串，返回str的下标
		{}
		int rFind(char* str, size_t pos = 0)const//从pos开始，从后往前找字符串，返回str的下标
		{}

		string& Erase(size_t pos,size_t num)//从pos开始删除num个字符
		{}
		
		string& Insert(size_t pos,char ch)//在pos处插字符ch
		{}
		string& Insert(size_t pos, char* str)//在pos处插字符串str
		{}

		friend ostream& operator<<(ostream& _cout, const string& s)
		{
			_cout << s.C_str();
			return _cout;
		}
		friend istream& operator>>(istream& _cin, const string& s)
		{
			_cin >> s._str;
			return _cin;
		}

	private:
		char* _str;//存放字符串
		size_t _size;//字符串个数
		size_t _capacity;//字符串容量
		static size_t npos;
	};
}

size_t wolf::string::npos = -1;



void Teststeing()
{
	wolf::string a("wolf");
	//cout << a.Size() << endl;
	//cout << a.Capacity() << endl;
	wolf::string b(a);
	//cout << b.Size() << endl;
	//cout << a.Capacity() << endl;
	b.Resize(10, '!');
	//cout << b << endl;
	//cout << b.Size() << endl;
	//cout << b.Capacity() << endl;
	b.Reserve(30);
	//cout << b.Capacity() << endl;
	b.Push_back(' ');
	b.Push_back('i');
	//cout << b << endl;
	//b.Clear();
	//cout << b << endl;
	//cout << b.Find('o') << endl;
	//cout << b.rFind('o') << endl;
	//cout << b.C_str() << endl;
	wolf::string::iterator it = b.begin();
	/*while (it < b.end())
	{
		cout << *it;
		it++;
	}*/
	//cout << endl;
	/*for (auto e: b)
	{
		cout << e;
	}*/
	//cout << endl;
	wolf::string c;
	cin >> c;
	cout << c;
}

int main()
{
	Teststeing();
	system("pause");
	return 0;
}
