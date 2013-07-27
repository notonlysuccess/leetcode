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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *last = head;
        for (ListNode *p = head->next ; p ; p = p->next) {
            if (p->val == last->val) {
                last->next = p->next;
            } else {
                last = p;
            }
        }
        return head;
    }
};