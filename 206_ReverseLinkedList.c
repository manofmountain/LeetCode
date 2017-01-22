/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//69.89%
struct ListNode* reverseList(struct ListNode* head) {
	if(!head || !head -> next)
		return head;
    struct ListNode *pre = head, *curr = head -> next;
	pre -> next = NULL;
	struct ListNode *after = curr -> next;
	curr -> next = pre;
	pre = curr;
	curr = after;
	while(curr){
		after = curr -> next;
		curr -> next = pre;
		pre = curr;
		curr = after;
	}
	return pre;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//2.69%
struct ListNode *reverseListHelper(struct ListNode **head){
	if(!((*head) -> next))
		return *head;
	struct ListNode *res = reverseListHelper(&((*head) -> next));
	(*head) -> next -> next = (*head);
	return res;
}
struct ListNode* reverseList(struct ListNode* head) {
	if(!head || !head -> next)
		return head;
	struct ListNode *res = reverseListHelper(&(head -> next));
	head -> next -> next = head;
	head -> next = NULL;
	return res;
}
