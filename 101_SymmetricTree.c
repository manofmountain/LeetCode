/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//79.05% 
bool isSymmetricHelper(struct TreeNode *treeL, struct TreeNode *treeR){
	if(!treeL && !treeR)
		return true;
	if(!treeL || !treeR || treeL -> val != treeR -> val)
		return false;
	return isSymmetricHelper(treeL -> left, treeR -> right) && isSymmetricHelper(treeL -> right, treeR -> left);
}

bool isSymmetric(struct TreeNode* root) {
    if(!root)
		return true;
	return isSymmetricHelper(root -> left, root -> right);
}