#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#if 0
//大数阶乘001
#include<stdio.h>
void JieCheng(int n)
{
	int a[2000];
	int i = 0;
	int j = 0;
	int weishu = 1;
	int tem = 0;//临时存储
	a[0] = 1;
	for (i = 2;i <= n;i++)
	{
		int num = 0;
		for (j = 0;j < weishu;j++)
		{
			tem = a[j] * i + num;
			a[j] = tem % 10;
			num = tem / 10;
		}
		while (num)
		{
			a[weishu] = num % 10;
			num = num / 10;
			weishu++;
		}
	}
	for(i=weishu-1;i>=0;i--)
	{
		printf("%d", a[i]);
	 }
}
int main()
{
	int n = 0;
	while (n != EOF)
	{
		printf("请输入要求阶乘得数：\n");
		scanf("%d", &n);
		JieCheng(n);
	}
	system("pause");
	return 0;
}



大数阶乘
#include<stdio.h>
int main()
{
	int a[2000];
	int n = 0;
	int i = 0;
	int j = 0;
	int num = 0;//判断是否进位
	int temp = 0;//临时存储结果
	while (n != EOF)
	{
		int weishu = 1;//如果进位就加一
		a[0] = 1;
		printf("请输入要求阶乘的数:");
		scanf("%d", &n);
		for (i = 2;i <= n;i++)
		{
			num = 0;
			for (j = 0;j < weishu;j++)
			{
				temp = a[j] * i + num;
				a[j] = temp % 10;
				num = temp / 10;
			}
			while (num)
			{
				a[weishu] = num % 10;
				num /= 10;
				weishu++;
			}

		}
		for (i = weishu - 1;i >= 0;i--)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	cout << "hello world "<< endl;
	system("pause");
	return 0;
}
#endif