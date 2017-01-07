/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//20.8%
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //Check boundary conditions
	if(!l1)
		return l2;
	if(!l2)
		return l1;
	
	struct ListNode *ptr1 = l1, *ptr2 = l2;
	struct ListNode *rst = NULL, *head = NULL;
	
	//Define first node from where
	if(ptr1 -> val < ptr2 -> val){
		rst = ptr1;
		ptr1 = ptr1 -> next;
	}
	else{
		rst = ptr2;
		ptr2 = ptr2 -> next;
	}
	head = rst;
	//FIrst round circulation	
	while(ptr1 && ptr2){
		if(ptr1 -> val < ptr2 -> val){
			rst -> next = ptr1;
			ptr1 = ptr1 -> next;
		}
		else{
			rst -> next = ptr2;
			ptr2 = ptr2 -> next;
		}
		rst = rst -> next;
	}
	
	//Second round circulation
	while(ptr1){
		rst -> next = ptr1;
		ptr1 = ptr1 -> next;
		rst = rst -> next;
	}
	
	while(ptr2){
		rst -> next = ptr2;
		ptr2 = ptr2 -> next;
		rst = rst -> next;
	}
	
	return head;	
}