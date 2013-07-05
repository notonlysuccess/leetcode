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
        ListNode *first = head;
        ListNode *last = head;
        ListNode *pre = head;
        while (first) {
            int i = 1;
            for (; i < k && last->next ; i ++) {
                last = last->next;
            }
            if (i < k) {
                break;
            }
            if (first == head) {
                head = last;
            } else {
                pre->next = last;
            }
            pre = first;
            ListNode *second = first->next;
            ListNode *next = last->next;
            first->next = next;
            while (first != last) {
                ListNode *third = second->next;
                second->next = first;
                first = second;
                second = third;
            }
            first = last = next;
        }
        return head;
    }
};