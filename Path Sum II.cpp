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
    vector<vector<int> > ret;
    vector<int> path;
    void dfs(TreeNode *root ,int sum) {
        if (!root) {
            return ;
        }
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                ret.push_back(path);
            }
        }
        dfs(root->left , sum - root->val);
        dfs(root->right , sum - root->val);
        path.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ret.clear();
        path.clear();
        dfs(root , sum);
        return ret;
    }
};