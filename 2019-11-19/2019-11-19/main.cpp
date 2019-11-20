#include<iostream>
#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#if 0


int main()
{
	char str[100];
	cin >> str;
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i ++ )
	{
		if (str[i] == 'a' || str[i] == 'o' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u')

		{
			cout << str[i] << endl;
			break;
		}
	}
	if(i>=len)
	cout << 'n' << endl;
	system("pause");
	return  0;
}
#endif
#if 0

int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		int num = i;
		while (num)
		{
			int a = num % 10;
			if (a == 2)
			{
				break;
			}
			num = num / 10;
		}
		if(num==0)
		count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int n;
	int a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i%a != 0 && i%b != 0 && i%c != 0)
		{
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int n,m;
	int r, c;
	cin >> n >> m;
	cin >> r >> c;

	int k = 1;
	int str[1000][1000];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			while (i < j)
			{
				str[i][j]
			}
		}
	}

	system("pause");
	return 0;
}
#endif
//int main()
//{
//
//	int n, m;
//	cin >> n >> m;
//	char str[1000][1000];
//	char str1[][1000] = {'.'};
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> str[i][j];
//		}
//	}
//	int k;
//	cin >> k;
//	
//	
//	for (int p = 0; p < k; p++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				str1[i][j] = str[i][j];
//
//				if (str[i][j] == 'g')
//				{
//					
//					if(j>0)
//					str1[i][j - 1] = 'g';
//					//if(j+1< m+1)
//					str1[i][j + 1] = 'g';
//					if(i>0)
//					str1[i - 1][j] = 'g';
//					//if(i+1<n+1)
//					str1[i + 1][j] = 'g';
//
//				}
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cout << str1[i][j];
//			}
//			cout << endl;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				str[i][j] = str1[i][j];
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << str1[i][j];
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
#if 0

int main()
{
	//cout << sqrt(22.2);
	//int n;
	//cin >> n;
	for (int i = 3; i <= 10000; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
			else
			{
				if (j > i );
				cout << i;
				break;
			}
		}
		

	}
	
	system("pause");
	return 0;
}

#endif
int main()
{
	int a[20][20] = { -1 };
	int t, x, y;
	int n, m;
	int r, c;
	t = a[x = 0][y = 0] = 1;
	cin >> n >> m;
	cin >> r >> c;
	while (t < n*m)
	{
		while (y + 1 < m && !a[x][y + 1])//ио 
			a[x][++y] = ++t;
		while (x + 1 < n && !a[x + 1][y])//ср 
			a[++x][y] = ++t;
		while (y - 1 >= 0 && !a[x][y - 1])//об 
			a[x][--y] = ++t;
		while (x - 1 >= 0 && !a[x - 1][y])//вС 
			a[--x][y] = ++t;
	}
	cout << a[r-1][c-1];
	system("pause");
	return 0;
}