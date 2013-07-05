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
    void Add(int add,bool &carry) {
 		ListNode *temp = new ListNode(0);
 		temp->val = (add + carry) % 10;
 		ret->next = temp;
 		carry = add + carry > 9;
 		ret = temp;
 	}
 	ListNode *ret;
 public:
 	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
 		ret = new ListNode(0);
 		ListNode *head = ret;
 		bool carry = false;
 		for ( ; l1 && l2 ; l1 = l1->next , l2 = l2->next) {
 			Add(l1->val + l2->val , carry);
 		}
 		for ( ; l1 ; l1 = l1->next) {
 			Add(l1->val , carry);
 		}
 		for ( ; l2 ; l2 = l2->next) {
 			Add(l2->val , carry);
 		}
 		if (carry) {
 			Add(0 , carry);
 		}
 		return head->next;
 	}
 };