
//59.87%
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
    bool isValidBST(TreeNode* root) {
        if(!root)
			return true;
		bool flagLeft(false);
		bool flagRight(false);
		if(!root -> left)
			flagLeft = true;
		else{
			TreeNode* temp(root -> left);
			while(temp -> right) temp = temp -> right;
			if(temp -> val < root -> val && isValidBST(root -> left))
				flagLeft = true;
		}
		
		if(!root -> right)
			flagRight = true;
		else{
			TreeNode* temp(root -> right);
			while(temp -> left) temp = temp -> left;
			if(temp -> val > root -> val && isValidBST(root -> right))
				flagRight = true;
		}
		return flagLeft && flagRight;
    }
};



//59.87% -> 9.28%%
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
    bool isValidBST(TreeNode* root) {
        if(!root)
			return true;
		bool flag(false);
		if(!root -> left)
			flag = true;
		else{
			TreeNode* temp(root -> left);
			while(temp -> right) temp = temp -> right;
			if(temp -> val < root -> val && isValidBST(root -> left))
				flag = true;
		}
		if(!flag)
			return false;
		flag = false;
		if(!root -> right)
			flag = true;
		else{
			TreeNode* temp(root -> right);
			while(temp -> left) temp = temp -> left;
			if(temp -> val > root -> val && isValidBST(root -> right))
				flag = true;
		}
		return flag;
    }
};

//BST inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};

//A java iterative way
public boolean isValidBST(TreeNode root) {
   if (root == null) return true;
   Stack<TreeNode> stack = new Stack<>();
   TreeNode pre = null;
   while (root != null || !stack.isEmpty()) {
      while (root != null) {
         stack.push(root);
         root = root.left;
      }
      root = stack.pop();
      if(pre != null && root.val <= pre.val) return false;
      pre = root;
      root = root.right;
   }
   return true;
}

//a clever recursive function and it's thinking looks like mine
bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}