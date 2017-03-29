//32.68%
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
    int rob(TreeNode* root) {
		if(records.find(root) != records.end())
			return records[root];
        if(!root)
			return 0;
		int leftTotal(rob(root -> left)), rightTotal(rob(root -> right));
		int sum(root -> val);
		if(root -> left){
			sum += rob(root -> left -> left);
			sum += rob(root -> left -> right);
		}
		if(root -> right){
			sum += rob(root -> right -> left);
			sum += rob(root -> right -> right);
		}
		records.insert(pair<TreeNode*, int>(root, max(sum, leftTotal + rightTotal)));
		//records[root] = max(sum, leftTotal + rightTotal);
		return records[root];
    }
private:
	map<TreeNode *, int> records;
};


//62.25%
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
    int rob(TreeNode* root) {
		if(!root)
			return 0;
		vector<int> res(2);
		robSub(root, res)
		return max(res[0], res[1]);
    }
private:
	void robSub(TreeNode* root, vector<int>& res){
		if(!root)
			return;
		vector<int> leftRes(2), rightRes(2);
		robSub(root -> left, leftRes);
		robSub(root -> right, rightRes);
		res[0] = max(leftRes[0], leftRes[1]) + max(rightRes[0], rightRes[1]);
		res[1] = root -> val + leftRes[0] + rightRes[0];
	}
};

//70.53%
class Solution {
public:
    int rob(TreeNode* root) {
        return robDFS(root).second;
    }
    pair<int, int> robDFS(TreeNode* node){
        if( !node) return make_pair(0,0);
        auto l = robDFS(node->left);
        auto r = robDFS(node->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + node->val);
        return make_pair(f2, f1);
    }
};