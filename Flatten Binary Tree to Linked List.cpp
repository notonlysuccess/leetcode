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
    void build(TreeNode *root , TreeNode *&last) {
        if (root == NULL) {
            return ;
        }
        last = root;
        if (root->left) {
            build(root->left , last);
            last->right = root->right;
        }
        build(root->right , last);
        if (root->left) {
            root->right = root->left;
            root->left = NULL;
        }
    }
public:
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        build(root , last);
    }
};