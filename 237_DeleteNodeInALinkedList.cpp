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
    void deleteNode(ListNode* node) {
        if(node && node -> next){
			ListNode *pre(NULL);
			while(node -> next){
				node -> val = node -> next -> val;
				pre = node;
				node = node -> next;
			}
			pre -> next = NULL;
		}
    }
};

void deleteNode(ListNode* node) {
    *node = *node->next;
}

void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}