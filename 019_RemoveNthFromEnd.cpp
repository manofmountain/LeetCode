/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//15.21%
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Check boundary
		if(!head || 0 >= n)
			return head;
		
		ListNode *ptr1 = head, *ptr2 = head;
		
		//Find the point
		while(n--)
		{
			ptr1 = ptr1 -> next;
			if(!ptr1)
			{
				if(0 == n)
					head = head -> next;
				return head;
			}
		}
		
		//Now remove the nth from the end
		while(ptr1 -> next)
		{
			ptr1 = ptr1 -> next;
			ptr2 = ptr2 -> next;
		}
		
		ptr2 -> next = ptr2 -> next -> next;
		
		return head;
    }
};