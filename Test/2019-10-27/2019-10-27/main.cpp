#include<iostream>
#include<Windows.h>
#include<string>
//int a = 10;
using namespace std;
//template<class T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	/*enum WM
//	{
//		MAN,
//		WOMAN
//	};*/
//	//printf("%d", Add<char>('1', '2'));
//	//cout << Add(1.1, 2.2);
//	/*printf("%d\n", '0');
//	printf("%d\n", '\0');
//	printf("%d\n", 48);*/
//
//	
//	/*enum WM b=MAN;
//	cout << a << endl;
//	cout << b << endl;
//	printf("%s",b );*/
//	system("pause");
//	return 0;
//}
void TestString1()
{
	string a("hello world");//构造函数
	cout << a << endl;
	string b(a);//拷贝构造
	cout << b << endl;
	string c = a;//赋值运算符重载
	cout << c << endl;
	string d;
	cout << d << endl;
	string e(7, 'a');//拷贝7个字符'a',
	cout << e << endl;
}

void TestString2()
{
	string a("hello world");
	cout << a.size() << endl;//元素个数
	cout << a.length() << endl;//元素个数
	cout << a.capacity() << endl;//空间容量
	cout << a.empty() << endl;//判空；空为1；不空为：0
	a.clear();//清理释放
	cout << a.size() << endl;
	cout << a.length() << endl;
	cout << a.capacity() << endl;
	cout << a.empty() << endl;

}

void TestString3()
{
	string a("wolf guidao");
	a.reserve(20);//将空间改变，扩容一般capacity会变，容量变小不一定会改变
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	
	a.reserve(40);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.reserve(30);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.reserve(14);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.reserve(8);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.resize(10, '!');
	cout << a << endl;

	a.resize(20, '!');
	cout << a << endl;	
}

void TestString4()
{
	string a("wolf guidao");//下标访问
	cout << a[0] << a[4] << endl;
	//cout << a[20];
	cout << a.at(0) << a.at(4) << endl;
	for (auto i : a)//范围for打印
	{
		cout << i;//i就是对象中每个元素的拷贝
	}
	cout << endl;
	for (int i = 0;i < a.size();i++)
	{
		cout << a[i];
	}
	cout << endl;
	string::iterator it = a.begin();//迭代器遍历输出
	while (it != a.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}

void TestString5()
{
	string a("wolf guidao");
	a.push_back(' ');//往末尾追加一个字符
	a.push_back('I');
	a.append(" Love");//往末尾追加一个字符串
	a += ' ';//运算符重载
	a.append("you");
	cout <<a.c_str() << endl;//转为C格式字符
	string b ("hello world");
	cout << b.c_str() << endl;;
	cout << a << endl;
}

void TestString6()
{
	string a("wolf guidao");
	//cout << a.find('o') << endl;
	a[a.find('w')] = 'W';
	cout << a << endl;
	a[a.rfind('g')] = 'G';
	cout << a << endl;
	cout << a.find("lf") << endl;
	if (a.find("lf") == string::npos)//npos是一个常量；值为-1；一般表示不存在；因为如果在find或rfind中找到字符或字符串就会返回对应下标，一旦没有找到，就会返回npos
	{
		cout << "未找到字符" << endl;
	}
	else
	{
		cout << "找到该字符" << endl;
	}


	if (a.find('o',1)==string::npos)
	{
		cout << "未找到字符" << endl;
	}
	else
	{
		cout << "找到该字符" << endl;
	}
	
	cout << a.substr(a.find(' ')) << endl;
	cout << a.substr() << endl;//默认从开始截取所有字符
	cout << a.substr(0, 4) << endl;
	cout << a.substr(2, 20) << endl;//从2开始截取20个字符

}

void TestString7()
{
	string a;
	//cin >> a;//注意cin/cout遇到空格就算一个字符串，所以如果输入字符串中有空格就得用getline（）获取一行字符串
	string b;
	//cin >> b;
	getline(cin, a);//注意用法
	getline(cin, b);
	cout << a << endl;
	cout << b << endl;
	

}

void TestString8()
{
	string a("wolf guidao");
	string b("wolf Guidao");
	cout << a << endl;
	cout << b << endl;
	swap(a, b);
	cout << a << endl;
	cout << b << endl;
	int x = 10;
	int y = 20;
	swap(x, y);
	cout << x << endl;
	cout << y << endl;
	//cout << a > b  << endl;

}

void TestString9()
{
	string a("12345");
	string b("wolf guidao");
	//b += a;
	reverse(b.begin()+2,b.end()-2);
	string::iterator it = b.begin(); it < b.end();
	//b.erase(0,1);
	cout << b << endl;
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	TestString9();

	system("pause");
	return 0;
}