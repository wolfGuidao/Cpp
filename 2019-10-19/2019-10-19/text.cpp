//#include<iostream>
//#include<windows.h>
//using namespace std;

#if 0
//命名空间
namespace N1
{
	namespace N2
	{
		int b = 3;
		int Max(int x, int y)
		{
			return (x > y ? x : y);
		}
	}
	int a = 2;
	int Sum(int x, int y)
	{
		return x + y;
	}
}

int main()
{
	//using namespace N1;
	using N1::N2::b;
	using N1::N2::Max;
	//using namespace N2;
	//using N1::a;
	//using N1::Sum;
		/*int a;
		int b;
		float c;
		char d;
		cout << "请输入4个值" << endl;
		cin >> a >> b >> c >> d;
		cout << endl;
		cout << a <<" "<< b << " " << c << " " << d << " " << "hello world";
		cout << endl;*/
		/*cout << 12.34 << endl;
		cout << 'a' << 'b' << endl;
		cout << "afbav" << endl;*/
		//cout << N1::a << endl;
		//cout << N1::Sum(2, 4) << endl;
		//cout << a << endl;
		//cout << Sum(3, 4) << endl;
	cout << b << endl;
	cout << Max(4, 6) << endl;
	system("pause");
	return 0;
}
#endif
#if 0
//int Sum(int x=5, int y=5)
//{
//	return x + y;
//}
//double Sum(double x, int y)
//{
//	return x + y;
//}
int Sum(int& rx, int & ry)
{
	int temp;
	temp = rx + ry;
	return temp;
}
int Add(int a)
{
	int c = a + 10;
	return c;
}
void Swap(int& ra, int& tb)
{
	int temp;
	temp = ra;
	ra = tb;
	tb = temp;
}

inline int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	/*cout << Sum(4, 5) << endl;
	cout << Sum(4) << endl;
	cout << Sum() << endl;*/
	/*cout << Sum(77, 99) << endl;
	cout<<Sum(12.34, 34.56) << endl;*/
	int a = 42;
	int b = 5;
	//cout << Sum(a, b) << endl;
	//cout<<Sum(a,b)<<endl
	//Swap(a, b);
	//cout<< a<< b << endl;
	//cout << Sum(a, b) << endl;
	//int ret = Add(9);
	//cout << ret<< endl;
	/*int& ra = a;
	int& rb = b;
	cout << ra << rb << endl;
	cout << ra - rb << endl;*/
	/*const int & ra = a;
	const int& rb = b;
	const int& rc = 10;
	const int &rd =11;
	double d = 12.45;
	const int& re = d;*/
	//cout << re << endl;
	/*double f = 12.12;
	const int& rf =f;
	cout << rf << endl;*/
	//cout << Max(a, b) <<endl;
	system("pause");
	return 0;
}
#endif
#if 0
int sum(int x, int y)
{
	return x + y;
}
int main()
{
	auto a = 4;
	auto b = 5;
	int f[] = { 1,2,3,4,4,5,6,7,7,8,8,9 };
	for (auto& i : f)
	{
		//cout << i*2 << endl;
	}
	//cout << sum(a, b) << endl;
	//cout<< nullptr << endl;
	system("pause");
	return 0;
}
#endif
#if 0
class Date
{
public:
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
private:
	int _year;
	int _month;
	int _day;
};
//void Date :: Show()
//{
//	cout << _year << _month << _day << endl;
//}
class A
{

};
class B
{
	void fb()
	{

	}
};
class C
{
	/*char c = 'a';
	int a = 3;
	
	char d = 'a';
	double b = 3;*/
	int a;
	short d;
	char c;
	
	
	int b;
	
};
int main()
{
	//Date a(2019,10,18);
	//Date b;
	//cout << b._day << endl;
	//cout << sizeof(A) << endl;
	//cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void show()
	{
		cout << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a(2019, 10, 18);
	a.show();
	cout << &a << endl;
	system("pause");
	return 0;
}
#endif 

#include<iostream>
#include<windows.h>
using namespace std;

class Date
{
public:
	Date()//默认无参构造函数
	{
		_year = 2019;
		_month = 10;
		_day = 18;
	}

	Date(int year,int month,int day)//构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	~Date()//析构函数
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}

	Date(const Date& ra)//拷贝构造函数
	{
		_year = ra._year;
		_month = ra._month;
		_day = ra._day;
	}

	bool operator >(const Date& ra)const// >运算符重载
	{
		if ((_year > ra._year) || (_year == ra._year &&_month > ra._month) ||
			(_year == ra._year &&_month == ra._month&&_day > ra._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Date& ra)const//<
	{
		if (this->operator>(ra))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator ==(Date& ra)//==运算符重载
	{
		if (_year == ra._year &&_month == ra._month&&_day == ra._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(const Date& ra)const
	{
		if ((_year > ra._year) || (_year == ra._year &&_month > ra._month) ||
			(_year == ra._year &&_month == ra._month&&_day > ra._day)||
			_year == ra._year &&_month == ra._month&&_day == ra._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Date& operator++()//前置++
	{
		_day = _day + 1;
		return *this;
	}

	Date operator++(int)//后置++
	{
		Date temp = *this;
		_day = _day + 1;
		return temp;
	}

	Date& operator--()//前置--
	{
		_day = _day - 1;
		return *this;
	}

	Date operator--(int)//后置--
	{
		Date temp = *this;
		_day = _day - 1;
		return temp;
	}

	Date& operator+(int day)//+
	{
		_day +=day;
		return *this;
	}

	Date& operator-(int day)//-
	{
		_day -= day;
		return *this;
	}

	Date& operator=(const Date& ra)//=
	{
		_year = ra._year;
		_month = ra._month;
		_day = ra._day;
		return *this;
	}

	int operator-(const Date& ra)//-
	{
		_day = _day - ra._day;
		return _day;
	}

	void Show()//打印
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//测试用例
	Date a(2019, 10, 19);
	Date b(a);
	a.Show();
	b.Show();
	a.operator++().Show();
	b.operator++().Show();
	cout << a.operator>(b) << endl;
	cout << a.operator==(b) << endl;
	a.operator+(3).Show();
	Date c;
	c.operator=(a).Show();
	cout << c.operator-(a) << endl;
	Date d(2998, 7, 22);
	cout <<d.operator<(a)<< endl;
	Date f(2019, 10, 19);
	cout << f.operator>=(a) << endl;
	system("pause");
	return 0;
}