#include<iostream>
#include<Windows.h>
#include<vector>
#include<list>
#include<string>
using namespace std;
int strStr(char * haystack, char * needle) {
	int len1 = strlen(haystack);
	int i = 0;
	char* start;
	char* start1 = needle;
	char* start3 = haystack;
	const char* str1 = "";
	if (*haystack == *needle &&*needle == *str1)
	{
		return 0;
	}
	else
	{
		while (*haystack != '\0')
		{
			start = haystack;
			while (*needle == *haystack&&*needle != '\0')
			{
				needle++;
				haystack++;
			}
			if (*needle != *haystack&&*needle != '\0')
			{
				haystack = start + 1;
				needle = start1;
			}
			else if (*needle == '\0')
			{
				while (start3 != start)
				{
					i++;
					start3++;
				}
				return i;
			}
		}
		return -1;
	}
}

void Testlist()
{
	list<int>l1(5, 9);
	list<int>l2(l1);
	list<int>l3{ 9,9,9,9,9,0,9,9 };
	list<int>l4 = l3;
	for (auto e : l1)
	{
		cout<<e<<" ";
	}
	cout << endl;
	for (auto e : l2)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : l3)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : l4)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Testlist2()
{
	list<int>l1{ 5,5,7,1,2,3,4,5,6,5,5,5,7,7,7,8,9 };
	/*for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
	l1.remove(5);
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;*/
	cout << l1.back();
	l1.sort();
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << l1.front();
}

//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int Max = (1 - 0)*min(height[1], height[0]);
//		for (int i = 0;i < height.size();i++)
//		{
//			for (int j = i + 1;j < height.size();j++)
//			{
//				if (Max < (j - i)*min(height[i], height[j]))
//				{
//					Max = (j - i)*min(height[i], height[j]);
//				}
//			}
//		}
//		return Max;
//	}
//};


//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		string s1;
//		if (s.size() == 0)
//		{
//			return 0;
//		}
//		else if (s.size() == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			int max = s1.size();
//			int i = 1;
//			int j = 0;
//			int count = 0;
//			s1.push_back(s[0]);
//		 	int index = 0;
//			while(i < s.size())
//			{
//				count = 0;//每次都置为0
//				for (j = 0;j < s1.size();j++)//判断s1中所有元素是否存在s[i]
//				{
//					if(s[i] != s1[j])//遍历s1所有元素
//					{
//						count++;//因为如果出现相等的元素，count少加一次，count就比size（）少一个
//					}
//				}
//				if (count == s1.size())//如果相等，说明遍历完s1，没出现相等的元素
//				{
//					s1.push_back(s[i]);//就把s[i]尾插到s1中
//					max = max > s1.size() ? max : s1.size();//因为不是只比较一次，而是取所有次数中最大的一个size（）
//					i++;
//				}
//				else//否则就是遍历完s1发现找到相等的字符，
//				{
//					s1.clear();//清空s1，进行下一次插入
//					i = s.find(s[i], index)+1;//从index位置处开始找是s[i]
//					index += 1;//每次从下一个位置开始往后比较
//				}
//			}
//			return max;
//		}	
//	}
//};

//class Solution {
//public:
//	double myPow(double x, int n) {
//		double num1 = 1.0;
//		if (n == 1)
//		{
//			return x;
//		}
//	    if (n == 0)
//		{
//			return 1.0;
//		}
//		else if (n > 0)
//		{
//			num1 *= myPow(x, --n);
//		}
//		else
//		{
//			num1 /= myPow(x, ++n);
//		}
//		return num1;
//
//	}
//};
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//		int count = 0;
//		if ((dividend > 0 && divisor > 0)|| (dividend < 0 && divisor < 0))
//		{
//			while (abs(dividend) - abs(divisor) >= 0)
//			{
//				dividend -= divisor;
//				count++;
//			}
//
//		}
//		else if (dividend < 0 && divisor > 0)
//		{
//			while (dividend + divisor <= 0)
//			{
//				dividend += divisor;
//				count++;
//			}
//			count = -count;
//		}
//		else if (dividend > 0 && divisor < 0)
//		{
//			while (dividend + divisor >= 0)
//			{
//				dividend += divisor;
//				count++;
//			}
//			count = -count;
//		}
//		else
//		{
//			count = 0;
//		}
//		return count;
//	}
//};

class Solution {
public:
	bool checkRecord(string s) {
		string s1(s);
		int countA = 0;
		int countL = 0;
		auto it = s1.begin();
		int j = 0;
		for (size_t i = 0;i < s1.size();i++)
		{
			if (s1[i] == 'A')
			{
				countA++;
			}
		}
		for (size_t i = 1;i < s1.size();i++)
		{
			
			if ((s1[i] == s1[i - 1]) && (s1[i - 1] =='L'))
			{
				countL++;
			}
			
		}
		if (countA <= 1 && countL <= 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	//vector<int> a{ 1,8,6,2,5,4,8,3,7 };
	//string s1("bpfbhmipx");
	/*int a;
	int b;
	cin >> a >> b;
	cout << "结果为：" << endl;
	Solution s;
	cout<<s.divide(a, b)<<endl;*/
	/*string s("wolf guidao");
	auto it = s.begin();
	s.erase(it);
	cout << s;*/
	string s1("LLPPPLL");
	Solution s;
	cout<<s.checkRecord(s1);
	system("pause");
 	return 0;
}
