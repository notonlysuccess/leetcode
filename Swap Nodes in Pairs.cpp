// new a temp node
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
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *first = temp;
        ListNode *second = temp->next;
        while (second && second->next) {
            first->next = second->next;
            ListNode *third = second->next->next;
            second->next->next = second;
            second->next = third;
            first = second;
            second = second->next;
        }
        return temp->next;
    }
};
// not new temp node
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
        if (head == NULL || head->next == NULL) return head;
        ListNode *first = head->next;
        ListNode *second = first->next;
        head->next = second;
        first->next = head;
        head = first;
        if (second == NULL) return head;
        first = first->next;
        while (second && second->next) {
            first->next = second->next;
            ListNode *third = second->next->next;
            second->next->next = second;
            second->next = third;
            first = second;
            second = second->next;
        }
        return head;
    }
};