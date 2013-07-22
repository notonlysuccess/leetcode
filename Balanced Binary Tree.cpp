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
    int check(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = check(root->left);
        int right = check(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left , right) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        return check(root) != -1;
    }
};