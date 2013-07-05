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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *ret;
        if (l1->val < l2->val) {
            ret = l1;
            l1 = l1->next;
        } else {
            ret = l2;
            l2 = l2->next;
        }
        ListNode *last = ret;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
                last = last->next;
            } else {
                last->next = l2;
                l2 = l2->next;
                last = last->next;
            }
        }
        if (l1) last->next = l1;
        else last->next = l2;
        return ret;
    }
};