class Solution {
public:
	int Gethight(TreeNode* pRoot)
	{
		//求某个二叉树的深度
		if (pRoot == nullptr)
		{
			return 0;
		}
		return max(1 + Gethight(pRoot->right), 1 + Gethight(pRoot->left));


	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr)
		{
			return true;
		}
		//如果出现左子树和右子树的深度插大于1，就直接返回false
		//反之递归该根结点的左右子树，判断是否都满足情况，直到左右孩子为空
		if (abs(Gethight(pRoot->left) - Gethight(pRoot->right)) <= 1)
		{
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

		}
		else
		{
			return false;
		}
	}
};