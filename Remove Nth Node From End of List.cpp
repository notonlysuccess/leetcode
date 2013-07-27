/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int remove(ListNode *&head, int n) {
        if (head == NULL) {
            return NULL;
        }
        int m = remove(head->next , n) + 1;
        if (n == m) {
            head = head->next;
        }
        return m;
    }
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        remove(head , n);
        return head;
    }
}; 