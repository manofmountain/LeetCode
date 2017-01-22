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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next)
			return head;
		ListNode *pre(head), *curr(head -> next);
		ListNode *after(curr -> next);
		pre -> next = NULL;
		curr -> next = pre;
		pre = curr;
		curr = after;
		while(curr){
			after = curr -> next;
			curr -> next = pre;
			pre = curr;
			curr = after;
		}
		return pre;
    }
};

//More clear than Mine from LeetCode solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }
};

//A Recursive function
class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 