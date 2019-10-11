#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cmath"
using namespace std;
#define Max 20      //定义棋盘的最大值
int a[Max];
int show(int S)    //定义输出函数
{
	int i, p, q;
	int b[Max][Max] = { 0 };     //定义并初始化b[][]输出数组
	for (i = 1;i <= S;i++)    //按横列i顺序输出a[i]数组坐标
	{
		b[i][a[i]] = 1;
		printf("(%d,%d)\t", i, a[i]);
	}
	printf("\n");
	for (p = 1;p <= S;p++)     //按棋盘的横列p顺序标明皇后的位置
	{
		for (q = 1;q <= S;q++)
		{
			if (b[p][q] == 1)     //在第p行第q列放置一个皇后棋子
				printf("●");
			else
				printf("○");
		}
		printf("\n");
	}
	return 0;
}

int check(int k)    //定义check函数
{
	int i;
	for (i = 1;i < k;i++)    //将第k行与前面的第1~~k-1行进行判断
	{
		if ((a[i] == a[k]) || (a[i] - a[k] == k - i) || (a[i] - a[k] == i - k)) //检查是否有多个皇后在同一条直线上
		{
			return 0;
		}
	}
	return 1;
}

void check_m(int num)   //定义函数
{
	int k = 1, count = 0;
	printf("皇后的位置如下:\n");
	a[k] = 1;
	while (k > 0)
	{
		if (k <= num && a[k] <= num)//从第k行第一列的位置开始，为后续棋子选择合适位子
		{
			if (check(k) == 0)    //第k行的a[k]列不能放置皇后
			{
				a[k]++;        //继续探测当前行的下一列：a[k]+1
			}
			else
			{
				k++;        //第K行的位置已经确定了，继续寻找第k+1行皇后的位置
				a[k] = 1;      //从第一列开始查找
			}
		}
		else
		{
			if (k > num)     //若满足输出数组的要求则输出该数组
			{
				count++;
				printf("[%d]:  ", count);
				show(num);    //调用输出函数show()
			}
			//如果k>num会执行下面两行代码，因为虽然找到了N皇后问题的一个解，但是要找的是所有解，需要回溯，从当前放置皇后的下一列继续探测
			//如果a[k]>num也会执行下面两行代码，就是说在当前行没有找到可以放置皇后的位置，于是回溯，从上一行皇后位置的下一列继续探测
			k--;      //棋子位置不符合要求，则退回前一步
			a[k]++;   //继续试探下一列位置
		}
	}
	printf("满足所有条件下皇后的位置共有: %d种 \n", count);
}

int main(void)
{
	int n;
	printf("请输入皇后个数：");
	scanf("%d", &n);
	printf("\n使用非递归回溯法解决 %d 皇后问题时的运行情况\n", n);
	check_m(n);
	system("pause");
	return 0;
}
#if 0

#include<Windows.h>
#include<stdio.h>
#define MaxSize 10
//2n皇后问题
//问题描述
//给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后
//都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？
//n小于等于8。
//输入格式
//输入的第一行为一个整数n，表示棋盘的大小。
//接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
//输出格式
//输出一个整数，表示总共有多少种放法。
//样例输入
//4
//1 1 1 1
//1 1 1 1
//1 1 1 1
//1 1 1 1
//样例输出
//2

int hei[MaxSize];//黑皇后
int bai[MaxSize];//白皇后
int chessboard[MaxSize][MaxSize];//1:能放  0:不能放
int count = 0;
int check(int queen[], int line)//判断函数
{
	for (int i = 1; i < line; i++)
	{
		int judge = queen[i] - queen[line];
		if (judge == 0 || judge == i - line || judge == line - i)
			//judge == 0 表示在同一列，judge == i - line || judge == line - i表示在同一对角线
		{
			return 0;
		}
	}
	return 1;
}

void White(int line, int n)//在黑皇后前提下递归放置白皇后
{
	if (line == n + 1)//在放完黑皇后前提下，放置白皇后，每放完所有皇后一次，count++;
	{
		count++;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (chessboard[line][i] == 1 && i != hei[line])
			{
				bai[line] = i;
				if (check(bai, line))
				{
					White(line + 1, n);//递归下一行
				}
			}
		}
	}
}

void Black(int line, int n)//递归放置黑皇后
{
	if (line == n + 1)//表示黑皇后已放置完毕
	{
		White(1, n);
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			if (chessboard[line][i] == 1)
			{
				hei[line] = i;//表示黑皇后每一行放置的位置
				if (check(hei, line))//判断放置皇后位置是否满足条件，满足就递归，不满足就换一个位置放置皇后，进行循环
				{
					Black(line + 1, n);//递归下一行				
				}
			}
		}
	}
}

int main()
{
	int n;
	printf("请输入棋盘大小：\n");
	scanf("%d", &n);
	printf("接下来%d行，每行%d个0或1的整数，\n",n,n);
	printf("如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf(" %d ", chessboard[i][j]);
		}
		printf("\n");
	}
	Black(1, n);
	printf("总共有%d种放置皇后的方法", count);
	system("pause");
	return 0;
}

#endif