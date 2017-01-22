/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//72.22%
bool isPalindrome(struct ListNode* head) {
    struct ListNode *curr = head, *first = head;
	int count = 0;
	while(curr){
		count++;
		curr = curr -> next;
	}
	curr = head;
	count -= (count >> 1);
	struct ListNode *pre = NULL;
	
	//Split the list to two parts
	while(count--){
		pre = curr;
		curr = curr -> next;
	}
	if(pre)
		pre -> next = NULL;
	
	//Inverse second half list
	pre = NULL;
	while(curr){
		struct ListNode *next = curr -> next;
		curr -> next = pre;
		pre = curr;
		curr = next;
	}
	
	//Compare these two half parts started with 'pre' and 'first' separately
	while(pre && first){
		if(pre -> val != first -> val)
			return false;
		pre = pre -> next;
		first = first -> next;
	}
	return true;
}