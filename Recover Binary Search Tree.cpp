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
    void dfs(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        if (root == NULL) {
            return ;
        }
        dfs(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        dfs(root->right, prev, first, second);
    }
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        dfs(root, prev, first, second);
        swap(first->val , second->val);
    }
};