/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//17.58%
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
		if(!root) return res;
		string base("");
		base += int2string(root -> val);
		if(!root -> left && !root -> right){
			res.push_back(base);
			return res;
		}
		binaryTreePathsHelper(res, base, root -> left);
		binaryTreePathsHelper(res, base, root -> right);
		return res;
    }
	void binaryTreePathsHelper(vector<string> &res, string base, TreeNode *node){
		if(!node){
			return;
		}
		base += "->";
		base += int2string(node -> val);
		if(!node -> left && !node -> right){
			res.push_back(base);
			return;
		}
		binaryTreePathsHelper(res, base, node -> left);
		binaryTreePathsHelper(res, base, node -> right);
	}
	string int2string(int val){
		stringstream s;
		s << val;
		return s.str();
	}
};

//A better solution than mine from LeetCode
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;
    
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}

