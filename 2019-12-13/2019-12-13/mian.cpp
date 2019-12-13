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
	bool isSubtreechild(TreeNode* s, TreeNode* t)
	{//判断两课树的值和结构是否相等
		if (t == nullptr&&s == nullptr)//只有同时为空才返回true，表明同时为空时，不仅每个对应节点值相等，并且结构一致
		{
			return true;
		}
		if (s == nullptr)
		{
			return false;
		}
		if (t == nullptr)
		{
			return false;
		}
		if (s->val != t->val)
		{
			return false;

		}
		else
		{//递归判断
			return isSubtreechild(s->left, t->left) && isSubtreechild(s->right, t->right);
		}
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		//注意这道题不仅要节点的值相等，并且还要结构相同才返回true
		if (s == nullptr)
		{
			return false;
		}
		if (t == nullptr)
		{
			return false;
		}
		//如果isSubtreechild返回true说明找到匹配的子串直接返回，反之在s中递归遍历看能否找到
		if (isSubtreechild(s, t))
		{
			return true;
		}
		else
		{
			return isSubtree(s->right, t) || isSubtree(s->left, t);
		}
	}
};