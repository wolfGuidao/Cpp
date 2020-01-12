#include <iostream>

using namespace std;

int main()
{
	int arr[1000000];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int j = i - 1;

		while (j >= 0)
		{
			if (arr[j] < arr[i])
			{
				cout << j << " ";
				break;
			}
			else
			{
				j--;
			}
		}
		if (j < 0)
		{
			cout << -1 << " ";
		}
		int k = i + 1;
		while (k < n)
		{
			if (arr[k] < arr[i])
			{
				cout << k << " " << endl;
				break;
			}
			else
			{
				k++;
			}
		}
		if (k >= n)
		{
			cout << -1 << " " << endl;
		}
	}

	return 0;
}