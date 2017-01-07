/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//18.75%
int minDepth(struct TreeNode* root) {
    if(!root)
		return 0;
	if(!root -> left)
		return minDepth(root -> right) + 1;
	if(!root -> right)
		return minDepth(root -> left) + 1;
	
	int heightL = minDepth(root -> left);
	int heightR = minDepth(root -> right);
	return  heightL < heightR ? heightL + 1 : heightR + 1;
}