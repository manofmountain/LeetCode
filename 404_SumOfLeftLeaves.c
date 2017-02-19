//9.34%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if(!root)
		return 0;
	int val = 0;
	if(root -> left && !(root -> left -> left) && !(root -> left -> right))
		val = root -> left -> val;
	return val + sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
}

