//79.96%
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
			return vector<vector<int> > ();
		vector<vector<int> > res;
		vector<int> curr;
		pathSumHelper(res, curr, root, sum);
		return res;
    }
	
private:
	void pathSumHelper(vector<vector<int> >& res, vector<int>& curr, TreeNode *root, int sum){
		if(!root)
			return;
		curr.push_back(root -> val);
		if(root -> val == sum && !root -> left && !root -> right){
			res.push_back(curr);
			curr.pop_back();
			return;
		}
		
		pathSumHelper(res, curr, root -> left, sum - root -> val);
		pathSumHelper(res, curr, root -> right, sum - root -> val);
		curr.pop_back();
	}
};