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
	void dfs(TreeNode *root , vector<vector<int> > &ret , int level) {
		if (root == NULL) return ;
		if (level == ret.size()) ret.push_back(vector<int>());
		ret[level].push_back(root->val);
		dfs(root->left , ret , level + 1);
		dfs(root->right, ret , level + 1);
	}
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		dfs(root , ret , 0);
		for (int i = 0 ; i < ret.size() ; i ++) {
			if (i & 1) {
				for (int a = 0 , b = ret[i].size() - 1 ; a < b ; a ++ , b --) {
					swap(ret[i][a] , ret[i][b]);
				}
			}
		}
		return ret;
	}
};