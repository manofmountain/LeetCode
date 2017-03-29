//41.13%
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
    int kthSmallest(TreeNode* root, int k) {
        int cntLeft(countOfBST(root -> left));
		if(cntLeft == k - 1)
			return root -> val;
		else if(cntLeft < k - 1)
			return kthSmallest(root -> right, k - cntLeft - 1);
		else
			return kthSmallest(root -> left, k);
    }
private:
	int countOfBST(TreeNode* root){
		if(!root)
			return 0;
		return 1 + countOfBST(root -> left) + countOfBST(root -> right);
	}
};


//By using InOrder
int kthSmallest(TreeNode* root, int k) {
    return find(root, k);
}
int find(TreeNode* root, int& k) {
    if (root) {
        int x = find(root->left, k);
        return !k ? x : !--k ? root->val : find(root->right, k);
    }
}

//Iterative solution by using InOrder
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(--k == 0)
                return p->val;
            st.pop();
            p = p->right;
        }
    }
};