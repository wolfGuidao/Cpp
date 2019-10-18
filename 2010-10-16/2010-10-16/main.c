//给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径上所有的数字
//累加起来就是路径和，输出所有的路径中最小的路径和。


#include<stdio.h>
int main()
{
	int n, m;
	int i = 0;
	int j = 0;
	int a[2000][2000];
	int min = 0;
	scanf("%d%d", &n, &m);
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			scanf("%d", &a[i][j]);
			getchar();
		}
	}
	for (i = 1;i < n;i++)
	{
		a[i][0] += a[i - 1][0];
	}
	for (j = 1;j < m;j++)
	{
		a[0][j] += a[0][j - 1];
	}
	for (i = 1;i < n;i++)
	{
		for (j = 1;j < m;j++)
		{
			min = a[i][j - 1] <= a[i - 1][j] ? a[i][j - 1] : a[i - 1][j];
			a[i][j] += min;
		}
	}
	printf("%d", a[n - 1][m - 1]);
	return 0;
}
//小易有一个古老的游戏机，上面有着经典的游戏俄罗斯方块。因为它比较古老，所以规则和一般的俄罗斯方块不同。
//荧幕上一共有 n 列，每次都会有一个 1 x 1 的方块随机落下，在同一列中，后落下的方块会叠在先前的方块之上，当一整行方块都被占满时，这一行会被消去，并得到1分。
//有一天，小易又开了一局游戏，当玩到第 m 个方块落下时他觉得太无聊就关掉了，小易希望你告诉他这局游戏他获得的分数。
//输入描述 :
//第一行两个数 n, m
//第二行 m 个数，c1, c2, ..., cm ， ci 表示第 i 个方块落在第几列
//其中 1 <= n, m <= 1000, 1 <= ci <= n
//输出描述 :
//小易这局游戏获得的分数


#include<stdio.h>
int main()
{
	int a[1000];
	int i = 0;
	int n, m;
	int k = 0;
	scanf("%d%d", &n, &m);
	for (i = 1;i <= n;i++)
	{
		a[i] = 0;
	}
	for (i = 1;i <= m;i++)
	{
		scanf("%d", &k);
		a[k]++;
	}
	int min = a[1];
	for (i = 1;i <= n;i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	printf("%d", min);
	return 0;
}