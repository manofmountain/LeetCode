//95.17%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Try using merge sorting
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next)
			return head;
		ListNode *slow(head), *fast(head);
		while(fast -> next && fast -> next -> next){
			slow = slow -> next;
			fast = fast -> next -> next;
		}
		ListNode *secondHalf(sortList(slow -> next));
		slow -> next = NULL;
		ListNode *firstHalf(sortList(head));
		ListNode newHead(0), *pre(&newHead);
		while(firstHalf && secondHalf){
			if(firstHalf -> val < secondHalf -> val){
				pre -> next = firstHalf;
				firstHalf = firstHalf -> next;
			}else{
				pre -> next = secondHalf;
				secondHalf = secondHalf -> next;
			}
			pre = pre -> next;
		}
		if(firstHalf)
			pre -> next = firstHalf;
		else if(secondHalf)
			pre -> next = secondHalf;
		return newHead.next;
    }
};