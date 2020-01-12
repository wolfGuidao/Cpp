#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include<list>
using namespace std;
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		vector<string>s1(min(numRows,s.size()));//定义一个vector<string>型的s1，vector的每一行对应存放Z字形的每一行
//		string s2;//定义一个s2最后按行遍历s1
//		if (numRows == 1)
//		{
//			return s;
//		}
//		bool goingDown = false;//定义goingDown控制方向
//		int index = 0;//是s1的下标
//		for (auto e : s)//遍历用户输入的s
//		{
//			s1[index] += e;
//			if (index == 0 || index == numRows - 1)//如果在第一行或最后一行，Z自行的方向会发生该变
//			{
//				goingDown = !goingDown;
//			}
//			index += goingDown ? 1 : -1;//控制下标的移动
//		}
//		for (auto e : s1)//遍历s1的每一行，把每一行的元素追加到s2中
//		{
//			s2 += e;
//		}
//		return s2;
//	}
//};

//class Solution {
//public:
//	string intToRoman(int num) {
//		string s;
//		if (num >= 1000)
//		{
//			int count = num / 1000;
//			for (int i = 0;i < count;i++)
//			{
//				s += 'M';
//				num -= 1000;
//			}
//		}
//		if (num >= 500 && num < 1000)
//		{
//			if (num >= 900)
//			{
//				s += "CM";
//				num -= 900;
//			}
//			else
//			{
//				s += 'D';
//				num -= 500;
//			}
//		}
//		if (num >= 100 && num < 500)
//		{
//			if (num >= 400)
//			{
//				s += "CD";
//				num -= 400;
//			}
//			else
//			{
//				int count = num / 100;
//				for (int i = 0;i < count;i++)
//				{
//					s += 'C';
//					num -= 100;
//				}
//			}
//		}
//		if (num >= 50 && num < 100)
//		{
//			if (num >= 90)
//			{
//				s += "XC";
//				num -= 90;
//			}
//			else
//			{
//				s += 'L';
//				num -= 50;
//			}
//		}
//		if (num >= 10 && num < 50)
//		{
//			if (num >= 40)
//			{
//				s += "XL";
//				num -= 40;
//			}
//			int count = num / 10;
//			for (int i = 0;i < count;i++)
//			{
//				s += 'X';
//				num -= 10;
//			}
//		}
//		if (num >= 5 && num < 10)
//		{
//			if (num == 9)
//			{
//				s += "IX";
//				num -= 9;
//			}
//			else
//			{
//				s += 'V';
//				num -= 5;
//			}
//		}
//		if (num < 5)
//		{
//			if (num == 4)
//			{
//				s += "IV";
//				num -= 4;
//			}
//			else
//			{
//				int count = num;
//				for (int i = 0;i < count;i++)
//				{
//					s += 'I';
//					num -= 1;
//				}
//
//			}
//		}
//		if (num == 0)
//		{
//			return s;
//		}
//	}
//};

//class Solution {
//public:
//	int romanToInt(string s) {
//		int num = 0;
//		auto it = s.begin();
//		for (it;it!=s.end();it++)
//		{
//			if (*it == 'M')
//			{
//				num += 1000;
//			}
//			if (*it == 'D')
//			{
//				num += 500;
//			}
//			if (*it == 'C')
//			{
//				if (*(it+1) == 'D')
//				{
//					num += 400;
//					it++;
//				}
//				else if (*(it+1) == 'M')
//				{
//					num += 900;
//					it++;
//				}
//				else
//					num += 100;
//			}
//			if (*it == 'L')
//			{
//				num += 50;
//			}
//			if (*it == 'X')
//			{
//				if (*(it+1) == 'L')
//				{
//					num += 40;
//					it++;
//				}
//				else if (*(it+1) == 'C')
//				{
//					num += 90;
//					it++;
//				}
//				num += 10;
//			}
//			if (*it == 'V')
//			{
//				num += 5;
//			}
//			if (*it == 'I')
//			{
//				if (*(it+1) == 'V')
//				{
//					num += 4;
//					it++;
//				}
//				else if (*(it+1) == 'X')
//				{
//					num += 9;
//					it++;
//				}
//				else
//				{
//					num += 1;
//				}
//			}
//		}
//		return num;
//	}
//};


//class Solution {
//public:
//	string defangIPaddr(string address) {
//		string s;
//		for (size_t i = 0;i < address.size();i++)
//		{
//			if (address[i] == '.')
//			{
//				s.push_back('[');
//				s.push_back(address[i]);
//				s.push_back(']');
//
//			}
//			else
//			{
//				s.push_back(address[i]);
//			}
//		}
//		return s;
//	}
//};

class Solution {
public:
	string toLowerCase(string str) {
		string s;
		for (size_t i = 0;i < str.size();i++)
		{
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
			{
				str[i] += 32;
				s.push_back(str[i]);
			}
			else
			{
				s.push_back(str[i]);
			}
		}
		return s;
	}
};

//int Split(int *data, int pre, int rear)
//{
//	int value = data[pre];
//	while (pre < rear)
//	{
//		while (data[rear] >= value && pre < rear) rear--;
//		data[pre] = data[rear];
//		while (data[pre] < value && pre < rear) pre++;
//		data[rear] = data[pre];
//	}
//	data[pre] = value;
//	return pre;
//}
//
////快速排序
//void QuickSort(int *data, int pre, int rear)
//{
//	if (pre < rear)
//	{
//		int mid = Split(data, pre, rear);
//		QuickSort(data, pre, mid - 1);
//		QuickSort(data, mid + 1, rear);
//	}
//}
//
//int* sortedSquares(int* A, int ASize, int* returnSize) {
//	int *str;
//	for (int i = 0;i < ASize;i++)
//	{
//		A[i] *= A[i];
//	}
//	QuickSort(A, 0, ASize - 1);
//	str = A;
//	return str;
//}

int main()
{
	Solution s;
	string s1("Hello");
	string s2 = s.toLowerCase(s1);
	cout << s2;
	//vector<vector<int>>newMatrix;
	//newMatrix.resize(2);
	//
	//for (int i = 0;i < 3;i++)
	//{
	//	newMatrix[i].resize(2);
	//	for (int j = 0;j < 4;j++)
	//	{
	//		newMatrix[i][j] = i;
	//	}
	//}
	//cout << newMatrix.size() << " " << newMatrix[0].size() << endl;
	//newMatrixSolution s;
	//string s1("Hello");
	//cout << s.toLowerCase(s1);
	/*s1 = s.intToRoman(1994);
	cout << s1;*/
	/*string s1("LEETCODEISHIRING");
	string s2= s.convert(s1, 3);
	cout << s2;*/
	/*vector<int>a;
	list<int>a1;
	*/
	system("pause");
	return 0;
}