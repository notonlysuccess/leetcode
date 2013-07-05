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
    bool dfs(TreeNode *root , int sum) {
        if (root->left == NULL && root->right == NULL) {
            return sum == root->val;
        }
        if (root->left && dfs(root->left , sum - root->val)) return true;
        if (root->right && dfs(root->right , sum - root->val)) return true;
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return dfs(root , sum);
    }
};