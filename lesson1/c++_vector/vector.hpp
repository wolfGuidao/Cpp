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

		vector()//Ĭ���޲ι��캯��
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{

		}

		vector(int n,const T& value=T())//��TΪ��������ʱ��T()����0����TΪ�Զ�������ʱ��T()���ڵ��乹�캯��
			:_start(new T[n])//����ռ�
		{
			for (int i = 0;i < n;i++)//����Ԫ��
			{
				_start[i] = value;
			}
			_finish = _start + n;//�������ָ��
			_endofstorage = _start + n;
		}

		template<class T1>//������������vector�ĵ���������ô��������ֻ����vector�ģ����Ե����¶����µĵ�������������������
		vector(T1 first, T1 last)//��Ϊ���乹����Ǹ������������Ͳ��������Ե���һ��ģ��
		{
			int n = 0;//��Ϊ��first��last����֮�䲻һ��ʱ�����ģ������������һ�����䣬���Բ�����first-last��Ԫ�ظ���
      T1 log = first;//���滹Ҫ�õ�first����ֱ�Ӹ�first
			while (log != last)
			{
				n++;
				log++;
			}
			_start = new T[n];//����ռ�
			for (int i = 0;i < n;i++)//����Ԫ��
			{
				_start[i] = *first;
				first++;
			}
			_finish = _start + n;//����
			_endofstorage = _finish;
		}

		vector(const vector<T>& s)//��������
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			 reserve(s.capacity());//��reserve������ռ䣬
       //��Ϊ��ʼ��ʱ���ָ��Ϊnullptr����reserve�����ڲ�û�п���Ԫ�أ�Ҫ�ֶ�����Ԫ��
			 auto it = begin();
       auto iit = s.cbegin();
       while(iit != s.cend())
       {
         *it = *iit;
         iit++;
         it++;
       }
				_finish = _start + s.size();//�������ָ��
				_endofstorage = _start + s.capacity();
		}

		~vector()//����
		{
			if (_start)
			{
				delete[] _start;//ע��������ָ��ʱָ��ͬһ���ռ�ģ�ֻ��Ҫ�ͷ�һ�˼���
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

		void Swap(vector<T>& s)//����
		{
			swap(_start, s._start);
			swap(_finish, s._finish);
			swap(_endofstorage, s._endofstorage);
		}

		vector<T>& operator=(vector<T> s)//��ֵ���������,ע��˴��������ܴ�����
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
				if (capacity() < newsize)//�ж��Ƿ���Ҫ����
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

		void reserve(size_t newcapacity)//���ݲ���
		{
			size_t oldsize = size();//�ȼ�¼Ԫ�صĸ�������Ϊsize�ļ��㷽��Ϊ_finish-_start;�����ڽ���_finish����ʱ
			//_finish���ھɿռ䣬��_start�Ѿ�ָ���¿ռ䣬�������_finish-_start�������ͻ����
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];
				if (_start)//��ֹ�ڹ��캯�������ã���Ϊ��ʱ_startΪ�գ��Ͳ��ܽ���Υ�����
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
        pos = _start + size;//����������ݣ��ռ�����Ѿ������ı䣬��pos����ԭ�ռ��ϣ���Ҫ�ı�ָ��ʹ��ָ��
        //�¿ռ�
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
		T* _start;//��ʼλ��
		T* _finish;//���һ��Ԫ�ص���һ��λ��
		T* _endofstorage;//�洢������ĩβ

	};
}//namespace wolf is end

