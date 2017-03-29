//37.12%
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root):currIndex(0) {
		//We did a inorder tracing here and obtain 'inorderArray'
		if(!root)
			return;
        stack<TreeNode *> s;
		//s.push(root);
		TreeNode *curr(root);
		while(!s.empty() || curr){
			if(curr){
				if(curr -> left){
					s.push(curr);
					curr = curr -> left;
				}else{
					inorderArray.push_back(curr -> val);
					curr = curr -> right;
				}
			}else{
				curr = s.top();
				s.pop();
				inorderArray.push_back(curr -> val);
				curr = curr -> right;
			}
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return currIndex < inorderArray.size();
    }

    /** @return the next smallest number */
    int next() {
        return inorderArray[currIndex++];
    }
private:
	vector<int> inorderArray;
	int currIndex;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
//Clearly a better solution from LeetCode 
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};