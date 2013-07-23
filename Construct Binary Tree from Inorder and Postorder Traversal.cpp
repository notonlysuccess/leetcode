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
    TreeNode *build(vector<int> &inorder,int si,int ei,vector<int> &postorder,int sp,int ep) {
        if (si > ei) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[ep]);
        for (int i = si ; i <= ei ; i ++) {
            if (inorder[i] == postorder[ep]) {
                root->left = build(inorder,si,i-1,postorder,sp,sp+i-1-si);
                root->right = build(inorder,i+1,ei,postorder,sp+i-si,ep-1);
                return root;
            }
        }
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,0,inorder.size() - 1,postorder,0,postorder.size()-1);
    }
};