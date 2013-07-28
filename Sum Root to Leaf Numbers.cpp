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
    int add(int num,TreeNode *root) {
        if (!root) {
            return 0;
        }
        num = num*10 + root->val;
        if (!root->left && !root->right) {
            return num;
        }
        return add(num,root->left) + add(num,root->right);
    }
public:
    int sumNumbers(TreeNode *root) {
        return add(0 , root);
    }
};