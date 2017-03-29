//20.29%
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty())
			return NULL;
		return buildTreeHelper(inorder, 0, postorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
	TreeNode *buildTreeHelper(const vector<int>& inorder, int startI, int endI, const vector<int>& postorder, int startP, int endP){
		if(startI > endI)
			return NULL;
		if(startI == endI)
			return new TreeNode(inorder[startI]);
		
		TreeNode *root(new TreeNode(postorder[endP]));
		int pos;
		for(pos = startI; pos <= endI; ++pos){
			if(inorder[pos] == postorder[endP])
				break;
		}
		root -> left = buildTreeHelper(inorder, startI, pos - 1, postorder, startP, startP + pos - startI - 1);
		root -> right = buildTreeHelper(inorder, pos + 1, endI, postorder, startP + pos - startI, endP - 1);
		return root;
	}
};

//90.08%
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty())
			return NULL;
		int size(postorder.size());
		TreeNode *root(new TreeNode(postorder[size - 1]));
		TreeNode *curr(root);
		stack<TreeNode *> s;
		s.push(curr);
		int pIndex(size - 2), iIndex(size - 1);
		while(pIndex >= 0){
			if(curr -> val != inorder[iIndex]){
				curr -> right = new TreeNode(postorder[pIndex--]);
				curr = curr -> right;
				s.push(curr);
			}else{
				while(!s.empty() && s.top() -> val == inorder[iIndex]){
					curr = s.top();
					s.pop();
					--iIndex;
				}
				curr -> left = new TreeNode(postorder[pIndex--]);
				curr = curr -> left;
				s.push(curr);
			}
		}
		return root;
    }
};