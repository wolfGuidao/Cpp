#include<iostream>
using namespace std;



/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{

		if (pRoot1 == nullptr)//如果传参时pRoot1或者pRoot2为空直接返回false
		{
			return false;
		}
		if (pRoot2 == nullptr)
		{
			return false;
		}
		if (dfs(pRoot1, pRoot2))//dfs（pRoot1，pRoot2）是调用dfs函数判断当前两个节
			//点是不是相等的，如果是相等的，就在dfs中进行判断是不是所有的节点都相等，
			//如果dfs返回true，说明从当前节点开始，满足题意，就返回true
			return true;
		else//否则就是当前节点不想等，就递归判断pRoot1的左子树和右子树，在左右子树中进行比较，看
			//能否找到满足题意的子树结构
			return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

	}
	bool dfs(TreeNode* pRoot1, TreeNode* pRoot2)//该函数是判断从pRoot1和pRoot2
		//开始，如果pRoot1和pRoot2相等就递归判断pRoot2的左子树和右子树，否则就直接返回false

	{
		//pRoot1为二叉树A，pRot2为二叉树B，所以判断pRoot2是不是pRoot1的子结构
		if (pRoot2 == nullptr)//如果pRoot2为空说明pRoot2从头节点开始就一直相等，直至走到空
			//，所以直接返回true，！！！！注意??pRoot2==nullptr这个判断条件必须在
			//pRoot1==nullptr这个条件之前，因为可能会同时为空，会导致出错
		{
			return true;
		}
		if (pRoot1 == nullptr)//表示pRoot1先一步为空，pRoot2还没有为空，就返回false
		{
			return false;
		}
		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}
		else
		{
			//递归判断
			return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
		}
	}
	
	if(!pRoot1)
		return false;
	if(!pRoot2)
		return false;
	return ( dfs(pRoot1,pRoot2)) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

bool dfs(TreeNode * pRoot1, TreeNode * pRoot2){
	if(!pRoot2)
		return true;
	if(!pRoot1)
		return false;
	if(pRoot1->val != pRoot2->val)
		return false;
	return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
}

};
*/


int main()
{
	short f = 0xb600;
	if (f == 0xb600)
	{
		cout << "wolf" << endl;

	}
	else
	{
		cout << "guidao" << endl;
	}
	system("pause");
	return 0;
}