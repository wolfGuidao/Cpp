#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
//调试

#define ROWS ROW+2
#define COLS COL+2

#define N 10

//打印菜单
void Muse()
{
	printf("******************************\n");
	printf("*******欢迎进入扫雷棋游戏*****\n");
	printf("*******输入1：进入游戏********\n");
	printf("*******输入0：退出游戏********\n");
	printf("******************************\n");
}

void ChuShiHua(char lei[ROWS][COLS], int rows, int cols ,char a)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			lei[i][j] = a;
		}
	}
}


void DaYin(char lei[][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	printf("====================\n");
	for (i = 0;i <rows-1 ;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i < rows-1 ;i++)
	{
		printf("%d ", i);
		for (j=1;j<cols-1;j++)
		{
			
			printf("%c ", lei[i][j]);

		}
		printf("\n");
	}
	printf("====================\n");
}

void SetLei(char lei[ROWS][COLS], int row,int col)
{
	int count = N;
	int x = 0;
	int y = 0;
	while (count!=0)
	{
		x = rand() % row+1;
		y = rand() % col+1;
		if (lei[x][y] == '0')
		{
			lei[x][y] = '1';
			count--;
		}
	}
}
int Getlei(char lei[][COLS], int x, int y)
{

	return lei[x - 1][y - 1] +
		lei[x - 1][y] +
		lei[x - 1][y + 1] +
		lei[x][y + 1] +
		lei[x + 1][y + 1] +
		lei[x + 1][y] +
		lei[x + 1][y-1] +
		lei[x][y - 1] - 8 * '0';
}
void ZhaoLei(char leinow[][COLS],char lei[][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int a = 0;

	while (count !=row*col - N)
	{
		printf("请输入你的坐标：");
		scanf("%d%d", &x,&y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (lei[x][y] == '1')
			{
				printf("挂了\n");
				break;
			}
			else
			{
				a = Getlei(lei, x, y);
				leinow[x][y] = a +'0';
				count++;
				DaYin(leinow, ROWS, COLS);
			}
		}
		else
		{
			printf("你输入的坐标不合法，重新输入：");
		}
		
	}
	if (count == row * col - N)
	{
		printf("成功\n");
	}
}
void Game()
{
	char leinow[ROWS][COLS];
	char lei[ROWS][COLS];
	ChuShiHua(leinow, ROWS, COLS,'*');
	ChuShiHua(lei, ROWS, COLS,'0');
	DaYin(leinow, ROWS, COLS);
	SetLei(lei, ROW, COL);
	//DaYin(lei, ROWS, COLS);
	ZhaoLei(leinow,lei, ROW, COL);
	DaYin(leinow, ROWS, COLS);
}

int main()
{
	int a = 0;
	srand((unsigned int) time(NULL));
	do
	{
		Muse();
		printf("请输入你的选择:");
		scanf("%d",&a);
		switch (a)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("你输入的数有误，请重新输入：\n");
		}
	} while (a);
}