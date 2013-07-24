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
    TreeNode *build(vector<int> &num,int lo,int hi) {
        if (lo > hi) {
            return NULL;
        }
        int mid = (lo + hi) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = build(num,lo,mid-1);
        root->right = build(num,mid+1,hi);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num , 0 , num.size() - 1);
    }
};