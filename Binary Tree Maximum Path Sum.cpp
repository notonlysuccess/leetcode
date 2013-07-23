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
    int maxPathSum(TreeNode *root,int &maxPath) {
        if (root == NULL) {
            maxPath = 0;
            return INT_MIN;
        }
        int left , right;
        int leftsum = maxPathSum(root->left , left);
        int rightsum = maxPathSum(root->right , right);
        maxPath = root->val + max(0 , max(left , right));
        return max(max(leftsum , rightsum) , root->val + max(0,left) + max(0,right));
    }
public:
    int maxPathSum(TreeNode *root) {
        int maxPath;
        return maxPathSum(root , maxPath);
    }
};