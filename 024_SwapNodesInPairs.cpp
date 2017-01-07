/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//11.16%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *prev, *curr;
		while((prev = *pp) && (curr = prev -> next)){
			prev -> next = curr -> next;
			curr -> next = prev;
			*pp = curr;
			pp = &(prev -> next);
		}
		return head;
    }
};