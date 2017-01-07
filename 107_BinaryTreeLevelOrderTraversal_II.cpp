/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//1.05%
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
		if(!root)
			return res;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()){
			vector<int> layer;
			
			while(q.front()){
				TreeNode *curr = q.front();
				layer.push_back(curr -> val);
				if(curr -> left)
					q.push(curr -> left);
				if(curr -> right)
					q.push(curr -> right);
				q.pop();
			}
			q.pop();
			if(!q.empty())
				q.push(NULL);
			res.insert(res.begin(), layer);
		}
		return res;
    }
};

//Using Depth first search
vector<vector<int> > res;
void DFS(TreeNode* root, int level)
{
    if (root == NULL) return;
    if (level == res.size()) // The level does not exist in output
    {
        res.push_back(vector<int>()); // Create a new level
    }
    
    res[level].push_back(root->val); // Add the current value to its level
    DFS(root->left, level+1); // Go to the next level
    DFS(root->right,level+1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    DFS(root, 0);
    return vector<vector<int> > (res.rbegin(), res.rend());
}