#include <iostream>
#include <assert.h>
using namespace std;

namespace wolf
{

	template<class T>	
	class vector
	{
	public:

		typedef T* iterator;
		typedef const T* const_iterator;

		int capacity()const
		{
			return _endofstorage - _start;
		}

		int size()const
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
			:_start(new T[n])//申请空间
		{
			for (int i = 0;i < n;i++)//拷贝元素
			{
				_start[i] = value;
			}
			_finish = _start + n;//更新相关指针
			_endofstorage = _start + n;
		}

		template<class T1>//如果区间参数传vector的迭代器，那么迭代区间只能是vector的；所以得重新定义新的迭代器，满足所有容器
		vector(T1 first, T1 last)//因为区间构造的那个区间数据类型不定，所以得有一个模板
		{
			int n = 0;//因为从first到last区间之间不一定时连续的，可能是链表的一段区间，所以不能用first-last求元素个数
      T1 log = first;//下面还要用到first不能直接该first
			while (log != last)
			{
				n++;
				log++;
			}
			_start = new T[n];//申请空间
			for (int i = 0;i < n;i++)//拷贝元素
			{
				_start[i] = *first;
				first++;
			}
			_finish = _start + n;//更新
			_endofstorage = _finish;
		}

		vector(const vector<T>& s)//拷贝构造
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			 reserve(s.capacity());//用reserve来申请空间，
       //因为初始化时相关指针为nullptr，在reserve函数内并没有拷贝元素，要手动拷贝元素
			 auto it = begin();
       auto iit = s.cbegin();
       while(iit != s.cend())
       {
         *it = *iit;
         iit++;
         it++;
       }
				_finish = _start + s.size();//更新相关指针
				_endofstorage = _start + s.capacity();
		}

		~vector()//析构
		{
			if (_start)
			{
				delete[] _start;//注意这三个指针时指向同一个空间的，只需要释放一此即可
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

		const_iterator cbegin()const
		{
			return _start;
		}

		const_iterator cend()const
		{
			return _finish;
		}

		void Swap(vector<T>& s)//交换
		{
			swap(_start, s._start);
			swap(_finish, s._finish);
			swap(_endofstorage, s._endofstorage);
		}

		vector<T>& operator=(vector<T> s)//赋值运算符重载,注意此处参数不能传引用
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
				if (capacity() < newsize)//判断是否需要扩容
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
			size_t oldsize = size();//先记录元素的个数，因为size的计算方法为_finish-_start;下面在进行_finish更新时
			//_finish还在旧空间，而_start已经指向新空间，如果进行_finish-_start操作，就会出错。
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];
				if (_start)//防止在构造函数处调用，因为那时_start为空，就不能进行违规操作
				{
					for (int i = 0;i < oldsize;i++)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + oldsize;
				_endofstorage = _start + newcapacity;
			}
		}

		void push_back(const T value = T())
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 2);
			}
			*_finish = value;
			_finish++;
		}

		void pop_back()
		{
			_finish--;
		}

		iterator insert(iterator pos, const T& value)
		{
      assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
        int size = pos - _start;
				reserve(capacity() * 2 + 2);
        pos = _start + size;//如果发生扩容，空间可能已经发生改变，而pos还在原空间上，需要改变指向，使其指向
        //新空间
			}
			T* _finish1 = _finish;
			while (_finish1 > pos)
			{
        *_finish1 = *(_finish1 - 1);
				_finish1--;
			}
			*pos = value;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			if (_start)
			{
				T* pos1 = pos;
				while ((pos1 +1 ) != _finish)
				{
          *pos1 = *(pos1 + 1);
					pos1++;
				}
				_finish--;
			}
			return pos;
		}

    T& operator[](size_t index)
    {
      assert(index < size() && index >= 0);
      return _start[index];
    }

    const T& operator[](size_t index)const
    {
      assert(index < size() && index >= 0);
      return _start[index];
    }

    void Print()
    {
      auto it = begin();
      while(it != end())
      {
        cout<<*it<<" ";
        it++;
      }
      cout<<endl;
    }

	private:
		T* _start;//起始位置
		T* _finish;//最后一个元素的下一个位置
		T* _endofstorage;//存储容量的末尾

	};
}//namespace wolf is end

