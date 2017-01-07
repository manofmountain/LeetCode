/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//20%
bool hasPathSum(struct TreeNode* root, int sum) {
    if(!root)
		return false;

	int currSum = root -> val;
	if(currSum == sum && !root -> left && !root -> right)
		return true;
	if(hasPathSum(root -> left, sum - currSum) || hasPathSum(root -> right, sum - currSum))
		return true;
	return false;	
}