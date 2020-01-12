#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
//大整数阶乘
#define N 10000
int main()
{
	int a[N] = { 1 };
	int k = 0, l = 1, n;
	int i, j;
	scanf("%d", &n);
	for (i = 1;i <= n;i++)
	{
		for (j = 0;j < l;j++)
		{
			a[j] = a[j] * i + k;
			k = a[j] / 10000;
			a[j] = a[j] % 10000;
		}
		if (k)
		{
			a[j] = k;
			l++;
			k = 0;
		}
	}
	printf("%d", a[l - 1]);
	for (i = l - 2;i >= 0;i--)
		printf("%04d", a[i]);
	printf("\n");
	system("pause");
	return 0;
}


#if 0
//对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：
//00000
//00001
//00010
//00011
//00100
//请按从小到大的顺序输出这32种01串。

#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	int p = 0;
	for (i = 0;i <= 1;i++)
	{
		for (j = 0;j <= 1;j++)
		{
			for (m = 0;m <= 1;m++)
			{
				for (n = 0;n <= 1;n++)
				{
					for (p = 0;p <= 1;p++)
					{
						printf("%d%d%d%d%d\n", i, j, m, n, p);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

//打印下图规律字符串
//ABCDEFG
//BABCDEF
//CBABCDE
//DCBABCD
//EDCBABC

#include<stdio.h>
void TuXin(int x, int y)
{
	char str = 'A';
	int i = 0;
	int j = 0;
	char a[26][26] = { 0 };
	for (i = 0;i < x;i++)
	{
		str = 'A';
		for (j = i;j < y;j++)
		{
			a[i][j] = str++;
		}
		str = 'A';
		for (j = i - 1;j >= 0;j--)
		{
			a[i][j] = ++str;
		}
	}
	for (i = 0;i < x;i++)
	{
		for (j = 0;j < y;j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int x = 8;
	int y = 8;
	TuXin(x,y);
	system("pause");
	return 0;
}
//杨辉三角
#include<stdio.h>
void YH(int n)
{
	int a[5][5] = { 0 };
	int i = 0;
	int j = 0;
	int p = sizeof(a) / sizeof(a[0]);
	int q = sizeof(a[0]) / sizeof(a[0][0]);
	//printf("%d  %d", p, q);
	for (i = 0;i < p;i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
		for (j = 1;j < i;j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (i = 0;i < p;i++)
	{
		for (j = 0;j <= i;j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n = 5;
	YH(n);
	system("pause");
	return 0;
}





//求五位数和六位数的回文数，且每位之和等于你输入的值n

#include<stdio.h>
	int main()
	{
		int a, b, c, d, e, f, t, all;
		printf("输入你要等于的值");
		scanf("%d", &t);
		for (a = 1;a < 10;a++)
			for (b = 0;b < 10;b++)
				for (c = 0;c < 10;c++)
					for (d = 0;d < 10;d++)
						for (e = 0;e < 10;e++)
						{
							if (a == e)
								if (b == d)
								{
									all = a + b + c + d + e;
									if (all == t)
										printf("%d\n", a * 10000 + b * 1000 + c * 100 + d * 10 + e);
								}
						}
		for (a = 1;a < 10;a++)
			for (b = 0;b < 10;b++)
				for (c = 0;c < 10;c++)
					for (d = 0;d < 10;d++)
						for (e = 0;e < 10;e++)
							for (f = 0;f < 10;f++)
							{
								if (a == f)
									if (b == e)
										if (c == d)
										{
											all = a + b + c + d + e + f;
											if (all == t)
												printf("%d\n", a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f);
										}
							}
        system("pause");
		return 0;
	}

#endif
