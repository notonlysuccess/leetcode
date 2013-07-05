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
    void dfs(TreeNode *root,int sum , vector<vector<int> > &ret , vector<int> &temp) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                temp.push_back(root->val);
                ret.push_back(temp);
                temp.pop_back();
            }
        }
        if (root->left) {
            temp.push_back(root->val);
            dfs(root->left , sum - root->val , ret , temp);
            temp.pop_back();
        }
        if (root->right) {
            temp.push_back(root->val);
            dfs(root->right , sum - root->val , ret , temp);
            temp.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if (root == NULL) return ret;
        vector<int> temp;
        dfs(root, sum , ret , temp);
        return ret;
    }
};