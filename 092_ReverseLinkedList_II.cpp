//17.94%
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *curr(head), *pre(NULL);
		int index(1);
		while(index < m){
			pre = curr;
			curr = curr -> next;
			++index;
		}
		
		//Start reversing from 'm'
		ListNode *next(NULL), *preR(NULL), *newHead(curr);
		while(index <= n && curr){
			next = curr -> next;
			curr -> next = preR;
			preR = curr;
			curr = next;
			++index;
		}
		if(pre)
			pre -> next = preR;
		else
			head = preR;
		newHead -> next = curr;
		return head;
    }
};

//1.6%
 ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n)return head;
	n-=m;
    ListNode prehead(0);
    prehead.next=head;
    ListNode* pre=&prehead;
    while(--m)pre=pre->next;        
    ListNode* pstart=pre->next;
    while(n--)
    {
        ListNode *p=pstart->next;
        pstart->next=p->next;
        p->next=pre->next;
        pre->next=p;
    }
    return prehead.next;
}

//Another faster one (17.94%)
class Solution {  
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        for (int i = 0; i < m - 1; i++)
            pre = pre -> next;
        ListNode* cur = pre -> next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur -> next; 
            cur -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }
        return new_head -> next;
    }
};