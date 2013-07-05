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
	bool ret;
	int dfs(TreeNode *root) {
		if (root == NULL) return 0;
		int left = dfs(root->left);
		int right = dfs(root->right);
		if (abs(left - right) > 1) {
			ret = false;
		}
		return max(left , right) + 1;
	}
public:
    bool isBalanced(TreeNode *root) {
        ret = true;
        dfs(root);
        return ret;
    }
};