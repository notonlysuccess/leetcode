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
    TreeNode *build(vector<int> &preorder,int sp,int ep,vector<int> &inorder,int si,int ei) {
        if (sp > ep) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[sp]);
        for (int i = si ; i <= ei ; i ++) {
            if (inorder[i] == preorder[sp]) {
                root->left = build(preorder, sp + 1, sp + i - si, inorder, si, i - 1);
                root->right = build(preorder, sp + i - si + 1, ep, inorder, i + 1, ei);
                return root;
            }
        }
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};