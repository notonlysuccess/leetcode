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
    class mycmp {
    public:
        bool operator()(const ListNode *a,const ListNode *b) const {
            return a->val > b->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        priority_queue<ListNode* , vector<ListNode*> , mycmp> Q;
        for (int i = 0 ; i < lists.size() ; i ++) {
            if (lists[i] != NULL) {
                Q.push(lists[i]);
            }
        }
        while (!Q.empty()) {
            ListNode *least = Q.top();
            Q.pop();
            tail->next = least;
            tail = least;
            if (least->next != NULL) {
                Q.push(least->next);
            }
        }
        return head->next;
    }
};