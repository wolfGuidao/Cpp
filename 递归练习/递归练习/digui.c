//非递归实现strlen
#include<stdio.h>
int Strlen(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;
	}
	return count;
}
int main()
{
	char a[] = "abcdefghijk";
	int ret = Strlen(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}



#if 0
//递归分别实现strlen 
#include<stdio.h>
int Strlen(char* a)
{
	if (*a != '\0')
	{
		return 1 + mystrlen(a + 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char a[] = "abcdefghijk";
	int ret = Strlen(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}




// 编写一个函数 reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//当条件不成立时，跳出if，输出\0前面的字母，再跳出这个递归，输出倒数第二个，直到递归结束。
#include<stdio.h>
void reverse_string(char *string)
{
	if ('\0' != *(++string))
		reverse_string(string);
	printf("%c", *(string - 1));
}

int main()
{
	char *a = "abcde";
	reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}


//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
#include<stdio.h>
int DigitSum(int n)
{
	if (n >0)
	{
		return n%10 + DigitSum(n / 10);
	}
	return 0;
}
int main()
{
	int n = 12;
	int a = DigitSum(n);
	printf("%d", a);
	system("pause");
	return 0;
}



//非递归分别实现求n的阶乘
#include <stdio.h>
int main()
{
	int n = 4;
	int i = 0;
	int fac = 1;
	for (i = 1;i <= n;i++)
	{
		fac = fac * i;
	}
	printf("%d", fac);
	system("pause");
	return 0;
}


//递归方式实现打印一个整数的每一位 
#include<stdio.h>
void DaYin(int n)
{
	if (n > 9)
	{
		DaYin(n / 10);
	}
	printf("%d  ", n % 10);
}
int main()
{
	int n = 1234;
	DaYin(n);
	system("pause");
	return 0;
}


//编写一个函数实现n^k，使用递归实现
#include<stdio.h>
int NK(int n, int k) 
{
	if (k == 1)
	{
		return n;
	}
	return n * NK(n, k - 1);
}
int main()
{
	int n = 2;
	int k = 10;
	int a = 0;
	a = NK(n, k);
	printf("%d", a);
	system("pause");
	return 0;
}



//非递归实现求第n个斐波那契数
#include<stdio.h>
int main()
{
	int n = 5;
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	int i = 0;
	for (i = 0;i < n - 2;i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	printf("%d", f3);
	system("pause");
	return 0;
}




//递归实现求第n个斐波那契数
#include<stdio.h>
int FeiBoNaQie(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FeiBoNaQie(n - 1) + FeiBoNaQie(n - 2);
}
int main()
{
	int a = 0;
	a = FeiBoNaQie(5);
	printf("%d", a);
	system("pause");
	return 0;
}


//递归逆置数组
#include<stdio.h>

void niarr(int arr[],int len,int left,int right)
{
	int i = 0;
	int temp = 0;
	if (left >= right)
	{
		for (i = 0;i < len;i++)
		{
			printf("%d   ", arr[i]);
		}
		return;
	}
	else 
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		niarr(arr, len, ++left, --right);
	}	
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	niarr(arr, 10, 0, 9);
	system("pause");
	return 0;
}



//递归输出整数的每一位
#include<stdio.h>
void Printf(int n)
{
	if (n > 9)
	{
		Printf(n / 10);
	}
	printf("%d  ", n % 10);
}
int main()
{
	int n = 2365;
	Printf(n);
	system("pause");
	return 0;
}


//n的阶乘递归
#include<stdio.h>
int Fan(int n)
{
	if (n == 0||n==1)
	{
		return 1;
	}
	if (n > 1)
	{
		return n * Fan(n - 1);
	}
}
int main()
{
	int a = 0;
	int n;
	printf("请输入n的值，求阶乘\n");
	scanf_s("%d", &n);
	a = Fan(n);
	printf("%d", a);
	system("pause");
	return 0;
}
#endif 