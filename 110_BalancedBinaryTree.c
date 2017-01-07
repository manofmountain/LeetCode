/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//13.1%
int heightTree(struct TreeNode *tree){
	if(!tree)
		return 0;
	int heightL = heightTree(tree -> left);
	int heightR = heightTree(tree -> right);
	return heightL > heightR ? heightL + 1 : heightR + 1;
}

bool isBalanced(struct TreeNode* root) {
    if(!root)
		return true;
	int heightL = heightTree(root -> left);
	int heightR = heightTree(root -> right);
	int diff = heightL > heightR ? heightL - heightR : heightR - heightL;
	return diff <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
}