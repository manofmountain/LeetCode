/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//3.31%
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
			return vector<int>();
		stack<TreeNode *> s;
		TreeNode *curr(root);
		vector<int> res;
		while(!s.empty() || curr){
			if(!curr){
				curr = s.top();
				s.pop();
			}
				
			if(curr -> left){
				TreeNode *lchild(curr -> left);
				curr -> left = NULL;
				s.push(curr);
				curr = lchild;
			}else if(curr -> right){
				TreeNode *rchild(curr -> right);
				curr -> right = NULL;
				s.push(curr);
				curr = rchild;
			}else{
				res.push_back(curr -> val);
				curr = NULL;
			}
		}
		return res;
    }
};

//Inverse the preorderTraversal
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> v;
    if (!root) return v;
    
    stack<TreeNode *> s;
    s.push(root);
    
    TreeNode *p = NULL;
    while(!s.empty()) {
        p = s.top();
        s.pop();
        v.insert(v.begin(), p->val);
        if (p->left) s.push(p->left);
        if (p->right) s.push(p->right);
    }
    
    return v;
}

//This is the one i actually want to see
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> toVisit;
    TreeNode* curNode = root;
    TreeNode* lastNode = NULL;
    while (curNode || !toVisit.empty()) {
        if (curNode) {
            toVisit.push(curNode);
            curNode = curNode -> left;
        }
        else {
            TreeNode* topNode = toVisit.top();
            if (topNode -> right && lastNode != topNode -> right)
                curNode = topNode -> right;
            else {
                nodes.push_back(topNode -> val);
                lastNode = topNode;
                toVisit.pop();
            }
        }
    }
    return nodes;
}


//Morris traversal
void reverseNodes(TreeNode* start, TreeNode* end) {
    if (start == end) return;
    TreeNode* x = start;
    TreeNode* y = start -> right;
    TreeNode* z;
    while (x != end) {
        z = y -> right;
        y -> right = x;
        x = y;
        y = z;
    }
}
void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
    reverseNodes(start, end);
    TreeNode* node = end;
    while (true) {
        nodes.push_back(node -> val);
        if (node == start) break;
        node = node -> right;
    }
    reverseNodes(end, start);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    TreeNode* dump = new TreeNode(0);
    dump -> left = root;
    TreeNode* curNode = dump;
    while (curNode) {
        if (curNode -> left) {
            TreeNode* predecessor = curNode -> left;
            while (predecessor -> right && predecessor -> right != curNode)
                predecessor = predecessor -> right;
            if (!(predecessor -> right)) {
                predecessor -> right = curNode;
                curNode = curNode -> left;
            }
            else {
                reverseAddNodes(curNode -> left, predecessor, nodes);
                predecessor -> right = NULL;
                curNode = curNode -> right;
            }
        }
        else curNode = curNode -> right;
    }
    return nodes;
}