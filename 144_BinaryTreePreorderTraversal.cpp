//3.12%
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
			return vector<int>();
		vector<int> res;
		stack<TreeNode *> s;
		s.push(root);
		while(!s.empty()){
			TreeNode *curr(s.top());
			s.pop();
			res.push_back(curr -> val);
			if(curr -> right)
				s.push(curr -> right);
			if(curr -> left)
				s.push(curr -> left);
		}
		return res;
    }
};


//My previous solution a year ago and it should be better
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
	{
        vector<int> result;
		stack<TreeNode*> sNodes;
		if(!root)
			return result;
		sNodes.push(root);
		TreeNode* currentNode;
		while(!sNodes.empty())
		{
			currentNode = sNodes.top();
			sNodes.pop();
			result.push_back(currentNode -> val);
			if(currentNode -> right)
				sNodes.push(currentNode -> right);
			currentNode = currentNode -> left;
			while(currentNode)
			{
				if(currentNode -> right)
					sNodes.push(currentNode -> right);
				result.push_back(currentNode -> val);
				currentNode = currentNode -> left;
			}
		}
		return result;	
    }
};

//3.14%
//Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
			return vector<int>();
		vector<int> res;
		TreeNode *curr(root);
		while(curr){
			if(curr -> left){
				TreeNode *predecessor(curr -> left);
				while(predecessor -> right && predecessor -> right != curr)
					predecessor = predecessor -> right;
				if(!predecessor -> right){
					res.push_back(curr -> val);
					predecessor -> right = curr;
					curr = curr -> left;
				}else{
					curr = curr -> right;
					predecessor -> right = NULL;
				}
			}else{
				res.push_back(curr -> val);
				curr = curr -> right;
			}
		}
		return res;
    }
};