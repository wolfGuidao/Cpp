#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>


#include<stdio.h>

//十六转八进制
#include<stdio.h>
#include<math.h>
int ShiLiuZhuanBa(char *a, int len)
{
	int sum = 0;
	int i = 0;
	int j = 0;
	for (i = 0;i < len;i++)
	{
		switch (a[i])
		{
		case 'a':
			a[i] = 10 + '0';
			break;
		case 'b':
			a[i] = 11 + '0';
			break;
		case 'c':
			a[i] = 12 + '0';
			break;
		case 'd':
			a[i] = 13 + '0';
			break;
		case 'e':
			a[i] = 14 + '0';
			break;
		case 'f':
			a[i] = 15 + '0';
			break;
		default:
			break;
		}
	}
	for (i = 0;i < len;i++)
	{
		sum += (a[i] - '0') * pow((double)16, (len - i - 1));
	}
	return sum;
}

void Ba(int sum)
{
	int i = 0;
	int m[20] = { 0 };
	int n = 0;
	while (sum != 0)
	{
		m[n++]=sum % 8;
		sum = sum / 8;
	}
	for (i = n-1;i >=0;i--)
	{
		printf("%d", m[i]);
	}
}

int main()
{
	int sum = 0;
	char a[] = "8f34ab";
	int len = strlen(a);
	sum=ShiLiuZhuanBa(a, len);
	Ba(sum);
	//printf("%d", sum);
	system("pause");
	return 0;
}



//快排
#include<stdio.h>
int Mid(int *date, int left, int right)
{
	int value = date[left];
	while (left < right)
	{
		while (left < right&&date[right] >= value)
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