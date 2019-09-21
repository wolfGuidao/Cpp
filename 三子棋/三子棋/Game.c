#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#define ROW 3
#define COL 3
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

void DaYin(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ",qipan[i][j]);
			if (j < row -1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row-1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < row-1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}

}

void WanJa(char qipan[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家移动！\n");
		printf("请输入1->3坐标：");
		scanf("%d%d", &x, &y);
		if (x>0 && y<=3)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("该位置已被下过棋子！\n");
             
			}
		}
		else
		{
			printf("您输入的坐标不合法；请重新输入：");
		}
	}
}

static int Man(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0;j < col;j++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
int Win(char qipan[][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[0][i] != ' ')
		{
			return qipan[0][i];
		}
		if(qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[0][0] != ' ')
		{
			return qipan[0][0];
		}
		if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[2][0] != ' ')
		{
			return qipan[2][0];
		}
		if (Man(qipan, row, col))
		{
			return 'Q';//平局
		}
	}
	return ' ';//没有平局也没有赢
}

void DianNao(char qipan[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % row;
		if (qipan[x][y]== ' ')
		{
			qipan[x][y] = 'O';
			break;
		}
	}
}