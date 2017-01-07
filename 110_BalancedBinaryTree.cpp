/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//78.07%
class Solution {
public:
	bool isBalancedHelper(TreeNode *tree, int &height){
		height = 0;
		int heightL(0), heightR(0);
		if(!tree || isBalancedHelper(tree -> left, heightL) && isBalancedHelper(tree -> right, heightR) && abs(heightL - heightR) <= 1){
			height = heightL > heightR ? heightL + 1 : heightR + 1;
			return true;
		}
		return false;
	}
				
    bool isBalanced(TreeNode* root) {
        int heightL(0), heightR(0);
		if(!root || isBalancedHelper(root -> left, heightL) && isBalancedHelper(root -> right, heightR) && abs(heightL - heightR) <= 1)
			return true;
		return false;
    }
};