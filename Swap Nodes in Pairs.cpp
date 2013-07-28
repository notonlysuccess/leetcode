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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        while (first && first->next && first->next->next) {
            ListNode *second = first->next;
            ListNode *third = second->next;
            first->next = third;
            second->next = third->next;
            third->next = second;
            first = second;
        }
        return dummy->next;
    }
};