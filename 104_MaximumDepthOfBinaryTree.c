/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//34.48%
int maxDepth(struct TreeNode* root) {
    if(!root)
		return 0;
	int depthLeft = maxDepth(root -> left);
	int depthRight = maxDepth(root -> right);
	return depthLeft > depthRight ? depthLeft + 1 : depthRight + 1;
}


//Depth-first-search from LeetCode
int maxDepth(TreeNode *root)
{
    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}

//Breadth-first-search from LeetCode
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }
    
    return res;
}