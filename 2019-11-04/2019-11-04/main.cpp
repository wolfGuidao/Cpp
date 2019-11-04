#include<iostream>
using namespace std;
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int>s;
//		for (int i = 0;i < nums.size();i++)
//		{
//			s.push(nums[i]);
//		}
//		for (int i = 0;i < k - 1;i++)
//		{
//			s.pop();
//		}
//		return s.top();
//	}
//};
#include<vector>
//void adjustdown(int* str,int len)
//{
//	int parent = (len - 1) / 2;
//	int child = 2 * parent + 1;
//	while (parent-- >= 0)
//	{
//		/*if (child < len)
//		{
//			if (str[child] > str[parent])
//			{
//				swap(str[child], str[parent]);
//			}
//		}
//		if (child + 1 < len)
//		{
//			if (str[child + 1] > str[parent])
//			{
//				swap(str[child + 1], str[parent]);
//			}
//		}
//		parent = parent-1;
//		child = 2 * parent + 1;*/
//		while (child < len)
//		{
//			if (child + 1 < len&&str[child + 1] > str[child])
//			{
//				child += 1;
//			}
//			if (str[child] > str[parent])
//			{
//				swap(str[parent], str[child]);
//				//child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		child = 2 * parent + 1;
//		
//	}
//}

//int main()
//{
//	int str[] = { 1,2,3,4,5,6,7,8,9,10 };
//	adjustdown(str, sizeof(str) / sizeof(str[0]));
//	for (auto i : str)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//vector<vector<int>> generate(int numRows)
//{
//	vector<vector<int>>ret;
//	//vector<int>ret1;
//	ret.resize(numRows);
//	for (size_t i = 0;i < numRows;i++)
//	{
//		ret[i].resize( i+1 , 0);
//		ret[i][0] = 1;
//		ret[i][i] = 1;
//	}
//	for (size_t i = 0;i < ret.size();i++)
//	{
//		for (size_t j = 0;j < ret[i].size();j++)
//		{
//			if (ret[i][j] == 0)
//			{
//				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
//			}
//		}
//	}
//	return ret;
//}
//void testVector()
//{
//	int numRows = 5;
//	vector<vector<int>>a;
//	a = generate(5);
//	for (size_t i = 0;i < numRows;i++)
//	{
//		for (size_t j = 0;j <= i;j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
#if 0

namespace wolf
{
	/*template<class T1,class T2>
	T1 Add(T1 left, T2 right)
	{
		return left + right;
	}*/
}
template<class T1, class T2>
class Date
{
public:
	Date()
	{
		cout << " Date <T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//template<>
//class Date<int, char>
//{
//public:
//	Date()
//	{
//		cout << " Date <int,char>" << endl;
//	}
//private:
//	char _d1;
//	double _d2;
//};

//template<class T1>
//class Date<T1,int>
//{
//public:
//	Date()
//	{
//		cout << " Date <T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};

void Test()
{
	//Date<int, char>d1;
	//Date<char, int>d2;
	//Date d3();
}

#endif
#if 0

template<class T>
T Sum(T left, T right)
{
	return left + right;
}
template<>
double Sum<double>(double left, double right)
{
	return left + right;
}

void Test()
{
	/*double Sum(double left, double right)
	{
		return left + right;
	}*/
	Sum(1, 2);
	Sum<int>(1, 3);
	Sum<double>(1.2, 3.4);
}

int main()
{
	//cout << wolf::Add(1.0, 2.0) << endl;
	//printf("%f", wolf::Add(1.0, 2.0));
	Test();
	system("pause");
	return 0;
}
#endif
#include<deque>
#if 0
namespace wolf
{
	template<class T,class con=deque<T>>
	class stack
	{
	public:
		void push(T x)
		{
			_c.push_back(x);
		}
		void pop()
		{
			_c.pop_back();
		}
		T& top()
		{
			return _c.back();
		}
		const T& top()const
		{
			return _c.back();
		}
		int size()
		{
			return _c.size();
		}
		bool empty()
		{
			return _c.empty();
		}
	private:
		con _c;
	};
}

void TestStack()
{
	wolf::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.top() << endl;
	cout << s.size() << endl;
	s.pop();
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
}
#endif
#if 0
namespace wolf
{
	template<class T,class com=deque<T>>
	class queue
	{
	public:
		void push(T x)
		{
			_m.push_back(x);
		}
		void pop()
		{
			_m.pop_back();
		}
		T& back()
		{
			return _m.back();
		}
		const T& back()const
		{
			return _m.back;
		}
		T& front()
		{
			return _m.front();
		}
		const T& front()const
		{
			return _m.front();
		}
		int size()
		{
			return _m.size();
		}
		bool empty()
		{
			return _m.empty();
		}
	private:
		com _m;
	};
}
void Testqueue()
{
	wolf::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout<< q.back() <<endl;
	cout << q.size() << endl;
	cout << q.front() << endl;
	q.pop();
	q.pop();
	cout << q.back() << endl;
	cout << q.size() << endl;
	cout << q.front() << endl;
}
int main()
{
	//TestStack();
	Testqueue();
	system("pause");
	return 0;
}

#endif