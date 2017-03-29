//46.59%
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
    ListNode* oddEvenList(ListNode* head) {
		if(!head || !head -> next)
			return head;
        ListNode evenNodes(0);
		ListNode *currOdd(head), *currEven(head -> next);
		evenNodes.next = currEven;
		while(currEven){
			currOdd -> next = currEven -> next;
			if(currOdd -> next)
				currOdd = currOdd -> next;
			else{
				currOdd -> next = evenNodes.next;
				return head;
			}
			currEven -> next = currOdd -> next;	
			currEven = currEven -> next;
		}
		currOdd -> next = evenNodes.next;
		return head;
    }
};

//A java solution which seemed good
public class Solution {
public ListNode oddEvenList(ListNode head) {
    if (head != null) {
    
        ListNode odd = head, even = head.next, evenHead = even; 
    
        while (even != null && even.next != null) {
            odd.next = odd.next.next; 
            even.next = even.next.next; 
            odd = odd.next;
            even = even.next;
        }
        odd.next = evenHead; 
    }
    return head;
}}

//The same C++ solution
   ListNode* oddEvenList(ListNode* head) 
    {
        if(!head) return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }