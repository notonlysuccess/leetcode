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
    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }
        return dfs(left->right, right->left) && dfs(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return dfs(root->left, root->right);
    }
};