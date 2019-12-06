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
	bool isSymmetricalChild(TreeNode* pRoot1, TreeNode* pRoot2)
	{//只有两个子树同时为空时，才为真，其他情况都是假
		if (pRoot1 == nullptr&&pRoot2 != nullptr)
		{
			return false;
		}
		else if (pRoot1 != nullptr&&pRoot2 == nullptr)
		{
			return false;
		}
		else if (pRoot1 == pRoot2 && pRoot2 == nullptr)
		{
			return true;
		}

		if (pRoot1->val != pRoot2->val)//如果两个根结点的值不想等，直接返回false
		{
			return false;
		}
		else//递归判断对称位置的子树，因为对称子树每次判断不在同一个节点下面
		{
			return isSymmetricalChild(pRoot1->left, pRoot2->right) &&
				isSymmetricalChild(pRoot1->right, pRoot2->left);
		}

	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetricalChild(pRoot, pRoot);
	}

};