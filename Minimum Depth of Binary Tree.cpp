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
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (root->left && root->right) {
            return min(left , right) + 1;
        } else {
            return max(left , right) + 1;
        }
    }
};