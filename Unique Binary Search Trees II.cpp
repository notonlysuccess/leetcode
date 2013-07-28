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
    void dfs(vector<TreeNode *> &ret, int lo, int hi) {
        if (lo > hi) {
            ret.push_back(NULL);
        }
        for (int mid = lo ; mid <= hi ; mid ++) {
            vector<TreeNode *> left , right;
            dfs(left , lo , mid - 1);
            dfs(right , mid + 1, hi);
            for (int i = 0 ; i < left.size() ; i ++) {
                for (int j = 0 ; j < right.size() ; j ++) {
                    TreeNode *root = new TreeNode(mid);
                    root->left = left[i];
                    root->right = right[j];
                    ret.push_back(root);
                }
            }
        }
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ret;
        dfs(ret , 1 , n);
        return ret;
    }
};