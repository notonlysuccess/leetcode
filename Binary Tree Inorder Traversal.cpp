/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root , vector<int> &ret) {
		if (root == NULL) return ;
		dfs(root->left , ret);
		ret.push_back(root->val);
		dfs(root->right , ret);
	}
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> ret;
		dfs(root , ret);
		return ret;
	}
};