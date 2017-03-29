//4.48%
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
			return vector<vector<int> >();
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);q.push(NULL);
		vector<int> currLayer;
		bool flag(false); //while 'false' from right to left, while 'true' from left to right
		while(!q.empty()){
			TreeNode *node(q.front());
			q.pop();
			if(node){
				currLayer.push_back(node -> val);
				if(node -> left) q.push(node -> left);
				if(node -> right) q.push(node -> right);
			}else{
				if(!q.empty())
					q.push(NULL);
				if(flag)
					reverse(currLayer.begin(), currLayer.end());
				res.push_back(currLayer);
				currLayer.resize(0);
				flag = !flag;
			}
		}
		return res;
    }
};


//39.58%
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if(!root)
			return vector<vector<int> >();
		vector<vector<int>> res;
		preOrderBuilding(res, root, 0);
		for(int i = 1; i < res.size(); i += 2){
			reverse(res[i].begin(), res[i].end());
		}
		return res;
    }
private:
	void preOrderBuilding(vector<vector<int>>& res, TreeNode *curr, int level){
		if(res.size() == level)
			res.push_back(vector<int>());
		res[level].push_back(curr -> val);
		if(curr -> left) preOrderBuilding(res, curr -> left, level + 1);
		if(curr -> right) preOrderBuilding(res, curr -> right, level + 1);
	}
};

//39.58%
//A very clever solution which don't need reverse operations
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

//39.58%
//Use deque data structure which is also very clever
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    std::deque<TreeNode*> deq;
    deq.push_back(root);
    int iszig=1;
    while(!deq.empty()) {
        int sz=deq.size();
        iszig=iszig^1;
        vector<int> row;
        while(sz--) {
            if(iszig) { // pop_front, push_back, right then left
                root=deq.front();deq.pop_front();
                row.push_back(root->val);
                if(root->right) deq.push_back(root->right);
                if(root->left) deq.push_back(root->left);
            }
            else { // pop_back, push_front, left then right
                root=deq.back();deq.pop_back();
                row.push_back(root->val);
                if(root->left) deq.push_front(root->left);
                if(root->right) deq.push_front(root->right);
            }
        }
        res.push_back(row);
    }
    return res;
}