/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//26.8%
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		
		int remain(0);
		ListNode *head(new ListNode(0));
		ListNode **curr(&(head -> next));
		//head -> next = (*curr);
		ListNode *p1(l1), *p2(l2);
		while(p1 || p2){
			int sum(remain);
			if(p1){
				sum += p1 -> val;
				p1 = p1 -> next;
			}
			if(p2){
				sum += p2 -> val;
				p2 = p2 -> next;
			}
			(*curr) = new ListNode(sum % 10);
			//curr -> val = sum % 10;
			remain = sum / 10;
			curr = &((*curr) -> next);
		}
		if(remain){
			*curr = new ListNode(remain);
			//curr -> val = remain;
		}
		curr = &(head -> next);
		delete head;
		return (*curr);
    }
};

//More concise and clear than mine
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}