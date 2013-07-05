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
    vector<TreeNode *> gen(int l,int r) {
        vector<TreeNode *>ret;
        if (l > r) {
            ret.push_back(NULL);
            return ret;
        }
        for (int m = l ; m <= r ; m ++) {
            vector<TreeNode *> left = gen(l , m - 1);
            vector<TreeNode *> right = gen(m + 1 , r);
            for (int i = 0 ; i < left.size() ; i ++) {
                for (int j = 0 ; j < right.size() ; j ++) {
                    TreeNode *root = new TreeNode(m);
                    root->left = left[i];
                    root->right = right[j];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return gen(1 , n);
    }
};