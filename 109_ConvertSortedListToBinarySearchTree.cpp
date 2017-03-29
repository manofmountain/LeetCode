//31.63%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
		if(!head -> next) return new TreeNode(head -> val);
		
		ListNode *pre(NULL), *fast(head), *slow(head -> next);
		while(slow){
			//slow = slow -> next;
			pre = fast;
			fast = fast -> next;
			slow = slow -> next;
			if(slow)
				slow = slow -> next;
		}
		TreeNode *root(new TreeNode(fast -> val));
		pre -> next = NULL;
		root -> left = sortedListToBST(head);
		root -> right = sortedListToBST(fast -> next);
		return root;	
    }
};

//In this way, we won't change input list
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
    	return sortedListToBST( head, NULL );
    }
    
private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
    	if( head == tail )
    		return NULL;
    	if( head->next == tail )    // 
    	{	
    		TreeNode *root = new TreeNode( head->val );
    		return root;
    	}
    	ListNode *mid = head, *temp = head;
    	while( temp != tail && temp->next != tail )    // 寻找中间节点
    	{
    		mid = mid->next;
    		temp = temp->next->next;
    	}
    	TreeNode *root = new TreeNode( mid->val );
    	root->left = sortedListToBST( head, mid );
    	root->right = sortedListToBST( mid->next, tail );
    	return root;
    }
};