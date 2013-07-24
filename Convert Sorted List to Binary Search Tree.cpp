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
private:
    int getLength(ListNode *head) {
        return head == NULL ? 0 : 1 + getLength(head->next);
    }
    TreeNode *build(ListNode *&head, int length) {
        if (length == 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(0);
        root->left = build(head , length/2);
        root->val = head->val;
        head = head->next;
        root->right = build(head , length - 1 - length/2);
        return root;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head , getLength(head));
    }
};