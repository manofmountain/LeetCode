/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//6.45%
struct ListNode* swapPairs(struct ListNode* head) {
    //Check boundary conditions
	if(!head || !head -> next)
		return head;
	
	struct ListNode *prev = head, *curr = head -> next;
	prev -> next = curr -> next;
	curr -> next = prev;
	head = curr;
	//prev = prev -> next;

	while(prev -> next){
		curr = prev -> next;
		if(curr -> next){
			struct ListNode *temp = curr -> next -> next;
			curr -> next -> next = curr;
			prev -> next = curr -> next;
			curr -> next = temp;
			prev = curr;
		}
		else
			break;
	}
	return head;
}

//6.45%
//Recursive way
struct ListNode* swapPairs(struct ListNode* head) {
    //Check boundary conditions
	if(!head || !head -> next)
		return head;
	
	struct ListNode *prev = head, *curr = head -> next;
	prev -> next = swapPairs(curr -> next);
	curr -> next = prev;
	return curr;	
}