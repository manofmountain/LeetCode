/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//3.39%
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
			return root;
		bool withinLeftP(false), withinLeftQ(false);
		isExist(root -> left, p, q, withinLeftP, withinLeftQ);
		if(withinLeftP && withinLeftQ)
			return lowestCommonAncestor(root -> left, p, q);
		
		bool withinRightP(false), withinRightQ(false);
		isExist(root -> right, p, q, withinRightP, withinRightQ);
		if(withinRightP && withinRightQ)
			return lowestCommonAncestor(root -> right, p, q);
		return root;
    }
private:
	void isExist(TreeNode *root, TreeNode *p, TreeNode *q, bool& withinP, bool& withinQ){
		if(!root)
			return;
		if(!withinP && p == root)
			withinP = true;
		if(!withinQ && q == root)
			withinQ = true;
		if(withinP && withinQ)
			return;
		isExist(root -> left, p, q, withinP, withinQ);
		isExist(root -> right, p, q, withinP, withinQ);
	}		
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//53.1%
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
			return root;
		if(p == q)
			return p;
		vector<TreeNode *> pathP, pathQ;
		TreeNode *res;
		findPath(root, p, pathP);
		findPath(root, q, pathQ);
		int i, j;
		for(i = pathP.size() - 1, j = pathQ.size() - 1; i > 0 && j > 0; --i, --j){
			if(pathP[i - 1] != pathQ[j - 1])
				break;
		}
		return pathP[i];
    }
private:
	bool findPath(TreeNode *curr, TreeNode *p, vector<TreeNode *>& path){
		if(!curr)
			return false;
		if(curr == p || findPath(curr -> left, p, path) || findPath(curr -> right, p, path)){
			path.push_back(curr);
			return true;
		}else
			return false;
	}		
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}