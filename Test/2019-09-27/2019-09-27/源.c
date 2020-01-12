#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>

#if 0

//1.调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
#include<stdio.h>
void JiaoHuan(int *p, int len)
{
	int left = 0;
	int right = len - 1;
	int value = p[left];
	while (left < right)
	{
		while (left < right&&p[right] % 2 == 0)
		{
			right--;
		}
		p[left] = p[right];
		while (left < right&&p[left] % 2 != 0)
		{
			left++;
		}
		p[right] = p[left];
	}
	p[left] = value;
}
int main()
{
	int i = 0;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	JiaoHuan(a, 10);
	for (i = 0;i < 10;i++)
	{
		printf("%d  ", a[i]);
	}
	system("pause");
	return 0;
}
#endif

//2.
////杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
// px，py 代表行数和列数
#include<stdio.h>
void find(int arr[3][3], int px, int py, int key)
{
	int i = 0;
	int j = py - 1;
	while (i < px - 1 && j >= 0)
	{
		if (arr[i][j] == key)
		{
			printf("存在这样的数");
			break;
		}
		else if (arr[i][j] > key)
		{
			--j;
		}
		else
		{
			++i;
		}
	}
	printf("不存在这样的数");
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = sizeof(arr)/sizeof(arr[0]);
	int y = sizeof(arr[0])/sizeof(arr[0][0]);
	find(arr, x, y, 4);
	//printf("%d%d", x, y);
	system("pause");
	return 0;
}
