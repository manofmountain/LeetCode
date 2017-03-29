//40.58%
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
			return;
		if(!root -> right){
			connect(ro0t -> left);
			return;
		}
		connect(root -> left);
		connect(root -> right);
		TreeLinkNode *lchild(root -> left), *rchild(root -> right);
		while(rchild){
			lchild -> next = rchild;
			lchild = lchild -> right;
			rchild = rchild -> left;
		}	
    }
};

//An iterative solution from LeetCode
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}