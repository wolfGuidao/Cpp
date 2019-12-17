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
/*
class Solution {
public:
	vector<int> buf;
	void dfs1(TreeNode *root) {
		if(!root) buf.push_back(0xFFFFFFFF);
		else {
			buf.push_back(root->val);
			dfs1(root->left);
			dfs1(root->right);
		}
	}
	TreeNode* dfs2(int* &p) {
		if(*p==0xFFFFFFFF) {
			p++;
			return NULL;
		}
		TreeNode* res=new TreeNode(*p);
		p++;
		res->left=dfs2(p);
		res->right=dfs2(p);
		return res;
	}
	char* Serialize(TreeNode *root) {
		buf.clear();
		dfs1(root);
		int bufSize=buf.size();
		int *res=new int[bufSize];
		for(int i=0;i<bufSize;i++) res[i]=buf[i];
		return (char*)res;
	}
	TreeNode* Deserialize(char *str) {
		int *p=(int*)str;
		return dfs2(p);
	}
};
*/
class Solution {
public:
	vector<char> buf;
	void dfs1(TreeNode *root)
	{
		if (!root)
		{
			buf.push_back('#');
		}
		else
		{
			buf.push_back(root->val + '0');
			dfs1(root->left);
			dfs1(root->right);
		}
	}
	TreeNode* dfs2(char* &p)
	{
		if (*p == '#')
		{
			p++;
			return NULL;
		}
		TreeNode* res = new TreeNode(*p - '0');
		p++;
		res->left = dfs2(p);
		res->right = dfs2(p);
		return res;
	}
	char* Serialize(TreeNode *root)
	{
		buf.clear();
		dfs1(root);
		int bufSize = buf.size();
		char *res = new char[bufSize];
		int i = 0;
		for (i = 0; i < bufSize; i++)
			res[i] = buf[i];
		res[i] = '\0';
		return res;
	}
	TreeNode* Deserialize(char *str)
	{
		char *p = str;
		return dfs2(p);
	}
};