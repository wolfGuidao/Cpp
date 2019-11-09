#include<iostream>
using namespace std;

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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* cur = pListHead;
		int count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		cur = pListHead;
		int i = count - k;
		if (k > count)
		{
			return nullptr;
		}
		else
		{
			while (i > 0)
			{
				cur = cur->next;
				i--;
			}
		}
		return cur;
	}
};

#endif

//

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}
		if (l1 == nullptr&&l2 == nullptr)
		{
			return nullptr;
		}
		// ListNode* head;
		// head->next=l1;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		ListNode* temp1 = cur1;//
		ListNode* temp2 = cur2->next;
		while (cur1&&cur2)
		{
			if (cur2->val < cur1->val)
			{
				if (temp1 == cur1)
				{
					temp2 = cur2->next;
					cur2->next = cur1;
					l1 = cur2;
					temp1 = cur2;
					cur2 = temp2;
					continue;
				}
				temp2 = cur2->next;
				temp1->next = cur2;
				cur2->next = cur1;
				cur2 = temp2;
			}
			else
			{
				temp1 = cur1;
				cur1 = temp1->next;
			}
		}
		if (cur1 == nullptr)
		{
			temp1->next = cur2;
		}
		return l1;
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
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		//return max(1+maxDepth(root->right),1+maxDepth(root->left))+1;
		int num1 = 1 + maxDepth(root->left);
		int num2 = 1 + maxDepth(root->right);
		return num1 > num2 ? num1 : num2;
	}
};

#endif
int main()
{
	//cout << nullptr;
	system("pause");
	return 0;
}