//49.46%
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
    int diameterOfBinaryTree(TreeNode* root) {
		int height(0);
        return helper(root, height);
    }
private:
	int helper(TreeNode* root, int &height){
		if(!root){
			height = 0;
			return 0;
		}
		int hLeft(0), hRight(0);
		int resL(helper(root -> left, hLeft));
		int resR(helper(root -> right, hRight));
		int res(hLeft + hRight);
		res = max(res, resL);
		height = max(hLeft, hRight) + 1;
		return max(res, resR);
	}
};

//I made a little complex seems
public class Solution {
    int max = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return max;
    }
    
    private int maxDepth(TreeNode root) {
        if (root == null) return 0;
        
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        
        max = Math.max(max, left + right);
        
        return Math.max(left, right) + 1;
    }
}

class Solution {
public:
int diameterOfBinaryTree(TreeNode* root) {
    if(root == nullptr) return 0;
    int res = depth(root->left) + depth(root->right);
    return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int depth(TreeNode* root){
    if(root == nullptr) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}
};