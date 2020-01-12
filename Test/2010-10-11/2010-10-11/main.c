#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 100
//高精度加法：两个大整数非负
int main()
{
	char a[MaxSize];
	char b[MaxSize];
	char c[MaxSize];
	int i = 0;
	for (;i < MaxSize;i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	printf("请输入第一个大整数：\n");
	scanf("%s", &a);
	printf("请输入第一个大整数：\n");
	scanf("%s", &b);
	int lena = strlen(a);
	int lenb = strlen(b);
    for (i=0;i < lena || i < lenb;i++)
	{
		/*因为字符串往数组里面存的时候都是从数组首元素开始存的，即数组第0位都存着两个大整数的最高位，数组第1位存两个
		大整数次高位，以此类推，*/
		if (i < lena)
		{
			c[i] += a[lena - 1 - i]-'0';//因为相加的时候都是从最低为开始相加，即两个数组的最后一位最先开始相加
		}
		if (i < lenb)
		{
			c[i] += b[lenb - i - 1]-'0';
		}
		if (c[i] >= 10)
		{
			c[i + 1] = c[i] / 10;//从C数组第1位开始存储和
			c[i] = c[i] % 10;
		}
	}
	if (lena < lenb)//取得两数组较大的长度
	{
		lena = lenb;
	}
	if (c[lena] > 0)
	{
		printf("%d", a[lena]);
	}
	for (i = lena - 1;i >= 0;i--)//输出
	{
		printf("%d", c[i]);
	}
	system("pause");
	return 0;
}