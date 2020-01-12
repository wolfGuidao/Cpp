#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10//归并排序，桶排序等排序时需要申请和原数组一样大小的空间时用到，方便修改

//快排
int QuickShortchild(int *str, int left, int right)//时间复杂度为：nlogn
{
	int temp = str[left];//默认选数组第一个元素作为基准，即temp = str[left]
	while (left < right)//选好基准，传参时right存储数组最后一个元素下标，left存储数组首元素下标
	{
		while (left<right&&str[right]>=temp)//每次循环都是从后往前进行，即如果right代表元素小于基准，就把该值赋给left代表元素
		{
			right--;//否者right位置前移
		}
			str[left] = str[right];
		while (left < right&&str[left] <= temp)//然后从前往后进行，如果left代表元素大于基准，这把该值赋给right代表元素
		{
			left++;//否者left后移
		}
			str[right] = str[left];
	}
	str[left] = temp;
	return left;//此为一趟快速排序，返回基准位置，方便递归时把数组分割开
}
void QuickSort(int *str,int left,int right)
{
	if (left < right)
	{
		int mid = QuickShortchild(str, left, right);//得到基准位置，即数组中该位置前的元素都比它小，后面的元素都比他大
		QuickSort(str,left, mid-1);//对基准左部进行递归排序
        QuickSort(str, mid + 1, right);	//对基准右部进行递归排序
	}
}

//堆排   
void adjust(int *str,int start,int end)//转化为大根堆
{
	int i = 0;
//已知子推父：若子为n,则父为(n-1)/2;
//已知父推子:若父为n,则子为2n+1\2n+2;
//一次调整为大根堆时间复杂度：log2n;
//整棵树调整为大根堆时间复杂度：n*log2n;
	int temp = str[start];
	for (i = 2 * start + 1;i <= end;i = i * 2 + 1)
	{
		if ((i < end) && str[i] < str[i + 1])
		{
			i++;
		}
		if (str[i] > temp)
		{
			str[start] = str[i];
			start = i;
		}
		else if (str[i] < temp)
		{
			//str[start] = temp;
			break;

		}
	}
	str[start] = temp;
}
void heapSort(int *str,int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = (len - 1 - 1) / 2;i >= 0;i--)//把整棵树调整为大根堆
	{
		adjust(str, i, len - 1);
	}
	for (j = 0;j < len - 1;j++)//进行交换，每交换一次，调整一次，保证每次都是大根堆，注意每交换完一次，即得到一个数，该数有序，所以把整棵树调整为大根的元素少一个
	{
		tmp = str[len - 1 - j];
		str[len - 1 - j] = str[0];
		str[0] = tmp;
		adjust(str, 0, len - 1-j-1);//len-1-j-1:（len-1):数组长度；-j:是为了进入循环；-1：因为已经进行一次交换，交换到底端的数有序，进行调整为大根堆操作的数少一个；
	}
}

//选择排序
void selectSort(int *str  ,int len)
{
//每次选择最小或最大的元素放在数组首元素位置，期间发生交换就好了
//时间复杂度为：n2;
//空间复杂度为：1；
	int i = 0;
	int j = 0;
	int temp;
	for (i = 0;i < len ;i++)
	{
		for (j = i+1;j < len;j++)
		{
			if (str[i] <= str[j])
			{
				j++;
			}
			else
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}

//冒泡排序
void bubbleSort(int *str, int len)
{
//冒泡排序, 升序排列
//数组当中比较小的数值向下沉，数值比较大的向上浮！
	int i = 0;
	int temp = 0;
	int j = 0;
	for (i = 0;i < len;i++)
	{
		for (j = i + 1;j < len;j++)
		{
			if (str[i] < str[j])
			{
				j++;
			}
			else
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}
//归并排序
void mergeChild(int *str,int start,int mid,int end)//把一个一个的序列排序并合并在一起
{
	int tempstr[MaxSize];
	int tempIndex = start;
	int start2 = mid + 1;
	int i = start;
	while (start <= mid && start2 <= end)//两个归并段都有数据的时候
	{
		if (str[start] <= str[start2])
		{
			tempstr[tempIndex] = str[start];
			start++;
			tempIndex++;
		}
		else
		{
			tempstr[tempIndex] = str[start2];
			start2++;
			tempIndex++;
		}
	}
	while (start <= mid)
	{
		tempstr[tempIndex] = str[start];
		start++;
		tempIndex++;
	}
	while (start2 <=  end)
	{
		tempstr[tempIndex] = str[start2];
		start2++;
		tempIndex++;
	}
	while (i <= end)//把每次合并排序完成的元素拷贝到原数组中
	{
		str[i] = tempstr[i];
		i++;
	}
}
void mergeSort(int *str, int start,int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;//该过程是把数组分解为一个一个的序列
	mergeSort(str,start, mid);
	mergeSort(str, mid+1 , end);

	mergeChild(str,start,mid ,end);//合并和排序过程
}

//快排优化（三数取中选基准）
void Swap(int *str,int start,int end)
{
	int temp = str[start];
	str[start] = str[end];
	str[end] = temp;
}
void medianOfThree(int * str,int low,int hight)//保证str[mid]<=str[low]<=str[hight];控制基准的选择
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
		Swap(str, low, hight);
	}
}
void quickSort2(int *str,int left,int right)
{
	if (left < right)
	{
		medianOfThree(str, left, right);
		int mid = QuickShortchild(str, left, right);//得到基准位置，即数组中该位置前的元素都比它小，后面的元素都比他大
		QuickSort(str, left, mid - 1);//对基准左部进行递归排序
		QuickSort(str, mid + 1, right);	//对基准右部进行递归排序
	}
}

//快速排序非递归（用数组代替栈）
void quickSort3(int *str, int len)
{
	int stack[MaxSize * 2];
	int top = 0;
	int low = 0;
	int hight = len - 1;
	int mid = QuickShortchild(str, low, hight);//先进行一趟快排，得到一个分界点，
	//判断mid左右两边是否两个数据以上，如果有，分别把左右两边元素下标入栈
	if (mid > low + 1)
	{
		stack[top++] = low;
		stack[top++] = mid - 1;
	}
	if (mid < hight - 1)
	{
		stack[top++] = mid + 1;
		stack[top++] = hight;
	}
	//以上代码执行完毕，说明下标入栈完毕
	//判断栈是否为空，如果不为空，取出两个下标赋给hight,low，后进行循环，直至栈为空。
	while (top > 0)
	{
		hight = stack[--top];
		low = stack[--top];

		mid = QuickShortchild(str, low, hight);
		if (mid > low + 1)
		{
			stack[top++] = low;
			stack[top++] = mid - 1;
		}
		if (mid < hight - 1)
		{
			stack[top++] = mid + 1;
			stack[top++] = hight;
		}
	}
}

//直接插入排序
void InsertSort(int *str, int len) 
{               
	int i=0;
	int j=0;                                    
	int temp;                                     
	for (i = 1; i < len; i++)
	{
		temp = str[i];
		for (j = i;j > 0&&str[j-1]>temp;j--)
		{
			str[j] = str[j - 1];//满足条件，就把j之前元素一个一个往后覆盖
		}
		str[j] = temp;//最后把temp放到合适位置
	}
}

//希尔排序
void shellSort(int *str, int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp;
	int gap = len / 2;//gap不仅是增量还是分得的组数
	for (;gap>0;gap/=2)
	{
		for (k = 0;k < gap;k++)

		{
			for (i = k+gap; i < len; i += gap)
			{
				temp = str[i];
				for (j = i;j > 0 && str[j - gap] > temp;j-=gap)
				{
					str[j] = str[j - gap];
				}
				str[j] = temp;
			}
		}
	}
}

//基数排序
int Max(int *str, int len)//找数组中最大元素，并返回其位数
{
	int i = 0;
	int max = str[0];
	int temp = 0;
	int d = 0;
	for (i = 1;i < len;i++)
	{
		if (str[i] > max)
		{
			max = str[i];
		}
	}
	while (max != 0)
	{
		max = max / 10;
		d++;
	}
	return d;
}
void radixSort(int *str, int len) //
{
	int d = Max(str, len);
	int tmp[MaxSize];
	int count[MaxSize]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
		{
			count[j] = 0; //每次分配前清空计数器
		}
		for (j = 0; j < len; j++)
		{
			k = (str[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		}
		for (j = len - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (str[j] / radix) % 10;
			tmp[count[k] - 1] = str[j];
			count[k]--;
		}
		for (j = 0; j < len; j++) //将临时数组的内容复制到str中
		{
			str[j] = tmp[j];
		}
		radix = radix * 10;
	}
}

//计数排序
void CountSort(int *str, int len)
{
	int i, j, count;
	int temp = 0;
	int data_p[MaxSize];
	for (i = 0;i < len;i++)//初始化data_p
	{
		data_p[i] = 0;
	}
	for (i = 0;i < len;i++)
	{
		count = 0;
		for (j = 0;j < len;j++)//扫描待排序数组
			if (str[j] < str[i])//统计比data[i]值小的值的个数
				count++;
		while (data_p[count] != 0)//对于相等非0的数据，应向后措一位。数据为0时，因数组data_p被初始化为0，故不受影响。
		/* 注意此处应使用while循环进行判断，若用if条件则超过三个重复值后有0出现 */
			count++;
		data_p[count] = str[i];//存放到data_p中的对应位置
	}
	//用于检查当有多个数相同时的情况
	i = 0, j = len;
	while (i < j)
	{
		if (data_p[i] == 0)
		{
			temp = i - 1;
			data_p[i] = data_p[temp];
		}
		i++;
	}
	for (i = 0;i < len;i++)//把排序完的数据复制到data中
	{
		str[i] = data_p[i];
	}
}

//桶排排序
typedef struct node {
	int key;
	struct node* next;
}KeyNode;
void bucketSort(int *str, int len, int bucket_size)
{
	KeyNode **bucket_table = (KeyNode**)malloc(bucket_size * sizeof(KeyNode*));
	for (int i = 0;i < bucket_size;i++)
	{    //初始化桶
		bucket_table[i] = (KeyNode*)malloc(sizeof(KeyNode));
		bucket_table[i]->key = 0;
		bucket_table[i]->next = NULL;
	}
	for (int i = 0;i < len;i++)
	{
		KeyNode* node = (KeyNode*)malloc(sizeof(KeyNode));
		node->key = str[i];
		node->next = NULL;
		int index = str[i] / 10;//给数据分类的方法（关系到排序速度，很重要）
		KeyNode *p = bucket_table[index];
		if (p->key == 0)
		{
			p->next = node;
			p->key++;
		}
		else 
		{
			while (p->next != NULL && p->next->key <= node->key) 
			{//=的时候后来的元素会排在后面
				p = p->next;
			}
			node->next = p->next;
			p->next = node;
			(bucket_table[index]->key)++;
		}
	}
	KeyNode* k = NULL;
	for (int i = 0;i < bucket_size;i++) 
	{
		for (k = bucket_table[i]->next;k != NULL;k = k->next)
		{
			printf("%d < ", k->key);
		}
	}
	printf("\n");
}

//打印函数
void Printf(int *str,int len)
{
	int i = 0;
	for (i = 0;i < len; i++)
	{
		printf("%d < ", str[i]);
	}
	printf("\n");
}

//测试函数
void text()
{
	int str[] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(str) / sizeof(str[0]);
	printf("快速排序结果：\n");
	QuickSort(str, 0, len-1);
	Printf(str, len);

	int str1[] = { 10,9,85,70,63,5,4,33,32,91 };
	int len1 = sizeof(str1) / sizeof(str1[0]);
	printf("堆排排序结果：\n");
	heapSort(str1,len1);
	Printf(str1, len1);

	int str2[] = { 10,96,85,47,63,35,24,31,12,11 };
	int len2 = sizeof(str2) / sizeof(str2[0]);
	printf("直接选择排序结果：\n");
	selectSort(str2,len2);
	Printf(str2, len2);

	int str3[] = { 101,91,18,27,26,35,43,34,24,16 };
	int len3 = sizeof(str3) / sizeof(str3[0]);
	printf("冒泡排序结果：\n");
	bubbleSort(str3, len3);
	Printf(str3, len3);

	int str4[] = { 10,29,82,97,86,58,46,3,62,1 };
	int len4 = sizeof(str4) / sizeof(str4[0]);
	printf("归并排序结果：\n");
	mergeSort(str4, 0,len4-1);
	Printf(str4, len4);

	int str5[] = { 109,19,82,73,64,45,99,43,52,11 };
	int len5 = sizeof(str5) / sizeof(str5[0]);
	printf("快速排序优化后排序结果：\n");
	quickSort2(str5, 0, len5 - 1);
	Printf(str5, len5);

	int str6[] = { 10,9,88,77,69,5,99,3,2,1 };
	int len6 = sizeof(str6) / sizeof(str6[0]);
	printf("快速排序非递归排序结果：\n");
	quickSort3(str6, len6);
	Printf(str6, len6);

	int str7[] = { 100,1999,58,67,60,51,29,13,25,18 };
	int len7 = sizeof(str7) / sizeof(str7[0]);
	printf("直接插入排序排序结果：\n");
	InsertSort(str7, len7);
	Printf(str7, len7);

	int str8[] = { 10,999,48,67,70,11,21,43,55,98 };
	int len8 = sizeof(str8) / sizeof(str8[0]);
	printf("希尔排序排序结果：\n");
	shellSort(str8, len8);
	Printf(str8, len8);

	int str9[] = { 110,999,8,6,17,31,31,93,55,99998 };
	int len9 = sizeof(str9) / sizeof(str9[0]);
	printf("基数排序排序结果：\n");
	radixSort(str9, len9);
	Printf(str9, len9);

	int str10[] = { 110,999,8,6,17,31,31,93,55,99998 };
	int len10 = sizeof(str10) / sizeof(str10[0]);
	printf("计数排序排序结果：\n");
	CountSort(str10, len10);
	Printf(str10, len10);

	int str11[] = { 10,96,85,47,63,35,24,31,12,11 };
	int len11 = sizeof(str11) / sizeof(str11[0]);
	printf("桶排排序结果：\n");
	bucketSort(str11, len11,MaxSize);//桶排排序打印函数在函数内部，因为其打印方式不方便和其他排序共用
}

int main()
{
	text();
	system("pause");
	return 0;
}