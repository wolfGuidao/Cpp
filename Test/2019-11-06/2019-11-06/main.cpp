#include<iostream>
#include<Windows.h>
using namespace std;

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*>s;
		vector<int>s1;
		TreeNode* cur = root;
		TreeNode* top1;//记录栈定元素
		while (!s.empty() || cur)
		{
			while (cur)//如果左子树存在，用cur标记，把所有的左孩子入栈
			{
				s1.push_back(cur->val);//把根结点的值放到vector<int>s1中
				s.push(cur);//把根结点入栈
				cur = cur->left;//寻找当前根结点的左孩子
			}
			top1 = s.top();//拿到最后一个左孩子用top1标记
			s.pop();//因为最后一个左孩子在上一个循环内已经打印了，所以把栈顶元素直接出栈
			cur = top1->right;//进行找右孩子
		}
		return s1;
	}
};

#endif

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>ret;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		TreeNode* topp;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			topp = s.top();
			s.pop();
			ret.push_back(topp->val);
			cur = topp->right;
		}
		return ret;
	}
};

#endif

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*>s;
		vector<int>ret;
		TreeNode* cur = root;
		TreeNode* top1;//记录栈定元素
		TreeNode* top2 = nullptr;//用来标记是否已经放到ret中
		while (cur || !s.empty())
		{
			while (cur)//循环一直把左孩子入栈
			{
				s.push(cur);
				cur = cur->left;
			}
			top1 = s.top();//当没有左孩子时，用top1取栈顶元素
			if (top1->right == nullptr || top1->right == top2)//只有当该节点的右孩子为空或右孩子被top2标记，才能把当前根结点放到ret中
			{
				ret.push_back(top1->val);
				s.pop();
				top2 = top1;//用top2记录top1节点已经放到ret中
				top1 = nullptr;//没必要，但最好加上，防止内存泄漏问题
			}
			else
			{
				cur = top1->right;
			}
		}
		return ret;

	}
};
#endif


int main()
{
	system("pause");
	return 0;
}