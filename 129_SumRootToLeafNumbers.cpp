//16.21%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
private:
	int sumNumbersHelper(const TreeNode *root, int sum){
		if(!root)
			return 0;
		//If leaf node meets
		if(!root -> left && !root -> right)
			return sum * 10 + root -> val;
		
		return sumNumbersHelper(root -> left, sum * 10 + root -> val) + sumNumbersHelper(root -> right, sum * 10 + root -> val);
	}
};