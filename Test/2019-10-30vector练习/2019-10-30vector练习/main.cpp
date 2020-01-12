#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
using namespace std;

#if 0
void Testvector1()
{
	//string a;
	//a.reserve(100);
	////a += "wolf";
	//a[0] = 'H';
	//cout << a << endl;
	/*vector<int>a;
	a.reserve(100);
	a[0] = 12;//相当于越界访问，会出错
	for (auto i : a)
	{
		cout << i;
	}*/
	/*string a("wolf guidao");
	auto it = a.begin();
	a.push_back('i');
	while (it != a.end())
	{
		cout << *it;
		it++;
	}*/
	vector<int>a{ 1,2,3,4,5,6,7,8,9,0 };
	a.reserve(20);
	//vector<int>::iterator it=a.begin();
	auto it = a.begin();//auto的强大功能
	
	a.push_back(1);
	while (it != a.end())
	{
		cout << *it<<" ";
		it++;
	}
}
#endif

void Testvector1()
{
	//string s("wolf guidao");
	vector<int> a{ 1,2,3,4,5,6,7,8,9,0 };
	//string::iterator it = s.begin();
	//s.erase(it);
	//cout << s << endl;
	//vector<int>::iterator it1 = a.begin();
	//a.erase(it1+a.size());
	//a.erase(a.end()-1);
	/*cout << a[a.size()-1];
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;*/
	vector<char>s{ 'w','l','o','l','f' };
	for (auto i = 0;i < s.size();i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	vector<char>s1(s);
	vector<char>s2 = s1;
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Testvector2()
{
	vector<int>a1(10, 9);//构造函数
	vector<int>a2(a1.begin()+2, a1.end()-2);//区间构造
	vector<int>a3(a1);//拷贝构造
	vector<int>a4;
	/*for (auto e : a1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : a2)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : a3)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : a4)
	{
		cout << e << " ";
	}
	cout << endl;*/
	/*int arr[] = { 1,2,3,4,5,6,7,89 };

	vector<int>a5(arr, arr + 2);//也算是区间构造
	for (auto e : a5)
	{
		cout << e << " ";
	}
	cout << endl;*/
}

void Testvector3()
{
	vector<int>a1{ 1,2,3,4,5,6,7,8,9,0 };
	auto it = a1.begin();
	*it = 99;
	cout << a1[0] << endl;
	auto it1 = a1.rbegin();
	while (it1 != a1.rend())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	a1.reserve(20);
	a1.resize(20, 9);
	it1 = a1.rbegin();
	while (it1 != a1.rend())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	auto it2 = a1.begin();
	while (it2 != a1.end())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
void Testvector4()
{
	/*string a("wolf guidao");
	a.pop_back();
	cout << a;
	vector<int>a1{ 1,2,3,4,5,6,7,8,9,0 };
	auto it = a1.begin();
	a1.insert(it+2, 99);
	cout << a1[2];*/
}
void Testvector5()
{
	//vector<int>a[3]{ {1,2},{1,4,9,3,} };
	//a->reserve(10);
	/*for (auto i = 0;i < a->size();i++)
	{
		for (auto j = 0;j < a[i].size();j++)
		{
			a[i][j] = j;
		}
	}*/
	/*if (a->size() == a[1].size())
	{
		cout << a->size() << endl;
	}
	else
	{
		cout << a[1].size();
	}*/
	/*cout << a[0].size() << endl;
	cout << a->size() << endl;*/
	//cout << endl;
	//cout << a[0][0] << endl;
	//cout << a[0].size();
	vector<int>a;
	a.resize(10);
	//a[0] = 1;
	cout << a[0] << endl;
	vector<int>b{ 1,2,3 };
	b[0] = 99;
	cout << b[0];
}


	/*vector<int>a{1,2};
	auto it = a.begin();
	a.pop_back();
	cout << a[0];*/
	/*string a;
	getline(cin, a);*/
	//cout << (('123'-'0')*2) << endl;
	string s("wolf guidao");
	/*auto it = s.begin();
	it = it + 1;
	reverse(it,it+2);
	cout << s;*/
	//auto it = s.begin();
	//cout << s.find(" ", 3);

//
//	给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//		示例 1 :
//
//输入: "Let's take LeetCode contest"
//	输出 : "s'teL ekat edoCteeL tsetnoc"
//
	
	//class Solution {
	//public:
	//	string reverseWords(string s) {
	//		auto it = s.begin();
	//		int i = 0;//记录it的位置
	//		int index1 = 0;//记录下一个空格的位置
	//		int index2 = 0;//记录上一个空个位置
	//		while (it != s.end())//没走到结尾
	//		{
	//			index1 = s.find(' ', i);//找到空格的位置，用index记录下来
	//			if (index1 == string::npos&&s.begin() != it)//在不是只有一个单词且不是第一个单词基础上找不到空格，说明已经到一行字符的最后一个单词处
	//			{
	//				reverse(it + 1, s.end());//直接交换剩下的，it加1是因为it此时位置处刚好是空格
	//				break;//退出循环
	//			}
	//			else
	//			{
	//				int temp = index1 - index2;//计算中间元素的个数
	//				if (it == s.begin())//如果是第一个单词，因为第一个单词it加上temp后刚好在空格处，刚好完成第一个单词交换
	//				{
	//					reverse(it, it + temp);
	//					i = i + temp + 1;//如果是第一个单词，i+ temp + 1后i就到下一个空格的后面
	//				}
	//				else if (string::npos == index1)//如果只有一个单词，就直接交换所有
	//				{
	//					reverse(it, it + s.size());
	//					break;
	//				}
	//				else//不是只有一个单词或不是第一个单词
	//				{
	//					reverse(it + 1, it + temp);//it+1是因为it位置在空格处，不能交换空格
	//					i = i + temp;//这种情况下，i = i + temp;i就到达下一个空格的后面
	//				}
	//				it = it + temp;
	//				index2 = index1;//index2保存上一个空格的位置
	//			}
	//		}
	//		return s;
	//	}
	//};

	/*给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

		示例 :

输入: s = "abcdefg", k = 2
	输出 : "bacdfeg"*/
	/*class Solution {
	public:
		string reverseStr(string s, int k) {
			int len = s.size();
			int len1 = 0;
			auto it = s.begin();
			while (len - len1 >= 2 * k)
			{
				reverse(it, it + k);
				it += 2 * k;
				len1 += 2 * k;
			}
			if (len - len1 < k)
			{
				reverse(it, s.end());
			}
			else
			{
				reverse(it, it + k);
			}
			return s;
		}
	};
	void Testvector8()
	{
		vector<string> s;
		string s1{ 'a','b' };
		string s2{ 'a','b' };
		string s3{ 'a','b' };
		string s4{ 'a','b' };
		s = { s1,s2,s3 };
		cout<<s.size();

	}*/

	class Solution {
	public:
		vector<string> letterCombinations(string digits) {//456
			vector<string>s{"abc","def","ghi","jll","mno","pqrs","tuv","wxyz"};//-2下标
		//////////////////////0/////1/////2/////3//////4////5///////6/////7///下标
			/////////////////2//////3////4/////5///////6////7///////8/////9///电话数字
			vector<string>s1;
			string s2(1, 0);
			s1.resize(100, s2);
			string s3;
			string s4;
			for (int i = 0;i < digits.size();i++)
			{
				//digits[0]//digits[1]
				for (int j = 0;j < s[digits[i]-'0'-2].size();j++)
				{
					for (int k = 0;k < s[digits[i+1] - '0'- 2].size();k++)
					{
						s3 = "s[digits[i] - '0' - 2][j]s[digits[i + 1] - '0' - 2][k]";
						s1.push_back(s3);//s[digits[i] - 2][j];s[digits[i + 1] - 2];
						
					}
				}
				break;
			}
			return s1;
		}
	};


int main()
{
	//vector<string>s{ "abd","vff" };
	//cout << s.size();
	//cout<<s[0].size();
	string s1("12");
	Solution a;
	a.letterCombinations(s1);
	system("pause");
	return 0;
}