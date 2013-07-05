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
        ListNode *less, *greater;
        ListNode *startLess = NULL, *startGreater = NULL;
        while (head) {
            if (head->val < x) {
                if (startLess == NULL) {
                    startLess = head;
                    less = startLess;
                } else {
                    less->next = head;
                    less = head;
                }
            } else {
                if (startGreater == NULL) {
                    startGreater = head;
                    greater = startGreater;
                } else {
                    greater->next = head;
                    greater = head;
                }
            }
            head = head->next;
        }
        if (startLess == NULL) {
            return startGreater;
        } else if (startGreater == NULL) {
            return startLess;
        }
        less->next = startGreater;
        greater->next = NULL;
        return startLess;
    }
};