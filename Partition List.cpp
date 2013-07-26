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
    ListNode *partition(ListNode *head, int x) {
        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);
        ListNode *t1 = h1 , *t2 = h2;
        for ( ; head ; head = head->next) {
            if (head->val < x) {
                t1->next = head;
                t1 = head;
            } else {
                t2->next = head;
                t2 = head;
            }
        }
        t1->next = h2->next;
        t2->next = NULL;
        return h1->next;
    }
};