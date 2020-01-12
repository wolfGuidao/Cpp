#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Menu()
{
	printf("********************************************\n");
	printf("*************猜数游戏开始*******************\n");
	printf("*************输入1开始游戏******************\n");
	printf("*************输入0退出游戏******************\n");
	printf("********************************************\n");
}
void Game()
{
	int n;
	int shuijishu = rand() % 100 + 1;
	for (;;)
	{
		scanf_s("%d", &n);
		if (shuijishu > n)
		{
			printf("你猜的数小了,请重新输入\n");
		}
		if (shuijishu < n)
		{
			printf("你猜的数大了，请重新输入\n");
		}
		if (shuijishu == n)
		{
			printf("你猜对了");
			break;
		}
	}
}
int main()
{
	int i;
	Menu();
	srand((unsigned int)time(NULL));
	printf("请输入你的选择（1、0）\n");
	scanf_s("%d", &i);
	if (i == 0)
	{
		printf("拜拜");
	}
	if (i == 1)
	{
		printf("请输入你猜的数：\n");
		Game();
	}
	system("pause");
	return 0;
}