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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
		if(!p) return q;
		if(!q) return p;
		int max(p -> val), min(q -> val);
		if(max < min){
			max = q -> val;
			min = p -> val;
		}
		if(root -> val >= min && root -> val <= max)
			return root;
		else if(root -> val < min)
			return lowestCommonAncestor(root -> right, p, q);
		else
			return lowestCommonAncestor(root -> left, p, q);
    }
};

//iterative way from LeetCode
class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};