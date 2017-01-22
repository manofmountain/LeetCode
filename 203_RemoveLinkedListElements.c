/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//27.45%
struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head && head -> val == val)
		head = head -> next;
	struct ListNode *pre = head;
	while(pre){
		while(pre -> next && pre -> next -> val == val){
			pre -> next = pre -> next -> next;
		}
		pre = pre -> next;
	}
	return head;
}