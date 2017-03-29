//50.89% (Remember, buddy, it's a binary tree, not a BST..)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
			return NULL;
		return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
	TreeNode* buildTreeHelper(vector<int>& preorder, int startP, int endP, vector<int>& inorder, int startI, int endI){
		if(startP > endP)
			return NULL;
		if(startP == endP)
			return new TreeNode(preorder[startP]);
		TreeNode *root(new TreeNode(preorder[startP]));
		int mid(-1);
		int left(startI), right(endI);
		while(left <= right){
			if(inorder[left] == preorder[startP])
				break;
		}
		mid = left;
		root -> left = buildTreeHelper(preorder, startP + 1, startP + mid - startI, inorder, startI, mid - 1);
		root -> right = buildTreeHelper(preorder, startP + mid - startI + 1, endP, inorder, mid + 1, endI);
		return root;
	}
};

//A straight way from LeetCode
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    return node;
}

//92.81%%
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root=NULL; stack<TreeNode *> MyData;
        if(preorder.empty()) return root;
        root = new TreeNode(preorder[0]);
        MyData.push(root); int index = 0;
       	for(int i=1; i<preorder.size(); i++) {
       		TreeNode *cur = MyData.top();
       		if((MyData.top()->val)!=inorder[index]) {
       			cur->left = new TreeNode(preorder[i]);
       			MyData.push(cur->left);
       		} else {
       			while(!MyData.empty() && ((MyData.top()->val)==inorder[index])) {
       				cur=MyData.top(); MyData.pop(); index++; 
       			}
       			cur->right = new TreeNode(preorder[i]);
       			MyData.push(cur->right);
       		}  
       	}
       	return root;
    }
};

//Another iterative function solution from LeetCode
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        if(preorder.size()==0)
            return NULL;
        
        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;
        
        f=i=j=0;
        s.push(preorder[i]);
        
        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;
        
        while(i<preorder.size())
        {
            if(!st.empty() && st.top()->val==inorder[j])
            {
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }
            else
            {
                if(f==0)
                {
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else 
                {
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }
        
        return root;
    }
};