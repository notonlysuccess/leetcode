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
    bool dfs(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        return dfs(root->left , sum - root->val) || dfs(root->right , sum - root->val);
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root , sum);
    }
};