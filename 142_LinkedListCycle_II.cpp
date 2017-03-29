//46.09%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next)
			return NULL;
		ListNode *fast(head -> next), *slow(head);
		while(fast){
			fast = fast -> next;
			slow = slow -> next;
			if(fast == slow)
				break;
			if(fast)
				fast = fast -> next;
		}
		if(!fast)
			return NULL;
		slow = head;
		while(slow != fast){
			slow = slow -> next;
			fast = fast -> next;
		}
		return slow;
    }
};