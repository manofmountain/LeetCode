/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//3.41%
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //Check boundary conditions
	if(!head || 0 >= n)
		return head;
	
	struct ListNode *ptr1 = head;
	struct ListNode *ptr2 = head;
	//Find the nth from the start
	while(n--)
	{
		ptr2 = ptr2 -> next;
		if(!ptr2)
		{
			if(0 == n)
				head = head -> next;
			return head;
		}
	}
	
	//Untile the last endpoint
	while(ptr2 -> next)
	{
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next;
	}
	
	//Remove the nth endpoint from end, it's 'ptr1 -> next'
	ptr1 -> next = ptr1 -> next -> next;
	
	return head;
}
 
//3.41%
int removeNthFromEndHelper(struct ListNode *prev, int n)
{
	struct ListNode *curr = prev -> next;
	if(!curr)
		return 0;
	int pos = 1 + removeNthFromEndHelper(curr, n);
	if(pos == n)
		prev -> next = curr -> next;
	return pos;
}
		
struct ListNode* removeNthFromEnd001(struct ListNode* head, int n) {
    struct ListNode *prev = head;
	int index = 0;
	if(!prev || 0 >= n)
		return head;
	
	index = 1 + removeNthFromEndHelper(prev, n);
	if(index == n)
		head = head -> next;
	return head;	
}