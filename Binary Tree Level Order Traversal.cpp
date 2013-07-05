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
	void dfs(TreeNode *root , vector<vector<int> > &ret , int deep) {
		if (root == NULL) return ;
		if (ret.size() == deep) ret.push_back(vector<int>());
		ret[deep].push_back(root->val);
		dfs(root->left , ret , deep + 1);
		dfs(root->right , ret , deep + 1);
	}
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		dfs(root , ret , 0);
		return ret;
	}
};