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
	TreeNode *buildTree(vector<int> &inorder,int li,int ri,vector<int> &postorder,int lp,int rp) {
		if (li > ri) return NULL;
		int val = postorder[rp];
		int index = li;
		for (; inorder[index] != val ; index ++);
		TreeNode *root = new TreeNode(val);
		root->left = buildTree(inorder , li , index - 1 , postorder , lp , lp + index - li - 1);
		root->right = buildTree(inorder , index + 1 , ri , postorder , lp + index - li , rp - 1);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size() - 1);
	}
};