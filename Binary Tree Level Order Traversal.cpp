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
    void traversal(vector<vector<int> >&ret , TreeNode *root , int deep) {
        if (root == NULL) {
            return ;
        }
        if (deep == ret.size()) {
            ret.push_back(vector<int>(1 , root->val));
        } else {
            ret[deep].push_back(root->val);
        }
        traversal(ret , root->left , deep + 1);
        traversal(ret , root->right , deep + 1);
    }
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        traversal(ret , root , 0);
        return ret;
    }
};