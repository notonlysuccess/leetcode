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
        if (root == NULL) return 0;
        int ret = 0x7fffffff;
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        if (root->left) {
            ret = min(ret , minDepth(root->left));
        }
        if (root->right) {
            ret = min(ret , minDepth(root->right));
        }
        return ret + 1;
    }
};