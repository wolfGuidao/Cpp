#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

#if 0

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>ret;
		int m = matrix.size();
		int n = matrix[0].size();
		int num = m * n;
		int x = 0;
		int y = 0;
		//ret.push_back(matrix[0][0]);
		while (num  > 0)
		{
			while (y + 1 < n&&matrix[x][y + 1] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				y++;
				num--;
			}
			while (x + 1 < m&&matrix[x + 1][y] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				x++;
				num--;
			}
			while (y - 1 >= 0 && matrix[x][y - 1] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				y--;
				num--;
			}
			while (x - 1 >= 0 && matrix[x - 1][y] != 0)
			{
				ret.push_back(matrix[x][y]);
				matrix[x][y] = 0;
				x--;
				num--;
			}
			if (num == 1)
			{
				ret.push_back(matrix[x][y]);
				num--;
			}
		}
		return ret;
	}
};

class Solution {
public:
	int temp = 0;
	stack<int>s;
	void push(int value) {
		if (s.empty())
		{
			temp = value;
			s.push(value);
			s.push(temp);
		}
		else
		{
			temp = temp > value ? value : temp;
			s.push(value);
			s.push(temp);
		}
	}
	void pop() {
		s.pop();
		s.pop();
	}
	int top() {
		s.pop();
		int num = s.top();
		s.pop();
		return num;
	}
	int min() {
		return s.top();
	}
};


void test()
{
	Solution s;
	vector<vector<int>>l{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int>ret;
	ret=s.printMatrix(l);
	int count = 0;
	for (auto e : ret)
	{
		count++;
		cout << e;
		if (count % 4 == 0)
		{
			cout << endl;
		}
	}
}

#endif

#if 0

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int>ret;
		queue<TreeNode*>q;
		if (root == nullptr)
		{
			return ret;
		}
		q.push(root);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			ret.push_back(cur->val);
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);

		}
		return ret;
	}
};

#endif

#if 0

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int>ret;
		sort(input.begin(), input.end());
		if (k<1 || k>input.size())
		{
			return ret;
		}
		for (int i = 0; i < k; i++)
		{
			ret.push_back(input[i]);
		}
		return ret;
	}
};

#endif

#if 0

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
		{
			return nullptr;
		}
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		int count1 = 0;
		int count2 = 0;
		while (cur1)
		{
			count1++;
			cur1 = cur1->next;
		}
		while (cur2)
		{
			count2++;
			cur2 = cur2->next;
		}
		cur1 = pHead1;
		cur2 = pHead2;
		int count = abs(count1 - count2);
		if (count1 > count2)
		{
			while (count--)
			{
				cur1 = cur1->next;
			}
			while (cur1)
			{
				if (cur1 == cur2)
				{
					return cur1;
				}
				else
				{
					if (cur1)
						cur1 = cur1->next;
					if (cur2)
						cur2 = cur2->next;
				}
			}
			return nullptr;
		}
		else
		{
			while (count--)
			{
				cur2 = cur2->next;
			}
			while (cur2)
			{
				if (cur1 == cur2)
				{
					return cur2;
				}
				else
				{
					if (cur1)
						cur1 = cur1->next;
					if (cur2)
						cur2 = cur2->next;
				}
				return nullptr;
			}
		}
	}
};

#endif
int main()
{
	//test();
	system("pause");
	return 0;
}