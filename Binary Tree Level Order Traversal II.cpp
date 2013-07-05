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
private:
    void dfs(TreeNode *root , vector<vector<int> > &ret , int level) {
		if (root == NULL) return ;
		ret[level].push_back(root->val);
		dfs(root->left , ret , level - 1);
		dfs(root->right , ret , level - 1);
	}
	int getMaxLevel(TreeNode *root) {
		if (root == NULL) return 0;
		return max(getMaxLevel(root->left) , getMaxLevel(root->right)) + 1;
	}
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int>> ret;
		int maxLevel = getMaxLevel(root);
		ret.resize(maxLevel);
		dfs(root , ret , maxLevel - 1);
		return ret;
	}
};