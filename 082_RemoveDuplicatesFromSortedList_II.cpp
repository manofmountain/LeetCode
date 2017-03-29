//7.18%
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next)
			return head;
		ListNode *orig(head), *curr(head);
		while(curr -> next && curr -> val == curr -> next -> val)
			curr = curr -> next;
		if(curr != orig){
			curr = curr -> next;
			return deleteDuplicates(curr);
		}else{
			curr -> next = deleteDuplicates(curr -> next);
			return curr;
		}
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//7.18%
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next)
			return head;
		ListNode *newHead(NULL), *pre(NULL), *start(head), *curr(head);
		while(curr -> next){
			if(curr -> val == curr -> next -> val)
				curr = curr -> next;
			else if(curr != start){
				start = curr = curr -> next;
			}else{
				if(pre){
					pre -> next = start;
					pre = pre -> next;
				}
				else
					newHead = pre = start;
				start = curr = curr -> next;
			}
		}
		
		if(start == curr){
			if(pre)
				pre -> next = start;
			else
				newHead = curr;
		}
		else{
			if(pre)
				pre -> next = NULL;
		}
		return newHead;			
    }
};


//Great C++ solution by using the second level pointer variable
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **runner = &head;
        
        if(!head || !head->next)return head;
        
        while(*runner)
        {
            if((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                ListNode *temp = *runner;
                while(temp && (*runner)->val == temp->val)
                    temp = temp->next;
                
                *runner = temp;
            }
            else
                runner = &((*runner)->next);
        }
        
        return head;
    }
};