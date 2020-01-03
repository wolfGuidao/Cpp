#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")
#include<time.h>
using namespace std;
int cot, flag1, flag2, flag3;//cot是计步器 flag1,2,3指示是否拿到钥匙
int x, y, i, p, q, z, book, a3, a4, a5, a6;
int a1, a2;
char ch;
char c[100][100] = { "■■■■■■■■■■",
					"■◎            ■■",
					"■  ■  ■  ■  ★■",
					"■      ■  ■    ■        勇者啊，记得拿到钥匙之后才能打开牢房逃离",
					"■  ■■■  ■  ■■         ■表示墙 ◎表示你 ★表示钥匙 卍表示出口",
					"■    ■■    ■  卍",
					"■  ■        ■  ■",
					"■  ■  ■■■■  ■",
					"■                ■",
					"■■■■■■■■■■",
};
char b[200][200] = { "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",
				   "■    ■            ■            ■■■■■■■    ■    ■",
				   "■  ■■    ■■■■    ■■  ■  ■■        ■■      ■■",
				   "■  ■          ■        ■        ■  ■    ■■  ■    ■",
				   "■  ■■■■  ◎    ■      ■■■      ■      ■■    ■■",
				   "■        ■        ■        ■    ■  ■■          ■  卍",
				   "■■              ■■  ■    ■■■■■■      ■■■    ■",
				   "■  ■■■■    ■      ■  ■      ■      ■■    ■■  ■",
				   "■    ■★  ■      ■■■■  ■    ■      ■■    ■    ■",
				   "■          ■  ■■      ■        ■■        ■■    ■■",
				   "■■■■        ■    ■      ■■■■  ■  ■  ■    ■■■",
				   "■        ■■          ■  ■■  ■        ■      ■■■■",
				   "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",
};
char a[200][300] =
{
	"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",
	"■        ■                      ■                    ■■■              ■■■■                                  ■",
	"■        ■    ■■■■■    ■      ■■    ■■■        ■        ■            ■■  ■■■■■  ■■■■■■■  ■",
	"■        ■    ■      ■    ■  ■    ■          ■      ■        ■■■■■              ■■            ■      ■",
	"■        ■■■■      ■    ■  ■    ■■■■    ■    ■■              ■        ■■■■        ■■■■■  ■■■",
	"■    ■                ■■■■  ■          ■    ■      ■        ■    ■        ■    ■■■■■    ■■    ■■■",
	"■    ■    ■    ■■        ■■■■■■    ■    ■        ■■■■■■  ■■■■■■            ■            ■■■",
	"■    ■■■        ■          ◎                  ■            ■          ■      ■    ■    ■■    ■■  ■■■■",
	"■          ■        ■■■■■    ■■■  ■■■■■■■■■■      ■■■■■■    ■    ■              ■■■■  卍",
	"■  ■■■■■  ■■■■    ■    ■■                        ■■■■■        ■          ■    ■■■■■          ■",
	"■  ■    ★■        ■              ■■■■■■■  ■■          ■        ■    ■■■■■■■■    ■■■■■■  ■",
	"■■■      ■    ■  ■■■■    ■        ■          ■■■■■  ■    ■■■■                            ■  ■  ■",
	"■        ■■    ■        ■■  ■■■■          ■■    ■          ■■      ■  ■    ■■■■■■          ■  ■",
	"■      ■        ■  ■            ■  ■    ■■■        ■  ■  ■    ■      ■■■      ■      ■      ■  ■  ■",
	"■      ■      ■■■■■■                ■■      ■        ■  ■■■■        ■      ■■■      ■    ■  ■  ■",
	"■      ■                ■    ■■■  ■■■      ■■■■■■■  ■              ■      ■  ■■■■■    ■      ■",
	"■              ■■■    ■        ■            ■■    ■              ■        ■■■■■  ■      ■    ■  ■  ■",
	"■      ■          ■        ■■■■      ■    ■            ■        ■■■            ■      ■        ■■■■■",
	"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",
};
void status()//状态函数
{
	void gotoxy(int x, int y);
	if (c[x][y + 1] == -17 && c[x][y] == -95 && z == 1)
	{
		flag1 = 1;//flag1变为1 拿到钥匙
		gotoxy(11, 5);
		printf("勇者，恭喜你！得到了遗失在迷宫中的钥匙！");
	}
	else  if (b[x][y + 1] == -17 && b[x][y] == -95 && z == 2)
	{
		flag2 = 1;//flag1变为1 拿到钥匙
		gotoxy(14, 5);
		printf("勇者，恭喜你！得到了遗失在迷宫中的钥匙！");
	}
	else  if (a[x][y + 1] == -17 && a[x][y] == -95 && z == 3)
	{
		flag3 = 1;//flag1变为1 拿到钥匙
		gotoxy(20, 5);
		printf("勇者，恭喜你！得到了遗失在迷宫中的钥匙！");
	}
}
void gotoxy(int x, int y)//辅助函数：光标移动
{
	COORD coord;//光标结构体
	coord.X = y;//设置坐标
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//同步到控制台/设置控制台光标位置
}
void HideCursor()  //隐藏光标，防止干扰视线
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void getpd(char js)
{
	if (z == 1)
	{
		if (js == 'w' && ((c[x - 1][y] != -95 && c[x - 1][y] != -10) || (c[x - 1][y + 1] == -17) || (c[x - 1][y + 1] == -14)))
		{
			if (c[x - 1][y] == -123 && !flag1)//判断走到出口时是否拿到钥匙
				goto out1;
			gotoxy(x, y);
			printf("  ");
			x--;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
		if (js == 's' && ((c[x + 1][y] != -95 && c[x + 1][y] != -10) || (c[x + 1][y + 1] == -17) || (c[x + 1][y + 1] == -14)))
		{
			if (c[x + 1][y] == -123 && !flag1)
				goto out1;
			gotoxy(x, y);
			printf("  ");
			x++;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'd' && ((c[x][y + 2] != -95 && c[x][y + 2] != -10) || (c[x][y + 3] == -17) || (c[x][y + 3] == -14)))
		{
			if (c[x][y + 2] == -123 && !flag1)
				goto out1;
			gotoxy(x, y);
			printf("  ");
			y += 2;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'a' && ((c[x][y - 2] != -95 && c[x][y - 2] != -10) || (c[x][y - 1] == -17) || (c[x][y - 1] == -14)))
		{
			if (c[x][y - 1] == -123 && !flag1)
				goto out1;
			gotoxy(x, y);
			printf("  ");
			y -= 2;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
	out1:
		{
		}
	}
	if (z == 2)
	{
		if (js == 'w' && ((b[x - 1][y] != -95 && b[x - 1][y] != -10) || (b[x - 1][y + 1] == -17) || (b[x - 1][y + 1] == -14)))
		{
			if (b[x - 1][y] == -123 && !flag2)//判断走到出口时是否拿到钥匙
				goto out2;
			gotoxy(x, y);
			printf("  ");
			x--;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
		if (js == 's' && ((b[x + 1][y] != -95 && b[x + 1][y] != -10) || (b[x + 1][y + 1] == -17) || (b[x + 1][y + 1] == -14)))
		{
			if (b[x + 1][y] == -123 && !flag2)
				goto out2;
			gotoxy(x, y);
			printf("  ");
			x++;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'd' && ((b[x][y + 2] != -95 && b[x][y + 2] != -10) || (b[x][y + 3] == -17) || (b[x][y + 3] == -14)))
		{
			if (b[x][y + 2] == -123 && !flag2)
				goto out2;
			gotoxy(x, y);
			printf("  ");
			y += 2;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'a' && ((b[x][y - 2] != -95 && b[x][y - 2] != -10) || (b[x][y - 1] == -17) || (b[x][y - 1] == -14)))
		{
			if (b[x][y - 1] == -123 && !flag2)
				goto out2;
			gotoxy(x, y);
			printf("  ");
			y -= 2;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
	out2:
		{
		}
	}
	if (z == 3)
	{
		if (js == 'w' && ((a[x - 1][y] != -95 && a[x - 1][y] != -10) || (a[x - 1][y + 1] == -17) || (a[x - 1][y + 1] == -14)))
		{
			if (a[x - 1][y] == -123 && !flag3)//判断走到出口时是否拿到钥匙
				goto out3;
			gotoxy(x, y);
			printf("  ");
			x--;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
		if (js == 's' && ((a[x + 1][y] != -95 && a[x + 1][y] != -10) || (a[x + 1][y + 1] == -17) || (a[x + 1][y + 1] == -14)))
		{
			if (a[x + 1][y] == -123 && !flag3)
				goto out3;
			gotoxy(x, y);
			printf("  ");
			x++;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'd' && ((a[x][y + 2] != -95 && a[x][y + 2] != -10) || (a[x][y + 3] == -17) || (a[x][y + 3] == -14)))
		{
			if (a[x][y + 2] == -123 && !flag3)
				goto out3;
			gotoxy(x, y);
			printf("  ");
			y += 2;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'a' && ((a[x][y - 2] != -95 && a[x][y - 2] != -10) || (a[x][y - 1] == -17) || (a[x][y - 1] == -14)))
		{
			if (a[x][y - 1] == -123 && !flag3)
				goto out3;
			gotoxy(x, y);
			printf("  ");
			y -= 2;
			gotoxy(x, y);
			printf("◎");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
	out3:
		{
		}
	}
}
void time(int t, int r)//怪物随机移动函数
{
	clock_t s, f;
	int a1;
	s = clock();
	f = clock();
	srand(time(NULL));
	if (z == 2)
	{
		while (1)
		{
			HideCursor();
			if (b[x][y] == -123 && flag2)//如果走到出口，跳出
				break;
			if (!_kbhit())
			{
				f = clock();
				if (f - s >= 200)
				{
					a1 = rand() % 100 + 1;
					if (a1 >= 1 && a1 <= 25 && b[t][r + 2] != -95 && b[t][r + 2] != -123)//向四个方向随机移动且不能走到非法区域
					{
						gotoxy(t, r);
						printf("  ");
						r += 2;
						gotoxy(t, r);
						printf("◆");
					}
					if (a1 >= 26 && a1 <= 50 && b[t][r - 2] != -95 && b[t][r - 2] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						r -= 2;
						gotoxy(t, r);
						printf("◆");
					}
					if (a1 >= 51 && a1 <= 75 && b[t + 1][r] != -95 && b[t + 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t++;
						gotoxy(t, r);
						printf("◆");
					}
					if (a1 >= 76 && a1 <= 100 && b[t - 1][r] != -95 && b[t - 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t--;
						gotoxy(t, r);
						printf("◆");
					}
					if (t == x && y == r)//如果被怪抓住，将钥匙和起始点重新打印
					{
						gotoxy(t, r);
						printf("  ");
						gotoxy(4, 14);
						printf("◎");
						gotoxy(8, 8);
						printf("★");
						flag2 = 0;//钥匙掉落
						book = 1;
						break;
					}
					s += 200;
				}
			}
			else
			{
				HideCursor();
				ch = getchar();
				getpd(ch);
				status();
			}
		}
	}
	else if (z == 3)
	{
		while (1)
		{
			HideCursor();
			if (a[x][y] == -123 && flag3)
				break;
			if (!_kbhit())
			{
				f = clock();
				if (f - s >= 200)
				{
					a1 = rand() % 100 + 1;
					int js1 = rand() % 100 + 1, js2 = rand() % 100 + 1;//三个怪的随机移动
					if (a1 >= 1 && a1 <= 25 && a[t][r + 2] != -95 && a[t][r + 2] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						r += 2;
						gotoxy(t, r);
						printf("◆");
					}
					if (a1 >= 26 && a1 <= 50 && a[t][r - 2] != -95 && a[t][r - 2] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						r -= 2;
						gotoxy(t, r);
						printf("◆");
					}
					if (a1 >= 51 && a1 <= 75 && a[t + 1][r] != -95 && a[t + 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t++;
						gotoxy(t, r);
						printf("◆");
					}
					if (a1 >= 76 && a1 <= 105 && a[t - 1][r] != -95 && a[t - 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t--;
						gotoxy(t, r);
						printf("◆");
					}

					if (js1 >= 1 && js1 <= 25 && a[a3][a4 + 2] != -95 && a[a3][a4 + 2] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a4 += 2;
						gotoxy(a3, a4);
						printf("◆");
					}
					if (js1 >= 26 && js1 <= 50 && a[a3][a4 - 2] != -95 && a[a3][a4 - 2] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a4 -= 2;
						gotoxy(a3, a4);
						printf("◆");
					}
					if (js1 >= 51 && js1 <= 75 && a[a3 + 1][a4] != -95 && a[a3 + 1][a4] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a3++;
						gotoxy(a3, a4);
						printf("◆");
					}
					if (js1 >= 76 && js1 <= 105 && a[a3 - 1][a4] != -95 && a[a3 - 1][a4] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a3--;
						gotoxy(a3, a4);
						printf("◆");
					}

					if (js2 >= 1 && js2 <= 25 && a[a5][a6 + 2] != -95 && a[a5][a6 + 2] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a6 += 2;
						gotoxy(a5, a6);
						printf("◆");
					}
					if (js2 >= 26 && js2 <= 50 && a[a5][a6 - 2] != -95 && a[a5][a6 - 2] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a6 -= 2;
						gotoxy(a5, a6);
						printf("◆");
					}
					if (js2 >= 51 && js2 <= 75 && a[a5 + 1][a6] != -95 && a[a5 + 1][a6] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a5++;
						gotoxy(a5, a6);
						printf("◆");
					}
					if (js2 >= 76 && js2 <= 105 && a[a5 - 1][a6] != -95 && a[a5 - 1][a6] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a5--;
						gotoxy(a5, a6);
						printf("◆");
					}

					if ((t == x && y == r) || (x == a3 && y == a4) || (x == a5 && y == a6))
					{
						gotoxy(t, r);
						printf("  ");
						gotoxy(a3, a4);
						printf("  ");
						gotoxy(a5, a6);
						printf("  ");
						gotoxy(7, 32);
						printf("◎");
						gotoxy(10, 10);
						printf("★");
						book = 1;
						flag3 = 0;//钥匙掉落
						break;
					}
					s += 200;
				}
			}
			else
			{
				HideCursor();
				ch = getchar();
				getpd(ch);
				status();
			}
		}
	}
}
int main()
{
	HideCursor();
	printf("                                     亲爱的勇者，你总算醒了。 (按下enter键继续)");
	system("color B");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                                            什么，你问现在什么个情况？");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                         你忘了么，你被怪物偷袭了，这之后他们把昏迷的你带到了这座迷宫并关了起来");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                              好在有我跟了进来并找到了牢房钥匙的位置，所以趁现在快离开这里吧");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                         但可惜的是你的武器被他们带走了，因此你只能想办法避开怪物，不被它们发现");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                      你问我是谁？这并不重要，你就把我当作一个乐于助人但未交课程设计作业的大学生吧");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                                            好了，话不多说，快开始吧");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	system("CLS");//清屏
	for (z = 1; z <= 3; z++)
	{
		if (z == 1)
		{
			//            mciSendString("open bgm1.mp3 alias bgm1", NULL, 0, NULL);//打开音乐
			//            mciSendString("play bgm1 repeat", NULL, 0, NULL);//循环播放
			x = 1, y = 1, p = 5, q = 9;
			for (i = 0; i < 10; i++)
			{
				printf("%s", c[i]);
				printf("\n");
			}
			printf("当前步数: %d\n状态: \n", cot);
			system("color B");
			x = 1, y = 2;
			while (c[x][y] != -123 || !flag1)//只有在到达出口的坐标并且有钥匙的情况下退出循环
			{
				HideCursor();
				ch = getchar();
				getpd(ch);
			}
			system("CLS");//清屏
			printf("         恭喜你！勇者，你成功逃出了第一层迷宫\n");
			printf("             请按下enter键以前往下一层\n");
			printf("(注意！下一层开始会出现你无法击败的强大怪物，请注意躲避)");
			while (1)
			{
				char ss;
				ss = getchar();
				if (ss == '\n')
					break;
			}
			system("CLS");//清屏
		}

		if (z == 2)
		{
			cot = 0;
			srand(time(0));
			x = 4, y = 14, p = 5, q = 57, book = 0;
			for (i = 0; i <= 12; i++)
			{
				printf("%s", b[i]);
				printf("\n");
			}
			printf("当前步数: %d\n状态: \n", cot);
			system("color B");
			while (1)
			{
				a1 = rand() % 10 + 3;
				a2 = rand() % 47 + 3;
				if (!(a2 % 2))//一定要让光标列数在偶数位
				{
					if (b[a1][a2] != -95)//在可走的道路上随机生成形状为“◆”的怪物
					{
						gotoxy(a1, a2);
						printf("◆");
						time(a1, a2);
						break;
					}
				}
			}
			if (book == 1)
			{
				system("CLS");//清屏
				z = 1;
				printf(" 很遗憾，勇者，你被怪物抓住了\n");
				printf(" (请按下enter键重新挑战)\n");
			}
			else
			{
				system("CLS");//清屏
				printf("真不愧是天选之子，恭喜你！勇者，你可以前往最终试炼了\n");
				printf("         (请按下enter键以前往下一层)\n");
			}
			while (1)
			{
				char ss;
				ss = getchar();
				if (ss == '\n')
					break;
			}
			system("CLS");//清屏
		}
		if (z == 3)
		{
			cot = 0;
			x = 7, y = 32, p = 8, q = 118, book = 0;
			for (i = 0; i <= 18; i++)
			{
				printf("%s", a[i]);
				if (i != 18)
					printf("\n");
			}
			printf("当前步数: %d\n状态: \n", cot);
			while (1)
			{
				a1 = rand() % 17 + 1;
				a2 = rand() % 117 + 1;
				a3 = rand() % 17 + 1;
				a4 = rand() % 117 + 1;
				a5 = rand() % 17 + 1;
				a6 = rand() % 117 + 1;
				if (!(a2 % 2) && !(a4 % 2) && !(a6 % 2))
				{
					if (a[a1][a2] != -95 && a[a3][a4] != -95 && a[a5][a6] != -95)
					{
						gotoxy(a1, a2);
						printf("◆");
						gotoxy(a3, a4);
						printf("◆");
						gotoxy(a5, a6);
						printf("◆");
						time(a1, a2);
						break;
					}
				}
			}
			if (book == 1)
			{
				system("CLS");//清屏
				z = 2;
				printf(" 很遗憾，勇者，你被怪物抓住了\n");
				printf(" (请按下enter键重新挑战)\n");
				while (1)
				{
					char ss;
					ss = getchar();
					if (ss == '\n')
						break;
				}
				system("CLS");//清屏
			}
			else
			{
				system("CLS");//清屏
				printf("太强了，恭喜你！勇者，你成功逃出了迷宫\n");
				printf("当然我也没有闲着，我替你找回了你的武器:\n");
				system("color 2");
				printf("        *   \n");
				printf("       ***  \n");
				printf("       ***  \n");
				printf("       ***  \n");
				printf("       ***       圣遗物:湖女剑\n");
				printf("       ***  \n");
				printf("     *******\n");
				printf("       ***  \n");
				printf("       ***  \n");
				system("color 6");
				printf("那么，请你在以后继续用它惩奸除恶，做最强的勇者吧");
				Sleep(10000);
			}
		}
	}
	return 0;
}

