/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//16.33%
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
			return NULL;
		convertBST(root -> right);
		if(prev){
			if(root -> val + preSum == prev -> val)
				root -> val = prev -> val;
			else{
				root -> val += (prev -> val);
				preSum = prev -> val;
			}
		}
		prev = root;
		convertBST(root -> left);
		return root;
    }
private:
	int preSum{0};
	TreeNode* prev{nullptr};
};


//Didn't consider if any nodes having the same values within the tree
public class Solution {

    int sum = 0;
    
    public TreeNode convertBST(TreeNode root) {
        convert(root);
        return root;
    }
    
    public void convert(TreeNode cur) {
        if (cur == null) return;
        convert(cur.right);
        cur.val += sum;
        sum = cur.val;
        convert(cur.left);
    }
    
}

class Solution {
private:
    int cur_sum = 0;
public:
    void travel(TreeNode* root){
        if (!root) return;
        if (root->right) travel(root->right);
        
        root->val = (cur_sum += root->val);
        if (root->left) travel(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};

public class Solution {
    int sum = 0;
    
    public TreeNode convertBST(TreeNode root) {
        if (root == null) return null;
        
        convertBST(root.right);
        
        root.val += sum;
        sum = root.val;
        
        convertBST(root.left);
        
        return root;
    }
}