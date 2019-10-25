#include<iostream>
#include<Windows.h>
using namespace std;
template<class T>
T Add(T a, T b)
{
	cout << typeid(T).name << endl;
	return a + b;
}
int main()
{
	cout << Add(1,2) << endl;
	cout << Add(1.1, 2.0) << endl;
	cout << Add<int>('a', 'b') << endl;

	system("pause");
	return 0;
}