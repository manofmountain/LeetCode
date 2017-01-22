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
    bool isPalindrome(ListNode* head) {
        ListNode *first(head), *curr(head), *pre(NULL);
		int count(0);
		
		//Count node numbers
		while(curr){
			curr = curr -> next;
			count++;
		}
		count -= (count >> 1);
		
		//Split these twor parts
		curr = head;
		while(count--){
			pre = curr;
			curr = curr -> next;
		}
		if(pre)
			pre -> next = NULL;
		
		//Invert second part
		pre = NULL;
		while(curr){
			ListNode *next(curr -> next);
			curr -> next = pre, pre = curr, curr = next;
		}
		
		//Compare two parts now
		while(pre && first){
			if(pre -> val != first -> val)
				return false;
			pre = pre -> next, first = first -> next;
		}
		return true;
    }
};

//A better solution than mine
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};