#include<stdio.h>
int main()
{
	int n, m;
	int i = 0;
	int j = 0;
	int a[2000][2000];
	int min = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			getchar();
		}
	}
	for (i = 1; i < n; i++)
	{
		a[i][0] += a[i - 1][0];
	}
	for (j = 1; j < m; j++)
	{
		a[0][j] += a[0][j - 1];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			min = a[i][j - 1] <= a[i - 1][j] ? a[i][j - 1] : a[i - 1][j];
			a[i][j] += min;
		}
	}
	printf("%d", a[n - 1][m - 1]);
	return 0;
}