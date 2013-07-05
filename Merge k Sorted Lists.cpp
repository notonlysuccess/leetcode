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
    class comp {
    public:
        bool operator()(const ListNode *l,const ListNode *r) const {
            return l->val > r->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode* , vector<ListNode*> , comp> que;
        ListNode *ret = new ListNode(0);
        ListNode *tail = ret;
        for (int i = 0 ; i < lists.size() ; i ++) {
            if (lists[i]) que.push(lists[i]);
        }
        while (!que.empty()) {
            ListNode *u = que.top();
            que.pop();
            ListNode *v = u->next;
            tail->next = u;
            u->next = NULL;
            tail = u;
            if (v) que.push(v);
        }
        return ret->next;
    }
};
