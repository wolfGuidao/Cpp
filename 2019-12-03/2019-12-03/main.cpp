#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		//本题主要思想是丑数乘以丑数还是丑数，反之则不是丑数
		if (index < 7)
		{
			return index;
		}
		vector<int>ret;//存储结果
		//题意要求排序的第N个丑数，所以定义个队列，每次往ret中放的时候放3个队列对首元素
		//最小的，然后再把这个最小的丑数分别乘以2，3，5放到相应的队列里面
		queue<int>q2;//存储乘以2的丑数
		queue<int>q3;//存储乘以3的丑数
		queue<int>q5;//存储乘以5的丑数

		ret.push_back(1);//1是丑数，直接放到ret中
		q2.push(ret[0] * 2);
		q3.push(ret[0] * 3);
		q5.push(ret[0] * 5);
		while (ret.size() < index)
		{
			int Min = min(q2.front(), min(q3.front(), q5.front()));//取3个队列
			//对首元素较小的Min放到ret中
			//取得是那个队列的元素就把那个队列的队首元素出队
			if (q2.front() == Min)
			{
				q2.pop();
			}
			if (q3.front() == Min)
			{
				q3.pop();
			}
			if (q5.front() == Min)
			{
				q5.pop();
			}
			ret.push_back(Min);
			q2.push(Min * 2);//并把这个较小的元素分别乘以2，3，5放到相应的队列里
			q3.push(Min * 3);
			q5.push(Min * 5);

		}
		return ret[ret.size() - 1];//返回最后一个元素，就是第N个丑数
	}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() < 1 || vin.size() < 1)
		{
			return nullptr;
		}

		vector<int>pre_right;
		vector<int>pre_left;
		vector<int>vin_right;
		vector<int>vin_left;

		TreeNode* head = new TreeNode(pre[0]);
		int flag;
		for (size_t i = 0; i < vin.size(); i++)
		{
			if (vin[i] == pre[0])
			{
				flag = i;
				break;
			}
		}

		for (size_t i = 0; i < flag; i++)
		{
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);
		}
		for (size_t i = flag + 1; i < vin.size(); i++)
		{
			vin_right.push_back(vin[i]);
			pre_right.push_back(pre[i]);
		}
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);
		return head;
	}
};

int main()
{
	int n;

	while (cin >> n)
	{
		int a = 1;
		int b = 1;
		int c = 0;

		int num = n - 1;
		int count = abs(1 - n);
		while (num-- > 0)
		{
			c = a + b;
			if (abs(c - n) < count)
			{
				count = abs(c - n);
			}
			a = b;
			b = c;
		}
		cout << count;

	}
	return 0;
}