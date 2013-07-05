/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *build(ListNode *&head,int l) {
    	if (l == 0) return NULL;
		TreeNode *root = new TreeNode(0);
		root->left = build(head , l>>1);
		root->val = head->val;
		head = head->next;
		root->right = build(head , l - 1 - (l>>1));
		return root;
	}
	int getLength(ListNode *head) {
		int ret = 0;
		for (; head ; head = head->next , ret ++);
		return ret;
	}
	TreeNode *sortedListToBST(ListNode *head) {
		return build(head , getLength(head));
	}
};