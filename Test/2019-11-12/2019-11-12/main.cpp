#include<iostream>
using namespace std;

#if 0

void main()
{
	int n;
	int i;
	int sum = 1;
	printf(“输入一个整数n:\n”);
	scanf("%d", &n);
	for (i = 2;i <= n;i++)
	{
		sum *= i;
		while (sum % 10 == 0)
		{
			sum /= 10;
		}
		sum = sum % 10;
	}
	printf("%d", sum);
}
#endif


#include<set>

void Test()
{
	int n;
	int i;
	int sum = 1;
	printf("输入一个整数n:\n");
	while (cin >> n)
	{
		sum = 1;
		for (i = 2;i <= n;i++)
		{
			sum *= i;
			while (sum % 10 == 0)//在乘的过程中如果发现结果有0，就直接去掉，因为输出结果不是阶乘结果，
			{
				sum /= 10;
			}
			sum = sum % 10;
		}
		printf("%d\n", sum);
	}
}

void Test1()
{
	char s;
	while (s = getchar())
	{
		cout << s << endl;
	}
}

void Test2()
{
	int n ;
	int i = 2;
	int sum = 1;
	while (cin >> n)
	{
		sum = 1;
		for (i = 2;i <= n;i++)
		{
			sum *= i;

			while (sum % 10 == 0)
			{
				sum /= 10;
			}
			sum = sum % 10;
		}
		cout << sum << endl;
	}
}
void Test3()
{
	
}
//int main()
//{
//	//Test();
//	//Test1();
//	Test2();
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<Windows.h>
int main()
{
	const char* lable = "/-\\|";
	char buf[1024] = { 0 };
	int i = 0;
	for (;i <= 100;i++)
	{
		buf[i] = '#';
		printf("[%d%%][%c][%s]\r", i, lable[i % 4], buf);
		fflush(stdout);
		Sleep(50);
	}
	return 0;
}