//28.3%
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next)
			return head;
		
		ListNode *curr(head -> next), *prev(head);
		while(curr){
			ListNode *start(head), *preStart(NULL);
			while(start -> val < curr -> val){
				preStart = start;
				start = start -> next;
			}
			if(start != curr){
				prev -> next = curr -> next;
				if(preStart){
					preStart -> next = curr;
					curr -> next = start;
				}else{
					head = curr;
					curr -> next = start;
				}
				curr = prev -> next;
			}else{
				prev = curr;
				curr = curr -> next;
			}
		}
		return head;
    }
};