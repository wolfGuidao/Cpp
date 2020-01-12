#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
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

//计时
void JiShi()
{
	printf("你一共花费了：%u秒\n", clock() / CLOCKS_PER_SEC);
}

//初始化二维数组，初始化玩家看到的扫雷界面，和雷的信息
void ChuShiHua(char WanJia[ROWS][COLS],int row, int col, char a)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS;i++)
	{
		for (j = 0;j < COLS;j++)
		{
			WanJia[i][j] = a;
		}
	}
}

//打印两个数组
void DaYin(char WanJia[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("=====================================\n");
	for (i = 0;i < row - 1;i++)
	{
		printf("%d   ", i);
	}
	printf("\n");
	for(i=1;i<row-1;i++)
	{
		printf("%d   ", i);
		for (j = 1;j < col-1;j++)
		{
			
			printf("%c   ", WanJia[i][j]);
		}
		printf("\n");
	}
	printf("=====================================\n");
}

//为玩家设置雷的位置
void SetLei(char LeiXinXi[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = N;
	while (count != 0)
	{
		x = rand() % row+1;
		y = rand() % col+1;
		if (LeiXinXi[x][y] == '0')
		{
			LeiXinXi[x][y] = '1';
			count--;
		}
	}
}

//玩家输入坐标后，返回该座标周围雷的数量
int Lei(char LeiXinXi[ROWS][COLS], int x, int y)
{
	return LeiXinXi[x - 1][y - 1] +
		LeiXinXi[x - 1][y] +
		LeiXinXi[x - 1][y + 1] +
		LeiXinXi[x][y + 1] +
		LeiXinXi[x + 1][y + 1] +
		LeiXinXi[x + 1][y] +
		LeiXinXi[x + 1][y - 1] +
		LeiXinXi[x][y - 1] - 8 * '0';
}

//展开:如果该座标周围8个位置没有一个雷，就把这8个位置的周围雷的信息存储起来
void ZhanKai(char LeiXinXi[ROWS][COLS], char WanJia[ROWS][COLS], int x, int y)
{
	int a = 0;
	a= Lei(LeiXinXi, x, y);
	if (a == 0)
	{
		WanJia[x - 1][y - 1] = Lei(LeiXinXi, x-1, y-1)+'0';
		WanJia[x - 1][y] = Lei(LeiXinXi, x - 1, y ) + '0';
		WanJia[x - 1][y + 1] = Lei(LeiXinXi, x - 1, y + 1) + '0';
		WanJia[x][y + 1] = Lei(LeiXinXi, x , y +1) + '0';
		WanJia[x + 1][y + 1] = Lei(LeiXinXi, x + 1, y + 1) + '0';
		WanJia[x + 1][y] = Lei(LeiXinXi, x +1, y ) + '0';
		WanJia[x + 1][y - 1] = Lei(LeiXinXi, x +1, y - 1) + '0';
		WanJia[x][y - 1] = Lei(LeiXinXi, x , y - 1) + '0';
		WanJia[x][y] = '0';
	}
	else
	{
		WanJia[x][y] = a + '0';
	}
}

//防止第一次被炸死，如果第一次就是雷，就把该位置置为没有雷即‘0’，
void FirstDie(char WanJia[ROWS][COLS], char LeiXinXi[ROWS][COLS], int row, int col, int x, int y)
{
	int m=0;
	int n = 0;
	int a=0 ;
	if (LeiXinXi[x][y] == '1')
	{
		LeiXinXi[x][y] = '0';
		a=Lei(LeiXinXi, x, y);
		WanJia[x][y] = a + '0';
		
		ZhanKai(LeiXinXi, WanJia, x, y);
		while (1)
		{
			m = rand() % row+1;
			n = rand() % col + 1;
			if (LeiXinXi[m][n] == '0')
			{
				LeiXinXi[m][n] = '1';
				DaYin(WanJia, ROWS, COLS);
				break;
			}
		}


	}
}


//标记：
void BiaoJi(char WanJia[ROWS][COLS], int x, int y)
{
	if (WanJia[x][y] == '*')
	{
		WanJia[x][y] = '!';
	}
	else
	{
		printf("此处不能标记\n");
	}
}

//取消标记
void QXBiaoJi(char WanJia[ROWS][COLS], int x, int y)
{
	if (WanJia[x][y] == '!')
	{
		WanJia[x][y] = '*';
	}
	else
	{
		printf("此处不能取消标记\n");
	}
}

//判断玩家是否需要标记或取消标记
void PDBiaoJi(char WanJia[ROWS][COLS])
{
	int count = 1;
	int input = 0;
	int x = 0;
	int y = 0;
	printf("输入1：标记；输入2：取消标记；输入0：跳过标记步骤\n");
	scanf("%d", &input);
	while (count)
	{
		switch (input)
		{
		case 1:
			printf("请输入要标记的坐标：\n");
			scanf("%d%d", &x, &y);
			BiaoJi(WanJia, x, y);
			count--;
			break;
		case 2:
			printf("请输入要取消标记的坐标：\n");
			scanf("%d%d", &x, &y);
			QXBiaoJi(WanJia, x, y);
			count--;
			break;
		case 0:
			printf("跳过该步骤\n");
			count--;
			break;
		default:
			printf("你输入的坐标有误，请重新输入！\n");
			count--;
			break;
		}
	}
}

//玩家开始找雷
void ZhaoLei(char WanJia[ROWS][COLS], char LeiXinXi[ROWS][COLS], int row, int col)
{
	int x = 0;
	int a = 0;
	int y = 0;
	int count = 0;
	while (count < (row*col - N))
	{
		PDBiaoJi(WanJia);
		DaYin(WanJia, ROWS, COLS);
		printf("请输入你的坐标：");
		scanf("%d%d", &x, &y);
		if(x>=1&&y<=ROW&& y >= 1 && y <= COL)
		{
			if (LeiXinXi[x][y] == '0')
			{
				ZhanKai(LeiXinXi, WanJia, x, y);
				count++;
				DaYin(WanJia, ROWS, COLS);
			}
			else if(LeiXinXi[x][y] == '1')
			{
				if (count == 0)
				{
					FirstDie(WanJia, LeiXinXi, row, col, x, y);
					count++;
				}
				else
				{
					printf("很遗憾，你被炸死了!\n");
					break;
				}
			}
	     }
		else
		{
			printf("你输入的坐标不合法，请重新输入");
		}
	}
	if (count == (row*col - N))
	{
		printf("恭喜你，扫雷成功！");
	}
	JiShi();
}

//游戏核心函数
void Game()
{
	char WanJia[ROWS][COLS];
	char LeiXinXi[ROWS][COLS];
	ChuShiHua(WanJia, ROWS, COLS, '*');
	ChuShiHua(LeiXinXi, ROWS, COLS, '0');
	DaYin(WanJia, ROWS, COLS);
	SetLei(LeiXinXi, ROW, COL);
	//DaYin(LeiXinXi, ROWS, COLS);
	ZhaoLei(WanJia, LeiXinXi, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Muse();
		printf("请选择进入游戏还是退出游戏:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("游戏退出\n");
			break;
		case 1:
			Game();
			break;
		default:
			printf("你输入的坐标有误，请重新输入；");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}