/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//17.17%
void deleteNode(struct ListNode* node) {
	if(node && node -> next){
		struct ListNode *pre = NULL;
		while(node -> next){
			node -> val = node -> next -> val;
			pre = node;
			node = node -> next;
		}
		pre -> next = NULL;
	}
}

void deleteNode(struct ListNode* node) {
    *node = *node->next;
}

void deleteNode(struct ListNode* node) {
    struct ListNode* next = node->next;
    *node = *next;
    free(next);
}