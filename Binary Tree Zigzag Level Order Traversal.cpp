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
    void traversal(TreeNode *root , vector<vector<int> > &ret , int deep) {
        if (!root) {
            return ;
        }
        if (deep == ret.size()) {
            ret.push_back(vector<int>());
        }
        if (deep & 1) {
            ret[deep].insert(ret[deep].begin() , root->val);
        } else {
            ret[deep].push_back(root->val);
        }
        traversal(root->left , ret , deep + 1);
        traversal(root->right , ret , deep + 1);
    }
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        traversal(root , ret , 0);
        return ret;
    }
};