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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = new ListNode(0);
        ListNode *pre = head , *cur = head , *last = ret;
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (pre == cur) {
                last->next = cur;
                last = cur;
            }
            pre = cur->next;
            cur = cur->next;
        }
        last->next = NULL;
        return ret->next;
    }
};