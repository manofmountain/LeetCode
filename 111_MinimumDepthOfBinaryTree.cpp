/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//5.56%
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
			return 0;
		if(!root -> left)
			return minDepth(root -> right) + 1;
		if(!root -> right)
			return minDepth(root -> left) + 1;
		return min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
};

//Solution from LeetCode
int minDepth(TreeNode* root) {
    if (!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
}