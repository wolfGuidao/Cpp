#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)//如果当前根结点为空或者找到p，q节点，就返回该节点
		{
			return root;
		}
		TreeNode* left = lowestCommonAncestor(root->left, p, q);//递归当前根结点的左子树
		TreeNode* right = lowestCommonAncestor(root->right, p, q);//递归右子树
		if (left&&right)//如果两边都不为空，说明p和q在当前根结点的两侧，直接返回根结点
		{
			return root;
		}
		return left ? left : right;
	}
};

#endif

#if 0

class Solution {
public:
	bool isValid(string s) {
		stack<char>ss;
		char topp1;
		char topp2;
		if (s.size() % 2 != 0)
		{
			return false;
		}
		for (auto i = 0;i < s.size();i++)
		{
			if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			{
				ss.push(s[i]);
			}
			else
			{
				if (!ss.empty())
				{
					topp1 = ss.top();
					ss.pop();
					switch (topp1)
					{
					case'{':
						topp2 = '}';
						break;
					case'(':
						topp2 = ')';
						break;
					case'[':
						topp2 = ']';
						break;
					}
					if (s[i] != topp2)
					{
						return false;
					}
				}
			}
		}
		if (ss.empty() == true)
			return true;
		else
			return false;
	}
};

#endif

#if 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr)
		{
			return head;
		}
		ListNode* cur = head;//判断当前节点
		ListNode* temp = cur;//指向当前节点的前一个节点
		while (cur)
		{
			if (cur->val == val)
			{
				if (cur == head)//要删除位置在头
				{
					head = cur->next;
					cur = head;
					if (head == nullptr)//如果删完后链表变为空，就直接返回
					{
						return head;
					}
					else
					{
						continue;//continue防止跳过一个节点
					}
				}
				else if (cur->next == nullptr)//如果要删除的位置在结尾
				{
					temp->next = nullptr;
					return head;
				}
				else//要删除的节点在中间
				{
					temp->next = cur->next;
					cur = temp->next;
					continue;//如果没有continue，就会跳过一个节点
				}
			}
			temp = cur;
			cur = cur->next;
		}
		return head;
	}
};

#endif
int main()
{
	cout << sizeof(nullptr)<<endl;
	cout << sizeof(NULL) << endl;
	cout << NULL;
	system("pause");
	return 0;
}