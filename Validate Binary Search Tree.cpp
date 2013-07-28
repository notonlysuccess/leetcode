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
    bool dfs(TreeNode *root,int lo,int hi) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= lo || hi <= root->val) {
            return false;
        }
        return dfs(root->left , lo , root->val) && dfs(root->right , root->val , hi);
    }
public:
    bool isValidBST(TreeNode *root) {
        return dfs(root , INT_MIN , INT_MAX);
    }
};