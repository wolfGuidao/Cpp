#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10
//注意数组存储下标代表每一行，数组元素代表皇后在每一行的位置
int hei[MaxSize];//黑皇后
int bai[MaxSize];//白皇后
int chessboard[MaxSize][MaxSize];//1:能放  0:不能放
int count = 0;//记录共有多少种放皇后的位置

int Check(int *str, int line)//该函数判断皇后是否能够放置在str[line]这个位置
{
	int i = 1;
	for (;i < line;i++)
	{
		int temp = str[i] - str[line];
		if (temp == 0 || temp == i - line || temp == line - i)
			//temp == 0，表示皇后在同一列；temp == i - line 和 temp == line - i代表皇后在正反对角线
		{
			return 0;
		}
	}
	return 1;
}

void Whilte(int n, int line)
{
	if (line == n + 1)
	{
		count++;
	}
	else
	{
		for (int i = 1;i <= n;i++)//i空值第line行的每一列
		{
			if (chessboard[line][i] == 1&&hei[line]!=i)//判断该位置是否可以放皇后
			{
				bai[line] = i;//记录第line行皇后的位置
				if (Check(bai, line))//进行判断，满足条件就递归下一行
				{
					Whilte(n, line + 1);
				}
			}
		}
	}
}

void Black(int n, int line)//该函数放黑皇后
{
	if (line == n+1)//如果行line等于n+1;说明该次递归找到一次所有黑皇后满足条件的位置，就去放白皇后
	{
		return Whilte(n, 1);
	}
	else
	{
		for (int i = 1;i <= n;i++)//i空值第line行的每一列
		{
			if (chessboard[line][i] == 1)//判断该位置是否可以放黑皇后
			{
				hei[line] = i;//记录第line行黑皇后的位置
				if (Check(hei, line))//进行判断，满足条件就递归下一行
					//注意该递归是放在循环内部的，所以当第i列不满足条件时，就会退回i-1列继续判断，即回溯
				{
					Black(n, line + 1);
				}
			}
		}
	}
}

int main()
{
	int n;
	printf("请输入棋盘大小n:\n");
	scanf("%d", &n);
	printf("请输入棋盘元素；1：该位置可以放皇后；0：该位置不可以放皇后\n");
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			printf("%d", chessboard[i][j]);
		}
		printf("\n");
	}
	Black(n, 1);
	printf("皇后共有%d种放法\n", count);
	system("pause");
	return 0;
}






#if 0
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

void Black(int line, int n)//递归放置黑皇后,注意该递归是在循环内部，
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
	printf("接下来%d行，每行%d个0或1的整数，\n", n, n);
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