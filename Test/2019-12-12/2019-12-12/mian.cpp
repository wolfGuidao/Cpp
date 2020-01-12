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
	bool isSymmetricchild(TreeNode* root1, TreeNode* root2)
	{//另外定义一个函数，用来递归判断
		if (root1 == root2 && root2 == nullptr)//如果子树的两边同时走到空才说明整棵树都判断完成，
		{
			return true;
		}
		if (root1 == nullptr || root2 == nullptr)//其中一个为空，说明某个子树先一步到达空，直接返回false
		{
			return false;
		}
		if (root1->val == root2->val)//递归
		{
			return isSymmetricchild(root1->left, root2->right) && isSymmetricchild(root1->right, root2->left);
		}
		else
		{
			return false;
		}
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}
		return isSymmetricchild(root, root);
	}
};

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
	//求二叉树深度
	int getlength(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max((1 + getlength(root->left)), (1 + getlength(root->right)));//?(1+getlength(root->left)):(1+getlength(root->right));

	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}//递归判断
		if (abs(getlength(root->left) - getlength(root->right)) <= 1)
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
		else
		{
			return false;
		}
	}
};