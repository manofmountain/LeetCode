//85.12%
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
			return root;
		if(root -> val == key){
			if(root -> right){
				if(!root -> left)
					return root -> right;
				TreeNode* curr(root -> right);
				while(curr -> left)
					curr = curr -> left;
				curr -> left = root -> left;
				root = root -> right;
			}else
				root = root -> left;
		}else if(root -> val > key)
			root -> left = deleteNode(root -> left, key);
		else
			root -> right = deleteNode(root -> right, key);

		return root;
    }
};