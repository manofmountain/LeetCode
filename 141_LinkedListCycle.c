/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//11.98%
bool hasCycle(struct ListNode *head) {
    if(!head)
		return false;
	struct ListNode *fast = head -> next, *slow = head;
	//if(fast)
	//	fast = fast -> next;
	while(fast){
		slow = slow -> next;
		fast = fast -> next;
		if(slow == fast)
			return true;
		if(fast)
			fast = fast -> next;
	}
	return false;
}