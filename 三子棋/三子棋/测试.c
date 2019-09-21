#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#define ROW 3
#define COL 3
void Menu()
{
	printf("****************************\n");
	printf("****欢迎进入三子棋游戏******\n");
	printf("****输入1：进入游戏*********\n");
	printf("****输入0：退出游戏*********\n");
	printf("****************************\n");
}
void Game()
{
	int win = 0;
	char qipan[ROW][COL] = { 0 };

	ChuShiHua(qipan,3,3);

	DaYin(qipan, 3, 3);
	while (1)
	{
		WanJa(qipan, 3, 3);
		DaYin(qipan, 3, 3);
		win = Win(qipan, 3, 3);
		if (win != ' ')
		{
			break;
		}
		printf("电脑移动\n");
		DianNao(qipan, 3, 3);
		DaYin(qipan, 3, 3);
		win = Win(qipan, 3, 3);
	}
	if (win == 'X')
	{
		printf("恭喜您获胜了!\n");
	}
	else if (win == 'O')
	{
		printf("真遗憾，你输了\n");
	}
	else if (win == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请输入你的选择：");
		scanf("%d", &a);
		switch(a)
		{
		case 1:
				Game();
				break;
		case 0:
				printf("退出游戏");
				break;
		default:
			printf("输入的数有误");
			break;
		}
	} while (a);
	system("pause");
	return 0;
}