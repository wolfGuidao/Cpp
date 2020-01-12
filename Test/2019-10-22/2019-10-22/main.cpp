#include<iostream>
#include<windows.h>
using namespace std;
#if 0
void Swap( int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
     int a = 3;
    int b = 4;
	Swap(&a, &b);
	cout << a << b << endl;
	system("pause");
	return 0;
}
int main()
{
	/*cout << "c:\\code\\test.c" << endl;
	cout << "\\\\" << endl;
	cout << "\\%" << endl;
	cout << "%%%%" << endl;*/
	//printf("%%%%");
	/*printf("%d\n", '\14');
	printf("%d\n", '\x14');*/
	cout << strlen("c:\test\328\test.c") << endl;
	printf("%d\n", strlen("c:\test\328\test.c"));
	cout << strlen("\328") << endl;
	//cout << strlen("200") << endl;
	//cout << strlen("\123") << endl;
	system("pause");
	return 0;
}

class Date
{
public:
	Date()
	{
		_year = 1998;
		_month = 7;
		_day = 22;
	}


	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	~Date()
	{
		_year = 1998;
		_month = 7;
		_day = 22;
	}

	Date(Date& ra)
	{
		_year = ra._year;
		_month = ra._month;
		_day = ra._day;
	}

	Date& operator=(Date& ra)
	{
		_year = ra._year;
		_month = ra._month;
		_day = ra._day;
		return *this;
	}

	Date& operator+(int day)
	{
		_day += day;
		return *this;
	}

	Date& operator-(int day)
	{
		_day -= day;
		return *this;
	}

	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	Date operator++(int)//后置++因为要返回没有加1之前的，所以创建类类型变量（不能是类类型的引用）存储起来，方便返回，注意和前置++返回值及参数的区别
	{
		Date temp = *this;
		_day += 1;
		return temp;
	}

	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp = *this;
		_day -= 1;
		return temp;
	}

	bool operator>(const Date& ra)const
	{
		if (_year > ra._year)
		{
			return true;
		}
		else if(_year==ra._year &&_month>ra._month )
		{
			return true;
		}
		else if (_year == ra._year &&_month == ra._month&&_day > ra._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Date& ra)const
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
		if (this->operator>(ra) || this->operator==(ra))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (const Date& ra)const
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

	bool operator<=(const Date& ra)const
	{
		if (this->operator<(ra) || this->operator==(ra))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Date& ra)const
	{
		if (this->operator==(ra))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date a(2019, 10, 20);
	a.Show();
	Date b(a);
	b.Show();
	Date c(2019, 10, 22);
	c.Show();
	/*a.operator+(3).Show();
	b.operator-(3).Show();
	a.operator++(1).Show();
	b.operator--(1).Show();
	a.Show();
	b.Show();*/
	//cout << a.operator>(b) << endl;
	//cout << a.operator==(b) << endl;
	//cout << a.operator>=(c) << endl;
	cout << a.operator!=(b) << endl;
	cout << a.operator<=(b) << endl;
	cout << a.operator!=(c) << endl;
	cout << a.operator<=(c) << endl;
	system("pause");
	return 0;
}
#endif

class Time
{
public:
	Time(int hour, int min, int s)
	{
		_hour = hour;
		_min = min;
		_s = s;
	}
private:
	int _hour;
	int _min;
	int _s;
};

//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int _a;
//	Time _t;
//public:
//	
//
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_a(99)
//		,_t(15,58,45)
//	{
//		
//	}
//
//	void Show()
//	{
//		cout << _year << "-"<<_month <<"-"<< _day <<"-"<<_a<< endl;
//	}
//};
class Date
{
private:
	int _year;
	int _month;
	int _day;
	//const int _a;
	//Time _t;
public:


	Date(int year)
		:_year(year)
		
	{

	}

	void Show()
	{
		cout << _year << "-" << _month << "-" << _day << "-" << endl;
	}
};
int main()
{
	Date a(1998);
	//cout<<a
	system("pause");
	return 0;
}