/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        for ( ; l1 || l2 || carry ; ) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            carry = sum > 9;
            ListNode *node = new ListNode(sum%10);
            tail->next = node;
            tail = node;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;;
        }
        return head->next;
    }
};