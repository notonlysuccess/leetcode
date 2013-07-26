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
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (l1 || l2) {
            if (!l1 || (l2 && l1->val > l2->val)) {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            } else {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
        }
        return head->next;
    }
};