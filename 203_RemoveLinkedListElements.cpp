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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && val == head -> val)
			head = head -> next;
		ListNode *pre(head);
		while(pre){
			while(pre -> next && pre -> next -> val == val)
				pre -> next = pre -> next -> next;
			pre = pre -> next;
		}
		return head;
    }
};

//Use second order pointer
ListNode *removeElements(ListNode *head, int val)
{
    ListNode **list = &head;

    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }

    return head;
}

void removeHelper(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->val == val)
    {
        head = head->next;
    }
    else
    {
        removeHelper(head->next, val);
    }
}