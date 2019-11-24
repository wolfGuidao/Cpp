#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

#if 0

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
		int ret1 = 0;
		int ret2 = 0;
		int ret = 0;
		for (size_t i = 0; i < data.size(); i++)
		{
			ret ^= data[i];//ret存储那两个只出现一次的异或结果
		}
		int pos = 0;//找ret中为1的位用pos保存起来
		for (int i = 0; i < 31; i++)
		{
			if ((ret & (1 << i)))
			{
				pos = i;
				break;
			}
		}


		for (size_t i = 0; i < data.size(); i++)
		{
			if ((data[i] & (1 << pos)) == 0)//遍历data，把data中元素在pos位为1的和在pos位为
				//0的分为2组，因为如果某个元素出现了两次，那么该元素在pos位上要么为0，要么
				//为1，反正肯定在同一组，如果某个元素只出现了一次，和另外一个只出现一次的元素
				//肯定在不同组，这样就把问题转换为在一组数据中找一个只出现一次的元素了
			{
				ret1 ^= data[i];
			}
			else
			{
				ret2 ^= data[i];
			}
		}
		*num1 = ret1;
		*num2 = ret2;
	}
};

void test()
{
	vector<int>l = { 4,6,2,2,3,3,8,8,9,9,1000000,1000000 };
	Solution s;
	int a;
	int b;
	
	s.FindNumsAppearOnce(l,&a,&b);
	//cout << *num1 << " " << *num2  ;
	cout << a <<"  "<< b << endl;
	//cout << ret1 << endl;
	//cout << ret2 << endl;
}

#endif

#if 0

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int count = 1;
		if (numbers.size() == 1)
		{
			return numbers[0];
		}
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i - 1] == numbers[i])
			{
				count++;
			}
			else
			{
				if (count > (numbers.size() / 2))
				{
					return numbers[i - 1];
				}
				else
				{
					count = 1;

				}
			}
		}
		return 0;
	}
};

#endif

#include<string>

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		/*
		char str1[100]={0};
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			{
				str1[str[i]-'a'+1]++;
			}
			else
			{
				str1[str[i]-'A'+27]++;
			}

		}
		for(int i=1;i<100;i++)
		{
			if(str1[i]==1)
			{
				if(i<=26)
				{
					return str.find((i-1)+'a');
				}
				else if(i<=52)
				{
					return str.find(i-27+'A');
				}
			}
		}
		return -1;
		*/
		int i = 0;
		for ( ;i < str.size();i++)
		{
			int j = 0;
			while (j < str.size())
			{
				if (str[i] != str[j]&& i != j)
				{
					j++;
				}
				else if (str[i] == str[j] && i == j)
				{
					j++;
				}
				else
				{
					
					break;
				}
			}
			if (j == str.size())
			{
				return i;
			}
		}
		return -1;
	}
};

#if 0

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];//存储最后的结果
		int tempsum = array[0];//临时存储连续子序列的和
		for (int i = 1; i < array.size(); i++)
		{
			if (tempsum >= 0)//如果tempsum大于0，说明还可以继续加下一个元素，
			{
				tempsum += array[i];
				sum = sum > tempsum ? sum : tempsum;//每次取最大连续子序列的和

			}
			else
			{
				tempsum = array[i];//如果tempsum结果小于0，说明tempsum在加上某个元素后
				//变为负数，此时就不能再加了，得把tempsum置为当前元素，从新开始计算
				//tempsum，注意元素本身可能为负数，所以每次都要比较
				sum = sum > tempsum ? sum : tempsum;//每次都要保存最大连续子序列的和，因为可能出现
				//数组中所有元素都是负数

			}
		}
		return sum;
	}
};

#endif

void test()
{
	Solution s;
	string s1 = "google";
	s.FirstNotRepeatingChar(s1);
}

int main()
{
	test();
	system("pause");
	return 0;
}