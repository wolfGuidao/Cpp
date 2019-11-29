#include<iostream>
using namespace std;

#if 0

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		/*
		vector<int>ret1;
		vector<int>ret2;

		for(int i=0;i<array.size();i++)
		{
			for(int j=i+1;j<array.size();j++)
			{
				if(array[i]+array[j]==sum)
				{
					ret2.push_back(array[i]);
					ret2.push_back(array[j]);
				}
			}
		}
		if(!ret2.empty())
		{
			ret1.push_back(ret2[0]);
			ret1.push_back(ret2[1]);
		}
		else
		{
			return ret1;
		}

		for(int i=0;i<ret2.size();i=i+2)
		{
			int multiply=ret2[0]*ret2[1];
			int temp=ret2[i]*ret2[i+1];

			if(multiply>temp)
			{
				ret1.clear();
				ret1.push_back(ret2[i]);
				ret1.push_back(ret2[i+1]);
				multiply=temp;
			}
		}
		return ret1;
		*/
		vector<int>ret;
		//vector<int>ret;
		if (array.size() < 2)
		{
			return ret;
		}
		int i = 0;
		int j = array.size() - 1;
		while (i < j)
		{
			if (array[i] + array[j] == sum)//因为数组是递增排序的，
			{
				ret.push_back(array[i]);
				ret.push_back(array[j]);//如果找到相等的两个数就直接返回，因为先找到
				//的肯定是最小的
				return ret;
			}
			else if (array[i] + array[j] > sum)
			{
				j--;//如果结果大于sum，就直接把j--，让结果变小一点
			}
			else
			{
				i++;//如果结果小于sum，就直接把i++，让结果变大一点
			}
		}
		return ret;//其他情况包括没找到，就直接返回
	}
};

#endif
#include<vector>
#if 0
int main()
{
	/*
	char str1[] = "hello";
	char str2[] = "world";
	str1 = str2;
	*/
	vector<int>ret(2);
	cout << ret[0] <<ret[1]<< endl;
	system("pause");
	return 0;
}
#endif
#include <string>     // std::string, std::to_string

int main()
{
	/*
	std::string pi = "pi is " + std::to_string(3.1415926);
	std::string perfect = std::to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";
	string ss = to_string(2);
	
	std::cout << pi << '\n';
	std::cout << perfect << '\n';
	*/

	system("pause");
	return 0;
}