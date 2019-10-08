#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10
//尽量把几种常用的排序掌握熟练，多写几次


//快排
int quickSortChild(int *str, int left, int right)//一趟快速排序
{
	int temp=str[left];
	while (left < right)
	{
		while (left < right&&str[right] >= temp)
		{
			right--;
		}
		str[left] = str[right];
		while (left < right&&str[left] <= temp)
		{
			left++;
		}
		str[right] = str[left];
	}
	str[left] = temp;
	return left;
}
void quickSort(int *str, int left,int right)
{
	if (left < right)
	{
		int mid = quickSortChild(str, left, right);
		quickSort(str, left, mid - 1);
		quickSort(str, mid + 1, right);
	}
}


//冒泡排序
void MaoPao(int *str, int len)
{
	int i = 0;
	int j = 0;
	int temp;
	for (i = 0;i < len; i++)
	{
		for (j = i+1;j < len;j++)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}


//直接选择排序和冒泡排序基本一样


//堆排
void adjust(int *str,int start, int end)//该函数功能为把堆调整为大根堆
{
	int temp = str[start];
	int i = 0;
	for (i = 2 * start + 1;i <= end;i = i * 2 + 1)
	{
		if (str[i] < str[i + 1] && (i < end))
		{
			i++;
		}
		if (str[i] > temp)
		{
			str[start] = str[i];
			start = i;
		}
		else
		{
			break;
		}
	}
	str[start] = temp;
}
void heapSort(int *str, int len)
{
	int i = (len - 1 - 1) >> 1;//控制调整为大根堆所需要的次数
	int j = 0;
	int temp = 0;
	for (;i >= 0;i--)
	{
		adjust(str,i,len-1);//进行调整
	}
	for (j = 0;j < len;j++)
	{
		temp=str[len - 1 - j] ;
		str[len - 1 - j] = str[0];
		str[0] = temp;
		adjust(str, 0, len - 1 - j - 1);
	}
}


//快排优化：三数取中法
void Swap(int *str, int start, int end)
{
	int temp;
	temp = str[start];
	str[start] = str[end];
	str[end] = temp;
}
void medianOfThree(int * str, int low, int hight)
{
	int mid = (low + hight) >> 1;
	if (str[mid] > str[low])
	{
		Swap(str, mid, low);
	}
	if (str[mid] > str[hight])
	{
		Swap(str, mid, hight);
	}
	if (str[low] > str[hight])
	{
		Swap(str,low, hight);
	}
}
void quickSort2(int *str, int left, int right)
{
	if (left < right)
	{
		medianOfThree(str, left, right);
		int mid = quickSortChild(str, left, right);
		quickSort(str, left, mid - 1);
		quickSort(str, mid + 1, right);
	}
}


//快排非递归
void quicksort3(int *str, int len)
{
	int stack[MaxSize*2];
	int top = 0;
	int low = 0;
	int hight = len-1;
	int mid = quickSortChild(str, low, hight);
	if (low + 1 < mid)
	{
		stack[top++] = low;
		stack[top++] = mid-1;
	}
	if (hight - 1 > mid)
	{
		stack[top++] = mid + 1;
		stack[top++] = hight;
	}
	while (top > 0)
	{
		hight = stack[--top];
		low = stack[--top];

		mid = quickSortChild(str, low, hight);
		if (low + 1 < mid)
		{
			stack[top++] = low;
			stack[top++] = mid - 1;
		}
		if (hight - 1 > mid)
		{
			stack[top++] = mid + 1;
			stack[top++] = hight;
		}
	}
}


//直接插入排序
void InsertSort(int *str, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i=1;i < len;i++)
	{
		temp = str[i];
		for (j = i;j >= 0 && str[j - 1] > temp;j--)
		{
			str[j] = str[j - 1];
		}
		str[j] = temp;
	}
}


//归并排序
void mergeSortchild(int *str,int start,int mid,int end)
{//并的过程中创建了和元素组一样大小的数组，如果原数组更改，记得更改MaxSize的大小
	int tempstr[MaxSize];
	int tempstrIndex = start;
	int start2 = mid + 1;
	int i = start;
	while (start <= mid && start2 <= end)
	{
		if (str[start] <= str[start2])
		{
			tempstr[tempstrIndex++] = str[start++];
		}
		else
		{
			tempstr[tempstrIndex++] = str[start2++];
		}
	}
	while (start <= mid)
	{
		tempstr[tempstrIndex++] = str[start++];
	}
	while (start2 <= end)
	{
		tempstr[tempstrIndex++] = str[start2++];
	}
	for (;i <= end;i++)
	{
		str[i] = tempstr[i];
	}
}
void mergeSort(int *str, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start+end)>>1;
	mergeSort(str, start, mid);
	mergeSort(str, mid + 1, end);
	//之前都是分解过程，接下来是合并过程
	mergeSortchild(str,start, mid,end);
}


void Printf(int *str,int len)
{
	int i = 0;
	for (i = 0;i < len;i++)
	{
		printf("%d < ", str[i]);
	}
	printf("\n");
}
void SortTest()
{
	int str[] = { 3,45,5362,764527,7845,735,2156,2,5262,866 };
	int len = sizeof(str) / sizeof(str[0]);
	quickSort(str, 0, len - 1);
	printf("快速排序排序结果：\n");
	Printf(str, len);

	int str1[] = { 3,45,535216,27,745,35,56,2,52,66 };
	int len1 = sizeof(str1) / sizeof(str1[0]);
	MaoPao(str1, len1);
	printf("冒泡排序排序结果：\n");
	Printf(str1, len1);

	int str2[] = { 93,45,53,5216,27,745,35,56,2,52,66 };
	int len2 = sizeof(str2) / sizeof(str2[0]);
	heapSort(str2, len2);
	printf("堆排序排序结果：\n");
	Printf(str2, len2);

	int str3[] = { 93,45,56,333,222,27,4533,35,56,99992,52,66 };
	int len3 = sizeof(str3) / sizeof(str3[0]);
     quickSort2(str3, 0,len3-1);
	printf("快速排序优化排序结果：\n");
	Printf(str3, len3);

	int str4[] = { 93,45,999,888,556,272,435,365,566,99992,352,646 };
	int len4 = sizeof(str4) / sizeof(str4[0]);
	quicksort3(str4, len4);
	printf("快速排序非递归排序结果：\n");
	Printf(str4, len4);

	int str5[] = { 93,45,55,33,33,33,33,27,43,36,56,992,32,66 };
	int len5 = sizeof(str5) / sizeof(str5[0]);
	InsertSort(str5, len5);
	printf("直接插入排序排序结果：\n");
	Printf(str5, len5);

	int str6[] = { 93,45,55,33,33,33,33,27,32,66 };
	int len6 = sizeof(str6) / sizeof(str6[0]);
	mergeSort(str6, 0,len6-1);
	printf("归并排序排序结果：\n");
	Printf(str6, len6);
}
int main()
{
	SortTest();
	system("pause");
	return 0;
}