#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
int a[9][9], n, sum;
int row1[9], diagl1[17], diagr1[17], row2[9], diagl2[17], diagr2[17];
void dfs2(int i)
{
	int j;
	if (i == n + 1)
	{
		sum++;
		return;
	}
	for (j = 1;j <= n;j++)
	{
		if (a[i][j] == 1 && row2[j] != 0 && diagl2[n - i + j] != 0 && diagr2[i + j] != 0)
		{
			a[i][j] = 0;
			row2[j] = 0;
			diagl2[n - i + j] = 0;
			diagr2[i + j] = 0;
			dfs2(i + 1);
			row2[j] = 1;
			diagl2[n - i + j] = 1;
			diagr2[i + j] = 1;
			a[i][j] = 1;
		}
	}
}
void dfs1(int i)
{
	int j, h, r;
	if (i == n + 1)
	{
		for (h = 1, r = 1;r <= n;r++)
		{
			if (a[1][r] == 1)
			{
				a[1][r] = 0;
				row2[r] = 0;
				diagl2[n - h + r] = 0;
				diagr2[h + r] = 0;
				dfs2(h + 1);
				row2[r] = 1;
				diagl2[n - h + r] = 1;
				diagr2[h + r] = 1;
				a[1][r] = 1;
			}
		}
	}
	for (j = 1;j <= n;j++)
	{
		if (a[i][j] == 1 && row1[j] != 0 && diagl1[n - i + j] != 0 && diagr1[i + j] != 0)
		{
			a[i][j] = 0;
			row1[j] = 0;
			diagl1[n - i + j] = 0;
			diagr1[i + j] = 0;
			dfs1(i + 1);
			row1[j] = 1;
			diagl1[n - i + j] = 1;
			diagr1[i + j] = 1;
			a[i][j] = 1;
		}
	}
}

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
				scanf("%d", &a[i][j]);
		for (i = 1;i <= n;i++)
			row1[i] = row2[i] = 1;
		for (i = 1;i <= 2 * n;i++)
			diagl1[i] = diagr1[i] = diagl2[i] = diagr2[i] = 1;
		for (i = 1, j = 1;j <= n;j++)
		{
			if (a[1][j] == 1)
			{
				a[1][j] = 0;
				row1[j] = 0;
				diagl1[n - i + j] = 0;
				diagr1[i + j] = 0;
				dfs1(i + 1);
				row1[j] = 1;
				diagl1[n - i + j] = 1;
				diagr1[i + j] = 1;
				a[1][j] = 1;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
