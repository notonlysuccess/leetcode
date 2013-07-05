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
    void dfs(TreeNode *root,int val,int &ans) {
		if (root->left == NULL && root->right == NULL) {
			ans += val * 10 + root->val;
		}
		if (root->left) {
			dfs(root->left , val * 10 + root->val , ans);
		}
		if (root->right) {
			dfs(root->right , val * 10 + root->val , ans);
		}
	}
public:
    int sumNumbers(TreeNode *root) {
    	if (root == NULL) {
    		return 0;
    	}
        int ans = 0;
        dfs(root , 0 , ans);
        return ans;
    }
};