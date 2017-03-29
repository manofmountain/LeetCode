//11.99%
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
    ListNode* rotateRight(ListNode* head, int k) {
		if(k <= 0 || !head)
			return head;
		
        //First obtain list's length
		int len(1);
		ListNode* curr(head);
		while(curr -> next){
			len++;
			curr = curr -> next;
		}
		
		k %= len;
		if(!k)
			return head;
		curr -> next = head;
		//Find new head of the rotated list
		int index(len - k);
		ListNode* newHead(head);
		while(index){
			curr = newHead;
			newHead = newHead -> next;
			index--;
		}
		curr -> next = NULL;
		return newHead;	
    }
};

//Almost the same idea with mine
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};