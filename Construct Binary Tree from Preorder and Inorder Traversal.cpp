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
	TreeNode *build(vector<int> &preorder , int lp,int rp,vector<int> &inorder , int li,int ri) {
		if (lp > rp) return NULL;
		int val = preorder[lp];
		int index = li;
		for ( ; inorder[index] != val ; index ++);
		TreeNode *root = new TreeNode(val);
		root->left = build(preorder , lp + 1 , lp + index - li ,inorder , li , index - 1);
		root->right = build(preorder , lp + index - li + 1 , rp , inorder , index + 1 , ri);
		return root;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return build(preorder , 0 , preorder.size() - 1 , inorder , 0 , inorder.size() - 1);
	}
};