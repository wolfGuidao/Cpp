#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10

int quickSortchild(int* str, int start, int end)
{
	int temp = str[start];
	while (start < end)
	{
		while (start < end&&str[end] >= temp)
		{
			end--;
		}
		str[start] = str[end];
		while (start < end&&str[start] < temp)
		{
			start++;
		}
		str[end] = str[start];
	}
	str[start] = temp;
	return start;
}
void quickSort(int *str, int start, int end)//快排非递归,栈用数组代替栈
{
	int stack[MaxSize*2];//*2是为了保证最坏情况下，防止溢出
	int top = 0;
	int mid = quickSortchild(str,start,end);//先进行一趟快速排序，得到一个mid,
	if (start + 1 < mid)//如果mid左边还有两个元素以上，分别把start,mid-1入栈
	{
		stack[top++] = start;
		stack[top++] = mid - 1;
	}
	if (end - 1 > mid)//如果mid右边还有两个元素以上，分别把mid+1,end入栈
	{
		stack[top++] = mid + 1;
		stack[top++] = end;
	}
	while (top > 0)//如果栈不为空，每次出栈两个元素作为start,end，但一定要注意顺序，别反了
	{
		end = stack[--top];
		start = stack[--top];

		mid = quickSortchild(str, start, end);
		if (start + 1 < mid)
		{
			stack[top++] = start;
			stack[top++] = mid - 1;
		}
		if (end - 1 > mid)
		{
			stack[top++] = mid + 1;
			stack[top++] = end;
		}
	}
	//栈空，代表每进行一趟快排得到的mid左右各只有一个元素，即排序完成
}

void adjust(int *str ,int start,int end)//该函数是把整棵树调整为大根堆
{
	int temp = str[start];
	int i = 0;
	for (i = 2 * start + 1;i <= end;i = i * 2 + 1)//此处i是控制叶子节点，i = i * 2 + 1是为了防止还有子树，
	{
		if (str[i] < str[i + 1]&&(i<end))//比较两个叶子节点，得到叶子中数值大的下标
		{
			i++;
		}
		if (str[i] > temp)//如果叶子节点比当前跟节点大，就交换
		{
			str[start] = str[i];
			start = i;//start往下移是为了防止还有子树
		}
		else
		{
			break;
		}
	}
		str[start] = temp;
}
void DuiPaiSort(int *str,int len)//堆排
{
	int i = (len - 1 -1 ) >> 1;//得到数组构成一颗树的最后一个子根节点，控制调整为大根堆的次数
	int j = 0;
	for (;i >= 0;i--)
	{
		adjust(str,i,len);
	}//循环结束，就把整棵树调整为大根堆
	for (j = 0;j < len-1;j++)
	{
		int temp = str[len-1-j];//把树最后一个节点和第一个根节点互换
		str[len - 1 - j] = str[0];
		str[0] = temp;
		adjust(str, 0, len - 1 - j - 1);//再次进行调整，得到一个大根堆，继续交换
	}

}

void mergeChild(int *str,int start,int mid,int end)
{
	int strtemp[MaxSize];
	int strtempIndex = start;
	int start2 = mid + 1;
	int i = start;
	while (start <= mid && start2 <= end)
	{
		if (str[start] <= str[start2])
		{
			strtemp[strtempIndex++] = str[start++];
		}
		else
		{
			strtemp[strtempIndex++] = str[start2++];
		}
	}
	while (start <= mid)
	{
		strtemp[strtempIndex++] = str[start++];
	}
	while (start2 <= end)
	{
		strtemp[strtempIndex++] = str[start2++];
	}
	while(i<=end)
	{
		str[i] = strtemp[i];
		i++;
	}
}
void mergeSort(int *str,int start,int end)
{
	if (start >= end)
	{
		return ;
	}
	int mid = (start + end) >> 1;
	mergeSort(str, start,mid);//分解
	mergeSort(str, mid + 1, start);

	mergeChild(str,start , mid ,end);//合并、排序
}
void Printf(int *str, int len)
{
	int i = 0;
	for (;i < len;i++)
	{
		printf("%d < ", str[i]);
	}
	printf("\n");
}

void sortTest()
{
	int str[] = { 2,34,45,6275,13,34,784,36,0,111 };
	int len = sizeof(str) / sizeof(str[0]);
	printf("快排非递归：\n");
	quickSort(str, 0, len - 1);
	Printf(str, len);

	int str1[] = { 999999,34,5,65,19,94,4,93,99,911 };
	int len1 = sizeof(str1) / sizeof(str1[0]);
	printf("堆排：\n");
	DuiPaiSort(str1, len1);
	Printf(str1, len1);

	int str2[] = { 2999999,34,995,65,19399,9934,9784,936,909,199911 };
	int len2 = sizeof(str2) / sizeof(str2[0]);
	printf("归并排序：\n");
	mergeSort(str2, 0,len2-1);
	Printf(str2, len2);
}
int main()
{
	sortTest();
	system("pause");
	return 0;
}

#if 0
int main()
{
	int n = 0;
	int a[2000];//存储结果
	int temp;//临时存储计算结果
	int i = 0;
	int j = 0;
	int num;
	int weishu ;//和num一起，如果发生进位，位数即数组长度加1
	while (n != EOF)
	{
		printf("请输入要计算阶乘n的值：");
		scanf("%d", &n);
		a[0] = 1;
		weishu = 1;//该程序多次进行阶乘运算，所以每次都要置为1；
		for (i = 2;i <= n;i++)
		{
			num = 0;//如果循环还没结束，记录进位值，往下一位上加,每次循环前都要置为0
			for (j = 0;j < weishu;j++)//该循环保证数组每一位都乘以n
			{
				temp = a[j] * i + num;
				a[j] = temp % 10;
				num = temp / 10;
			}
			while (num)//该循环是保证每次j循环的最后一次*n结束后，如果发生进位，就直接往数组里面存储并且位数++
			{
				a[weishu++] = num % 10;
				num /= 10;
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
				a[weishu++] = num % 10;
				num /= 10;
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
	int a;
	int b;
	cout << "请输入a,b的值" << endl;
	cin >> a >> b;
	cout << a + b << endl;
	cout << a * b << endl;
	cout << "hello world!"<< endl;
	system("pause");
	return 0;
}
#endif