//69.41%
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
    int pathSum(TreeNode* root, int sum) {
        if(!root)
			return 0;
		return pathSumHelper(root, sum) + pathSum(root -> left, sum) + pathSum(root -> right, sum);	
    }
private:
	int pathSumHelper(TreeNode *root, int sum){
		if(!root)
			return 0;
		int count(0);
		if(sum == root -> val)
			count++;
		count += pathSumHelper(root -> left, sum - root -> val);
		count += pathSumHelper(root -> right, sum - root -> val);
		return count;
	}
};