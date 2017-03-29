//27.71%
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
    void flatten(TreeNode* root) {
        if(!root)
			return;
		stack<TreeNode *> s;
		s.push(root);
		TreeNode *curr(NULL);
		while(!s.empty()){
			if(curr)
				curr -> right = s.top();
			curr = s.top();
			s.pop();
			
			while(curr -> left || curr -> right){
				if(curr -> left){
					if(curr -> right)
						s.push(curr -> right);
					curr -> right = curr -> left;
					curr -> left = NULL;
					curr = curr -> right;
				}else{
					curr = curr -> right;
				}
			}
		}
    }
};


//27.71%
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
    void flatten(TreeNode* root) {
        if(!root)
			return;
		if(!root -> left && !root -> right)
			return;
		
		flatten(root -> left);
		flatten(root -> right);
		TreeNode *lchild(root -> left);
		while(lchild && lchild -> right)
			lchild = lchild -> right;
		if(lchild){
			lchild -> right = root -> right;
			root -> right = root -> left;
			root -> left = NULL;
		}
    }
};

//O(1) space
class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};


void flatten(TreeNode *root) {
	while (root) {
		if (root->left && root->right) {
			TreeNode* t = root->left;
			while (t->right)
				t = t->right;
			t->right = root->right;
		}

        if(root->left)
		    root->right = root->left;
		root->left = NULL;
		root = root->right;
	}
}