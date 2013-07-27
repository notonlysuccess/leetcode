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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *boundary , *prev = dummy;
        for (int i = 1 ; i <= n ; i ++) {
            if (i == m) {
                boundary = prev;
            }
            if (m < i) {
                prev->next = head->next;
                head->next = boundary->next;
                boundary->next = head;
                head = prev;
            }
            prev = head;
            head = head->next;
        }
        return dummy->next;
    }
}; 