#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
int f = 3;
ll mod = 1e9 + 7;
struct node {
	ll materix[5][5];
};

node mul(node a, node b)
{
	node res;
	memset(res.materix, 0, sizeof(res.materix));
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= f; j++)
		{
			for (int k = 1; k <= f; k++)
			{
				res.materix[i][j] = (res.materix[i][j] + a.materix[i][k] * b.materix[k][j] % mod) % mod;
			}
		}
	}
	return res;
}

node ksm(node a, ll b)
{
	node ans;
	memset(ans.materix, 0, sizeof(ans.materix));
	for (int i = 1; i <= f; i++)
		ans.materix[i][i] = 1;
	while (b)
	{
		if (b & 1)
			ans = mul(ans, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ans;
}
int main()
{
	while (cin >> n)
	{
		if (n == 1 || n == 2)
			cout << n << endl;
		else
		{
			node a, b, ans;
			memset(a.materix, 0, sizeof(a.materix));
			a.materix[1][1] = 3;
			a.materix[2][1] = 2;
			a.materix[3][1] = 1;

			b.materix[1][1] = 1, b.materix[1][2] = 0, b.materix[1][3] = 1;
			b.materix[2][1] = 1, b.materix[2][2] = 0, b.materix[2][3] = 0;
			b.materix[3][1] = 0, b.materix[3][2] = 1, b.materix[3][3] = 0;
			ans = ksm(b, n - 3);
			ans = mul(ans, a);
			ll init = ans.materix[1][1];
			cout << init << endl;
		}
	}
	return 0;
}
