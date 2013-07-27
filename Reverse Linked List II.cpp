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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (n == m) {
            return head;
        }
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *boundary = ret;
        int i = 1 ;
        for ( ; i < m ; i ++ , boundary = boundary->next);
        ListNode *prev = boundary->next;
        ListNode *cur = prev->next;
        ListNode *next = cur->next;
        for ( ; i < n ; i ++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        boundary->next->next = cur;
        boundary->next = prev;
        return ret->next;
    }
};