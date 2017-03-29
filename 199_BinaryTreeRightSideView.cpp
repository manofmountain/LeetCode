/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//27.62%
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
			return vector<int>();
		queue<TreeNode* > q;
		q.push(root);
		q.push(NULL);
		vector<int> res;
		vector<vector<int> > layers(1);
		int level(0);
		while(!q.empty()){
			TreeNode *node(q.front());
			q.pop();
			if(node){
				layers[level].push_back(node -> val);
				if(node -> left)
					q.push(node -> left);
				if(node -> right)
					q.push(node -> right);
			}else{
				if(!q.empty()){
					q.push(NULL);
					++level;
					layers.push_back(vector<int>());
				}
			}
		}
		
		for(int i = 0; i < layers.size(); ++i){
			res.push_back(layers[i].back());
		}
		return res;
    }
};

//A fabulious solution by using pre-order traversing
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};

//A java solution
public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        rightView(root, result, 0);
        return result;
    }
    
    public void rightView(TreeNode curr, List<Integer> result, int currDepth){
        if(curr == null){
            return;
        }
        if(currDepth == result.size()){
            result.add(curr.val);
        }
        
        rightView(curr.right, result, currDepth + 1);
        rightView(curr.left, result, currDepth + 1);
        
    }
}

//Even using level order we still can have another space efficient way
public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        // reverse level traversal
        List<Integer> result = new ArrayList();
        Queue<TreeNode> queue = new LinkedList();
        if (root == null) return result;
        
        queue.offer(root);
        while (queue.size() != 0) {
            int size = queue.size();
            for (int i=0; i<size; i++) {
                TreeNode cur = queue.poll();
                if (i == 0) result.add(cur.val);
                if (cur.right != null) queue.offer(cur.right);
                if (cur.left != null) queue.offer(cur.left);
            }
            
        }
        return result;
    }
}