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
        if (head == NULL || k == 0) {
            return head;
        }
        int length = 1;
        ListNode *tail = head;
        while (tail->next) {
            length ++;
            tail = tail->next;
        }
        k = length - k%length;
        if (k == 0 || k == length) return head;
        ListNode *first = head;
        while (-- k) {
            first = first->next;
        }
        tail->next = head;
        head = first->next;
        first->next = NULL;
        return head;
    }
};