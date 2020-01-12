#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
int Mid(int *date, int left, int right)
{
	int value = date[left];
	while (left < right)
	{
		while (left<right&&date[right]>=value)
		{
			right--;
		}
		date[left] = date[right];
		while (left < right&&date[left] <= value)
		{
			left++;
		}
		date[right] = date[left];
	}
	date[left] = value;
	return left;
}
void KPai(int *date, int left, int right)
{
	if (left < right)
	{
		int mid = Mid(date, left, right);
		KPai(date, left, mid - 1);
		KPai(date, mid + 1, right);
	}
}
int main()
{
	int i = 0;
	int a[] = { 8,20,11,3,6,4,9,2,3,7 };
	KPai(a, 0, 9);
	for (i = 0;i < 10;i++)
	{
		printf("%d   ", a[i]);
	}
	printf("\b");
	system("pause");
	return 0;
}

#if 0

//问题描述
//给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1 <= n <= 200
//输入格式
//第一行为一个整数n。
//第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
//输出格式
//输出一行，按从小到大的顺序输出排序后的数列。
//样例输入
//5
//8 3 6 4 9
//样例输出
//3 4 6 8 9

int Split(int *data, int pre, int rear)
{
	int value = data[pre];
	while (pre < rear)
	{
		while (data[rear] >= value && pre < rear) rear--;
		data[pre] = data[rear];
		while (data[pre] < value && pre < rear) pre++;
		data[rear] = data[pre];
	}
	data[pre] = value;
	return pre;
}

//快速排序
void QuickSort(int *data, int pre, int rear)
{
	if (pre < rear)
	{
		int mid = Split(data, pre, rear);
		QuickSort(data, pre, mid - 1);
		QuickSort(data, mid + 1, rear);
	}
}


int main()
{
	int i = 0;
	int a[] = { 8,20,11,3,6,4,9,2,3,7 };
	QuickSort(a, 0, 9);
	for (i = 0;i < 10;i++)
	{
		printf("%d < ", a[i]);
	}
	printf("\b");
	system("pause");
	return 0;
}


//Fibonacci数列的递推公式为：Fn = Fn - 1 + Fn - 2，其中F1 = F2 = 1。
//当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
//输入格式
//输入包含一个整数n。
//输出格式
//输出一行，包含一个整数，表示Fn除以10007的余数。
//说明：在本题中，答案是要求Fn除以10007的余数，因此我们只要能算出这个余数即可，而不需要先计算出Fn的准确值，再将计算的结果除以10007取余数，直接计算余数往往比先算出原数再取余简单。
//样例输入
//10
//样例输出
//55
//样例输入
//22
//样例输出
//7704
#include<stdio.h>
#define N 10007
int Fn(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
		return (Fn(n - 1) + Fn(n - 2))%10007;
}
int main() 
{
	int n = 122;
	int a = 0;
	a = Fn(n);
	printf("%d", a);
	system("pause");
	return 0;
}

#endif