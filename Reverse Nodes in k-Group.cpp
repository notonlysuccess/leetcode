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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);
        ListNode *start = dummy;
        dummy->next = head;
        while (true) {
            int l = -1;
            for (ListNode *p = start ; p && l < k ; p = p->next , l ++);
            if (l < k) {
                break;
            }
            ListNode *cur = start->next;
            ListNode *next = cur->next;
            while (-- l) {
                cur->next = next->next;
                next->next = start->next;
                start->next = next;
                next = cur->next;
            }
            start = cur;
        }
        return dummy->next;
    }
};