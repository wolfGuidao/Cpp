#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
int main()
{
	int a[2000];
	int n=0;
	int weishu = 1;
	int i=0;
	int j=0;
	int tem = 0;
	a[0] = 1;
	printf("请输入n的值：\n");
	scanf("%d", &n);
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
			a[weishu++] = num % 10;
			num /= 10;
		}
	}
	for (i = weishu - 1;i >= 0;i--)
	{
		printf("%d", a[i]);
	}
	system("pause");
	return 0;
}
#if 0

#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>

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
	for (i = weishu - 1;i >= 0;i--)
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
#endif