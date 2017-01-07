/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//16.99%
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
			return 0;
		int depthL = maxDepth(root -> left);
		int depthR = maxDepth(root -> right);
		return depthL > depthR ? depthL + 1 : depthR + 1;
    }
};