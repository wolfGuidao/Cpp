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
	vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>>ret;
		vector<int>temp;
		if(root==nullptr)
		{
			return ret;
		}
		temp.push_back(root->val);
		if((expectNumber-root->val)==0&&root->left==nullptr&&root->right==nullptr)
		{
			ret.push_back(temp);
		}
		if(root->left)
		{
			FindPath(root->left,expectNumber-root->val);
		}
		if(root->right)
		{
			FindPath(root->right,expectNumber-root->val);

		}
		if(temp.size()!=0)
		{
			temp.pop_back();
		}
		return ret;
	}
};
*/
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
	vector<vector<int> > buffer;//保存最后的结果
	vector<int> tmp;//临时存储
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return buffer;
		tmp.push_back(root->val);//把根结点的值放到temp中
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL)
		{
			buffer.push_back(tmp);//如果满足该节点是叶子节点，并且最后expecNumber减掉
			//当前节点的val后为0，说明注意路径满足题意，直接放到buffer中
		}
		if (root->left)//递归左边，注意此时只需在子树中找和expectNumber-root->val即可
			FindPath(root->left, expectNumber - root->val);
		if (root->right)//递归右边
			FindPath(root->right, expectNumber - root->val);
		if (tmp.size() != 0)//如果递归找到叶子节点但发现(expectNumber-root->val)！=0，
			//说明这一路径不满足题意，返回其父亲节点，继续递归，并把temp中最后一个元素删掉
			tmp.pop_back();
		return buffer;
	}
};