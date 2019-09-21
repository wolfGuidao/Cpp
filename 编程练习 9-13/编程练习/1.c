#define _CRT_SECURE_NO_WARNINGS 
//罗马数字包含以下七种字符 : I， V， X， L，C，D 和 M。
//	字符          数值
//	I             1
//	V             5
//	X             10
//	L             50
//	C             100
//	D             500
//	M             1000
//	例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X  + II 。 27 写做  XXVII, 即为 XX  + V  + II 。
//	通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的
//左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//	给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
//	示例 :
//		输入: "III"
//		输出 : 3

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[100] = { 0 };
	int b = 0;
	int i = 0;
	int len = 0;
	while (1)
	{
		for (i = 0;i < 100;i++)
		{
			scanf("%c", &a[i]);
			if (a[i] == '0')//输入0，结束输入
			{
				break;
			}
		}
		break;
	}
	len = strlen(a);
	for (i = 0;i < len;i++)
	{
		if ((a[i] == 'I') && (a[i + 1] == 'V' || a[i + 1] == 'X'))
		{
			a[i] = 'O';
		}
		if ((a[i] == 'X') && (a[i + 1] == 'L' || a[i + 1] == 'C'))
		{
			a[i] = 'P';
		}
		if ((a[i] == 'C') && (a[i + 1] == 'D' || a[i + 1] == 'M'))
		{
			a[i] = 'Q';
		}
		switch (a[i])
		{
		case 'I':b += 1;
			break;
		case 'V':b += 5;
			break;
		case 'X':b += 10;
			break;
		case 'L':b += 50;
			break;
		case 'C':b += 100;
			break;
		case 'D':b += 500;
			break;
		case 'M':b += 1000;
			break;
		case 'O':b -= 1;
			break;
		case 'P':b -= 10;
			break;
		case 'Q':b -= 100;
			break;
		}
	}
	printf("%d", b);
	system("pause");
	return 0;
}







#if 0
//罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X  + II 。 27 写做  XXVII, 即为 XX  + V  + II 。
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
//所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
//示例 :
//输入: 3
//输出 : "III"
#include<stdio.h>
void Zhuanhuan(int n)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int j;
	while(n >= 1000)
	{
		a = n / 1000;
		for (j = 0;j < a;j++)
		{
			printf("M");
			
		}
		n = n - 1000 * a;
	}
	while (n >= 500)
	{
		if (n == 900)
		{
			printf("CM");
			n = -1;
			break;
		}
			printf("D");
			n = n - 500;
	}
	while (n > 100)
	{
		if (n == 400)
		{
			printf("CD");
			n = -1;
			break;
		}
		b = n / 100;
		for (j = 0;j < b;j++)
		{
			printf("C");
		}	
		n = n - 100 * b;
	}
		
	while (n >= 50)
	{
		if (n == 90)
		{
			printf("XC");
			n = -1;
			break;
		}
		printf("L");
		n = n - 50;
	}
	while (n >= 10)
	{
		if (n == 40)
		{
			printf("XL");
			n = -1;
			break;
		}
		c = n / 10;
		for (j = 0;j < c;j++)
		{
			printf("X");
		}
		n = n - 10 * c;
	}
	while (n >= 5)
	{
		if (n == 9)
		{
			printf("IX");
			n = -1;
			break;
		}
		printf("V");
		n = n - 5;
	}
	while (n > 0)
	{
		if (n == 4)
		{
			printf("IV");
			n = -1;
			break;
		}
		for (j = 0;j < n;j++)
		{
			printf("I");
		}
		break;
	}
	while (n == -1)
	{
		return ;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	Zhuanhuan(n);
	system("pause");
	return 0;
}


//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个
//端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//输入: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//输出 : 49
#include<stdio.h>
int Min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int a[] = { 1,8,6,2,5,4,8,3,7 };
	int i,j=0;
	int m = Min(a[0], a[1]);
	for (i = 0;i < 9;i++)
	{
		for (j = i + 1;j < 9;j++)
		{
			;
			if (Min(a[i], a[j])*(j - i)>m)
			{
				m = Min(a[i], a[j])*(j - i);
			}
		}
	}
	printf("%d", m);
	system("pause");
	return 0;
}





//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//输入: 123
//输出 : 321
#include<stdio.h>
int main()
{
	int n=123456789;
	long int m = 0;
	int a = 0;
	while (n != 0)
	{
		a = n % 10;
		n /= 10;
		m = m * 10 + a;
	}
	printf("%d", m);
	system("pause");
	return 0;
}




//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//输入: "abcabcbb"
//输出: 3
//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
#include<stdio.h>
#include<string.h>
int main()
{
	char a[] = "aadgghagfg";
	int b[9];
	int i = 0;
	int k;
	int j = 0;
	int max ;
	int len = strlen(a);
	for (i = 0;i < len;i++)
	{
		for (b[i]=1,j = i + 1;j < len;b[i]++,j++)
		{
			for (k = i;k < j;k++)
			{
				
				if (a[k] == a[j])
				{
					break;
				}
			}
			if (k < j)
			{
				break;
			}
		}
	}
	max = b[0];
	for (i = 0;i < 9;i++)
	{
		if (b[i] > max)
		{
			max = b[i];
		}
	}
	printf("%d", max);
	system("pause");
	return 0;
}

#endif
