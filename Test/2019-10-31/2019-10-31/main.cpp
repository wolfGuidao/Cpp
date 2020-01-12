#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

namespace wolf
{
	template<class T>
	
	class vector
	{
	public:

		typedef T* iterator;

		int capacity()
		{
			return _endofstorage - _start;
		}

		int size()
		{
			return _finish - _start;
		}

		vector()//默认无参构造函数
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{

		}

		vector(int n,const T& value=T())//当T为内置类型时，T()等于0；当T为自定义类型时，T()等于调其构造函数
			:_start(new T[n])
		{
			for (int i = 0;i < n;i++)
			{
				_start[i] = value;
			}
			_finish = _start + n;
			_endofstorage = _start + n;
		}
		template<class T1>//如果区间参数传vector的迭代器，那么迭代区间只能是vector的；所以得重新定义新的迭代器，满足所有容器
		vector(T1 first, T1 last)//因为区间构造的那个区间数据类型不定，所以得有一个模板
		{
			int n = 0;//因为从first到last区间之间不一定时连续的，可能是链表的一段区间，所以不能用first-last求元素个数
			while (first != last)
			{
				n++;
				first++;
			}
			_start = new T[n];
			for (int i = 0;i < n;i++)
			{
				_start[i] = *first;
				first++;
			}
			_finish = _start + n;//更新
			_endofstorage = _finish;
		}

		//vector(const vector<T>& s)//拷贝构造
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	reserve(s.capacity);
		//	iterator it =
		//		delete[] _start;
		//		_start = str;
		//		_finish = _start + s.size();
		//		_endofstorage = _start + s.capacity();
		//}

		~vector()//析构
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		void Swap(vector<T>& s)//交换
		{
			swap(_start, s._start);
			swap(_finish, s._finish);
			swap(_endofstorage, s._endofstorage);
		}

		vector<T>& operator=(vector<T> s)//赋值运算符重载
		{
			Swap(s);
			return *this;
		}

		void resize(size_t newsize, const T value = T())
		{
			if (newsize <= size())
			{
				_finish = _start + newsize;
			}
			else
			{
				if (capacity() < newsize)
				{
					reserve(newsize);
				}
				iterator it = begin();
				 _finish = it + newsize;
				while (it != _finish)
				{
					*it = value;
					it++;
				}
			}
		}

		void reserve(size_t newcapacity)//扩容操作
		{
			size_t size1 = size();//先记录元素的个数，因为size的计算方法为_finish-_start;下面在进行_finish更新时
			//_finish还在旧空间，而_start已经指向新空间，如果进行_finish-_start操作，就会出错。
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];
				if (_start)//防止在构造函数处调用，因为那时_start为空，就不能进行违规操作
				{
					for (int i = 0;i < size();i++)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + size1;
				_endofstorage = _start + newcapacity;
			}
		}

		void push_back(const T value = T())
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2+2);
			}
			*_finish = value;
			_finish++;
		}
		void pop_back()
		{
			_finish--;
		}
		T* insert(T* pos, const T& value)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() + 2);
			}
			T* _finish1 = _finish;
			while (_finish1 > pos)
			{
				_start[*_finish1] = _start[*(_finish1 - 1)];
				_finish--;
			}
			*pos = value;
			_finish++;
			return pos;
		}

		T* erase(T* pos)
		{
			if (_start)
			{
				T* pos1 = pos;
				while ((pos1+2) != _finish)
				{
					_start[*pos1] = _start[*(pos1 + 1)];
					pos1++;
				}
				_finish--;
			}
			return pos;
		}

	private:
		T* _start;//起始位置
		T* _finish;//最后一个元素的下一个位置
		T* _endofstorage;//存储容量的末尾

	};
}

void Testvector()
{
	//wolf::vector <int>a(10,5);
	////cout<<a.size()<<endl;
	////cout << a.capacity()<<endl;
	///*wolf::vector<int>b(a);
	//cout << a.size() << endl;
	//cout << a.capacity() << endl;*/
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	/*wolf::vector<int>c(arr, arr + 8);
	cout << c.size() << endl;
	cout << c.capacity() << endl;
	c.reserve(10);
	c.push_back(99);
	cout << c.size() << endl;
	c.pop_back();
	cout << c.size() << endl;*/
	//wolf::vector <int>a(10, 5);
	//cout<<a.size()<<endl;
	wolf::vector <int>c(5, 5);
	//cout << c.size() << endl;
    /*a.Swap(c);
	cout << a.size() << endl;
	cout << c.size() << endl;*/
	c.push_back(9);
	//a.operator=(c);
	/*cout << a.size() << endl;*/
	cout << c.size() << endl;
	c.insert(c.begin()+8, 9999);
	cout << c.size() << endl;
	c.erase(c.begin()+4);
	cout << c.size() << endl;
}
int main()
{
	//int arr[] = { 12,3,4,56,7,8,9 };
	Testvector();
	//vector<int>a(arr, arr + 6);
	//cout << a.size() << endl;
	//a.insert(a.begin()+2, 99);
	system("pause");
	return 0;
}