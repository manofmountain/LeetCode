//25.87%
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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head -> next)
			return head;
		
		ListNode *larger(head), *prevL(NULL);
		//Make sure 'larger' points to first value larger or equal than 'x'
		while(larger && larger -> val < x){
			prevL = larger;
			larger = larger -> next;
		}
		if(!larger)
			return head;
		
		ListNode *curr(larger -> next), *prevCurr(larger);
		while(curr){
			if(curr -> val < x){
				if(!prevL)
					head = curr;
				else
					prevL -> next = curr;
				prevCurr -> next = curr -> next;
				curr -> next = larger;
				prevL = curr;
				curr = prevCurr -> next;
			}else{
				prevCurr = curr;
				curr = curr -> next;
			}
		}
		return head;
    }
};

//Such a concise solution from LeetCode which only use two nodes' space. !!!
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}