#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//打印菜单
void Muse()
{
	printf("******************************\n");
	printf("*******欢迎进入三子棋游戏*****\n");
	printf("*******输入1：进入游戏********\n");
	printf("*******输入0：退出游戏********\n");
	printf("******************************\n");
}

//初始化您的二维数组为空格
void ChuShiHua(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			qipan[i][j] = ' ';
		}
	}
}

//按照棋盘的格式打印二维数组
void DaYin(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ", qipan[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//玩家移动，棋子为‘X’
void WanJia(char qipan[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家移动：\n");
		printf("请输入1——>3的坐标：");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= 3 && y > 0 && y <= 3)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("您输入的坐标已有棋子，请重新输入:");
			}
		}
		else
		{
			printf("您输入的坐标有误！请重新输入：");
		}
	}
}

//判断棋盘中是否已经全部落子；方便后续判断
int Man(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断玩家或电脑移动后是否构成三子（判赢）
int Win(char qipan[][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < ROW;i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[0][i] != ' ')
		{
			return qipan[0][i];
		}
		if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[0][0] != ' ')
		{
			return qipan[0][0];
		}
		if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[2][0] != ' ')
		{
			return qipan[i][0];
		}//赢
		if (Man(qipan, 3, 3) == 1)
		{
			return 'P';//平局
		}
	}
	return 'B';//没有赢也没平局，对方移动
}

//电脑移动，棋子为‘O’
void DianNao(char qipan[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑移动：\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = 'O';
			break;
		}
	}
}

//整个游戏的核心函数
void Game()
{
	int a = 0;
	char qipan[ROW][COL] = { 0 };
	ChuShiHua(qipan, 3, 3);
	DaYin(qipan, 3, 3);
	while (1)
	{

		WanJia(qipan, 3, 3);
		DaYin(qipan, 3, 3);
		a = Win(qipan, 3, 3);
		if (a != 'B')
		{
			break;
		}
		DianNao(qipan, 3, 3);
		DaYin(qipan, 3, 3);
	}
	if (a == 'X')
	{
		printf("恭喜你你赢了！");
	}
	else if (a == 'O')
	{
		printf("真遗憾，你输了！");
	}
	else if (a == 'P')
	{
		printf("平局哟！");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Muse();
		printf("请输入你的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("您输入的有误！请重新输入：");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}