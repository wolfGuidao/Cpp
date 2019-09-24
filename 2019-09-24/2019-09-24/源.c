#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>

//有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。
//
//给定一个NxN的矩阵，和矩阵的阶数N, 请返回旋转后的NxN矩阵, 保证N小于等于300。
//
//测试样例：
//[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 3
//返回：[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
#include<stdio.h>
int main()
{
	int a[][4] = { {1,2,3,4} ,{5,6,7,8,},{9,10,11,12},{13,14,15,16} };
	int i = 0;
	int j = 0;
	int k = 0;
	int b[4][4] = { 0 };
	for (i = 0;i < 4;i++)
	{
		for (j = 3;j >=0;j--)
		{
			b[i][k++] = a[j][i];
		}
		k = 0;
	}
	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 4;j++)
		{
			printf("%-3d", b[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

//对于一个矩阵，请设计一个算法，将元素按“之”字形打印。具体见样例。
//
//给定一个整数矩阵mat，以及他的维数nxm，请返回一个数组，其中元素依次为打印的数字。
//
//测试样例：
//[[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]], 4, 3
//返回：[1, 2, 3, 6, 5, 4, 7, 8, 9, 12, 11, 10]

#include<stdio.h>
int main()
{
	int a[][3] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
	int m = 4;
	int n = 3;
	int i = 0;
	int j = 0;
	int p = 0;
	int b[12];
	int q = 0;
	for (i = 0;i < m;i++)
	{
		if (p % 2 == 0)
		{
			for (j = 0;j < n;j++)
			{
				b[q++] = a[i][j];
			}
		}
		else
		{
			for (j = n-1;j >= 0;j--)
			{
				b[q++] = a[i][j];
			}
		}
		p++;
	}
	for (j = 0;j < 12;j++)
	{
		printf("%d, ", b[j]);
	}
	system("pause");
	return 0;
}



//对于一个字符串，和字符串中的某一位置，请设计一个算法，将包括i位置在内的左侧部分移动到右边，将右侧部分移动到左边。
//
//给定字符串A和它的长度n以及特定位置p，请返回旋转后的结果。
//
//测试样例：
//"ABCDEFGH", 8, 4
//返回："FGHABCDE"
#include<stdio.h>
void NiZi(char *p, int len, int n)
{
	char *q = p + len;
	char *m = p;
	int i = 0;
	while (i < n)
	{
		*q = *m;
		q++;
		m++;
		i++;
	}
	*q = '\0';
}
int main()
{
	int i = 0;
	char p[] = "abcdefgh";
	int len = strlen(p);
	int len1 = 0;
	int n = 4;
	NiZi(p, len, n);
	len1 = strlen(p);
	for (i = n;i < len1;i++)
	{
		printf("%c", p[i]);
	}
	//printf("%d", len1);
	system("pause");
	return 0;
}



#include <stdio.h>
#include <string.h>

#define N 100
int main()
{
	char s[N];
	int n;
	int p;
	int i;
	int j;
	char ch;

	printf("Enter string(<=100):");
	fgets(s, N, stdin);
	printf("Enter len:");
	scanf("%d", &n);
	printf("Enter the location move(<=%d):", n - 1);
	scanf("%d", &p);

	for (i = 0; i < n - p - 1; i++)
	{
		ch = s[n - 1];
		for (j = n - 1; j >= 1; j--)
		{
			s[j] = s[j - 1];
		}
		s[0] = ch;
	}

	printf("the result:%s", s);
	system("pause");
	return 0;
}
