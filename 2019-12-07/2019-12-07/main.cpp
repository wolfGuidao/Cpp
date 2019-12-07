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
	int v;
	bool isUnivalTree(TreeNode* root) {
		v = root->val;
		bool s = helper(root);
		return s;
	}
	//


	bool helper(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		if (root->val != v) {
			return false;
		}
		return helper(root->left) && helper(root->right);
	}


};