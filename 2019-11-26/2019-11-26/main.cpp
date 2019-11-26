#include<iostream>
using namespace std;

#if 0
class Solution {
public:
	vector<double>ret;
	void Insert(int num)
	{
		ret.push_back(num);
	}

	double GetMedian()
	{
		sort(ret.begin(), ret.end());

		int count = ret.size();
		if (count < 2)
		{
			return ret[0];
		}
		else if (count == 2)
		{
			return (ret[0] + ret[1]) / 2.0;
		}
		else if (count % 2 == 0)
		{
			return (ret[count / 2.0] + ret[count / 2.0 - 1]) / 2.0;
		}
		else
		{
			return ret[count / 2.0];
		}
	}

};


#endif

#include<vector>
#include <algorithm> 

#if 0

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int>ret;
		vector<int>ret1;

		if (size==0)
		{
			return ret;
		}

		int i = 0;
		int j = 0;
		while ((i +size )<= num.size())
		{
			j++;
			int count = size;
			while (count-- > 0 && i < num.size())
			{
				ret1.push_back(num[i++]);
			}
			i = j;
			sort(ret1.begin(), ret1.end());
			ret.push_back(ret1[ret1.size() - 1]);
			ret1.clear();
		}
		return ret;
	}
};

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>>ret;//层次遍历加上count计数就好了
		vector<int>ret1;
		queue<TreeNode*>q;
		if (pRoot == nullptr)
		{
			return ret;
		}
		q.push(pRoot);
		int count = 0;
		int flag = 1;
		while (!q.empty())
		{
			count = q.size();

			while (count > 0)
			{
				ret1.push_back(q.front()->val);
				TreeNode* cur = q.front();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
				q.pop();
				count--;
			}
			if (flag % 2 == 0)
			{
				reverse(ret1.begin(), ret1.end());
			}
			ret.push_back(ret1);
			flag++;
			ret1.clear();
		}
		return ret;
	}

};

void test()
{
	vector<int>ll;
	vector<int>l = { 2,3,4,2,6,2,5,1 };
	Solution s;
	ll=s.maxInWindows(l, 3);
	for (int i = 0; i < ll.size(); i++)
	{
		cout << ll[i] << " ";
	}
	//cout<<max(66,99);
}

#endif

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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
		{
			return;
		}
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}

	}
};

int main()
{
	//test();
	system("pause");
	return 0;
}