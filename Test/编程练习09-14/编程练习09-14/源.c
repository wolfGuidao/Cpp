#define _CRT_SECURE_NO_WARNINGS
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//示例 :
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#include<stdio.h>

int main()
{
	char a[8][5] = { {'2','a','b','c'},{'3','d','e','f'},{'4','g','h','i'},{'5','j','k','l'},{'6','m','n','o'},{'7','p','q','r','s'},{'8','t','u','v'},{'9','w','x','y','z'} };
	int i = 0;
	int j = 0;
	char b[4];
	printf("请输入：");
	scanf("%s", b);
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 5;j++)
		{
			printf("%c%c",)
		}
	}
	system("pause");
	return 0;
}





#if 0
//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和
//与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//例如，给定数组 nums = [-1，2，1， - 4], 和 target = 1.
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
#include<stdio.h>
int main()
{
	int nums[] = { -1,2,1, -4 };
	int target = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 4;
	int min = abs((nums[0] + nums[1] + nums[2]) - 1);
	int sum = nums[0] + nums[1] + nums[2];
	for (i = 0;i < len;i++)
	{
		for (j = i+1;j < len;j++)
		{
			for (k = j+1;k< len;k++)
			{
				if ((abs((nums[i] + nums[j] + nums[k]) - 1)) < min)
				{
					min = abs((nums[i] + nums[j] + nums[k]) - 1);
					sum = nums[i] + nums[j] + nums[k];
				}
			}
		}
	}
	printf("%d", sum);
	system("pause");
	return 0;
}



//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
//找出所有满足条件且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//满足要求的三元组集合为：
//	[-1, 0, 1],
//	[-1, -1, 2]
#include<stdio.h>
#include<string.h>
int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 6;
	for (i = 0;i < len;i++)
	{
		for (j = i+1;j < len;j++)
		{
			for (k = j+1;k < len;k++)
			{
				if (a[i] + a[j] + a[k] == 0)
				{
					printf("%d %d %d\n", a[i], a[j], a[k]);	
				}
			}
		}
	}
	system("pause");
	return 0;
}
#endif