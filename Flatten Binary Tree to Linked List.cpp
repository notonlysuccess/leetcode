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
	TreeNode *rebuild(TreeNode *root,TreeNode *father) {
		if (root == NULL) return father;
		if (father != NULL) father->right = root;
		TreeNode *left = root->left;
		TreeNode *right = root->right;
		root->left = NULL;
		root->right = NULL;
		TreeNode *last = rebuild(left , root);
		return rebuild(right , last);
	}
	void flatten(TreeNode *root) {
		rebuild(root , NULL);
	}
};