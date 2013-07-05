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
    void dfs(TreeNode *root,TreeNode *&a,TreeNode *&b , TreeNode *&pre) {
        if (root == NULL) return ;
        dfs(root->left , a , b , pre);
        if (pre && pre->val > root->val) {
            a = root;
            if (!b) {
                b = pre;
            }
        }
        pre = root;
        dfs(root->right , a , b , pre);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *a = NULL , *b = NULL , *p = NULL;
        dfs(root , a , b , p);
        swap(a->val , b->val);
    }
};