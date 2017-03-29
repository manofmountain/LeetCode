//61.26%
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
    int countNodes(TreeNode* root) {
        if(!root)
			return 0;
		//if(!root -> left)
		//	return 1;
		int heightLeft(1);
		TreeNode *curr(root -> left);
		while(curr){
			curr = curr -> left;
			++heightLeft;
		}
		int heightRight(1);
		curr = root -> right;
		while(curr){
			curr = curr -> left;
			++heightRight;
		}
		if(heightLeft == heightRight)
			return (1 << (heightLeft - 1)) + countNodes(root -> right);
		else
			return (1 << (heightRight - 1)) + countNodes(root -> left);
    }
};

//Optimization  97.75%
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
			return 0;
		int heightLeft(1);
		TreeNode *curr(root -> left);
		while(curr){
			curr = curr -> left;
			++heightLeft;
		}
		return countNodesHelper(root, heightLeft);
    }
private:
	int countNodesHelper(TreeNode* root, int heightLeft){
		if(!root)
			return 0;
		int heightRight(1);
		TreeNode *curr(root -> right);
		while(curr){
			curr = curr -> left;
			++heightRight;
		}
		if(heightLeft == heightRight)
			return (1 << (heightLeft - 1)) + countNodesHelper(root -> right, heightRight - 1);
		else
			return (1 << (heightRight - 1)) + countNodesHelper(root -> left, heightLeft - 1);
	}
};

//A slow one
class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};