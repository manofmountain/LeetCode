/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(!root)
		return root;
	struct TreeNode *nodeLeft = invertTree(root -> right);
	struct TreeNode *nodeRight = invertTree(root -> left);
	root -> left = nodeLeft, root -> right = nodeRight;
	return root;
}