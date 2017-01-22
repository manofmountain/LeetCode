/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//99.37%
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(!root)
		return NULL;
	if(!p)
		return q;
	if(!q)
		return p;
	
	int max = p -> val, min = q -> val;
	if(max < min){
		max = q -> val;
		min = p -> val;
	}
	if(root -> val >= min && root -> val <= max)
		return root;
	else if(root -> val < min)
		return lowestCommonAncestor(root -> right, p, q);
	else
		return lowestCommonAncestor(root -> left, p, q);	
}