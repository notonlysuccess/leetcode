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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return head;
        }
        ListNode *last = head;
        int length = 1;
        for (; last->next ; last = last->next, length ++);
        k = length - k%length;
        if (k == 0 || k == length) {
            return head;
        }
        ListNode *first = head;
        for ( ; -- k ; first = first->next);
        ListNode *ret = first->next;
        first->next = NULL;
        last->next = head;
        return ret;
    }
};