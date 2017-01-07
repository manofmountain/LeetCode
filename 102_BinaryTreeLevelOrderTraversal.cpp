/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//3.72%
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
		if(!root)
			return res;
		queue<TreeNode *> q;
		queue<TreeNode *> p;
		q.push(root);
		//vector<int> layer;
		while(!q.empty() || !p.empty()){
			vector<int> layer;
			queue<TreeNode *> &qFull = (p.empty()) ? q : p;
			queue<TreeNode *> &pEmpty = (q.empty()) ? q : p;
			while(!qFull.empty()){
				layer.push_back(qFull.front() -> val);
				if(qFull.front() -> left)
					pEmpty.push(qFull.front() -> left);
				if(qFull.front() -> right)
					pEmpty.push(qFull.front() -> right);
				qFull.pop();
			}
			res.push_back(layer);
		}
		return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Another solution I did before which only need one 'queue'
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
	{
        vector<vector<int>> result;
		vector<int> currLayer;
		if(!root)
			return result;
		
		queue<TreeNode*> qNodes;
		TreeNode* currNode;
		qNodes.push(root);
		
		int currNum = 0;
		int nextNum = 1;
		while(!qNodes.empty() && nextNum)
		{
			currNum = nextNum;
			nextNum = 0;
			while(currNum--)
			{
				currNode = qNodes.front();
				currLayer.push_back(currNode -> val);
				qNodes.pop();
				if(currNode -> left)
				{
					nextNum++;
					qNodes.push(currNode -> left);
				}
				if(currNode -> right)
				{
					nextNum++;
					qNodes.push(currNode -> right);
				}
			}
			result.push_back(currLayer);
			currLayer.clear();
		}
		
		return result;
    }
};

//Another solution from LeetCode which use re-cursive
vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());
    
    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}

// A solution from LeetCode which use a 'NULL' to separate different layers and use only one queue
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};