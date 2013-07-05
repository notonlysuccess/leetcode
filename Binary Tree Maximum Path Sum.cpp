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
    int dfs(TreeNode *root , int &longest) {
		if (root == NULL) return 0;
		int left = 0 , right = 0;
		int ret = root->val;
		if (root->left) ret = max(ret , dfs(root->left , left));
		if (root->right) ret = max(ret , dfs(root->right , right));
		left = max(left , 0);
		right = max(right , 0);
		longest = root->val + max(left , right);
		return max(ret , left + right + root->val);
	}
	int maxPathSum(TreeNode *root) {
		int longest = 0;
		return dfs(root , longest);
	}
};