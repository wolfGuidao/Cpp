#define _CRT_SECURE_NO_WARNINGS
//编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
#include<stdio.h>
int main()
{
	int m = 1;
	int n = 7;
	int a = 0;
	int count = 0;
	a = m ^ n;
	for (int i = 0;i < 32;i++)
	{
		if ((a >> i) & 1 == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}
#if 0
//输出一个整数的每一位。
#include<stdio.h>
void DaYin(int n)
{
	if (n > 9)
	{
		DaYin(n / 10);
	}
	printf("%d " ,n % 10);
}
int main()
{
	int n = 123784;
	DaYin(n);
	system("pause");
	return 0;
}


//获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
#include<stdio.h>
int main()
{
	int a = 7;
	int i = 0;
	int b[32] = { 0 };
	for (i = 0;i < 32;i++)
	{
		b[i] = ((a >> i) & 1);
	}
	printf("奇数位为：\n");
	for (i = 15;i >=0;i--)
	{
		printf("%d ",b[2*i]);
	}
	printf("\n偶数位为：\n");
	for (i = 15;i >= 0;i--)
	{
		printf("%d ", b[2 * i +1]);
	}
	system("pause");
	return 0;
}


//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
#include<stdio.h>
/*
int count_one_bits(int a)//第一种方法
{
	int i = 0;
	int count = 0;
	for (i = 0;i < 32;i++)
	{
		if (((a >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
*/

/*
int count_one_bits(int a)//第二种方法
{
	int count = 0;
	while (a != 0)
	{
		a=a&(a - 1);
		count++;
	}
	return count;
}
*/

int count_one_bits(int a)
{
	int count = 0;
	while (a != 0)
	{
		if (a % 2 == 1)
		{
			count++;
		}
		a = a / 2;
	}
	return count;
}
int main()
{





	int a = 4;
	int b = 0;
	b=count_one_bits(a);
	printf("%d", b);
	system("pause");
	return 0;
}
#endif