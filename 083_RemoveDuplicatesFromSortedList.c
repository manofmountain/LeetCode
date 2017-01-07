/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//20.63%
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head || !head -> next)
		return head;
	int val = head -> val;
	struct ListNode *ptr = head;
	while(ptr){
		struct ListNode *curr = ptr;
		while(ptr -> next && ptr -> next -> val == val)
			ptr = ptr -> next;
		if(ptr -> next){
			curr -> next = ptr -> next;
			ptr = ptr -> next;
			val = ptr -> val;
		}else{
			curr -> next = NULL;
			break;
		}
	}
	return head;	
}