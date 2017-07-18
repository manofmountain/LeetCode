/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//26.56%
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
			return {};
		vector<int> res;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			q.push(nullptr);
			int maxVal(INT_MIN);
			while(q.front() != nullptr){
				TreeNode* curr(q.front());
				maxVal = max(maxVal, curr -> val);
				if(curr -> left)
					q.push(curr -> left);
				if(curr -> right)
					q.push(curr -> right);
				q.pop();
			}
			q.pop();
			res.push_back(maxVal);
		}
		return res;
    }
};

//C++ DFS solution
class Solution {
    vector<int> solution;
public:
    void helper(TreeNode* node, int cl) {
        if (node == NULL) {
            return;
        }
        if (solution.size() < cl + 1) {
            solution.push_back(node->val);
        } else {
            if (solution[cl] < node->val) {
                solution[cl] = node->val;
            }
        }
        helper(node->left, cl+1);
        helper(node->right, cl+1);
    }
    //vector<int> largestValues(TreeNode* root) {
    vector<int> findValueMostElement(TreeNode* root) {
        if(root == NULL) {
            return solution;
        }
        
        helper(root, 0);
        return solution;
    }
};

//A good java solution + DFS
public class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        helper(root, res, 0);
        return res;
    }
    private void helper(TreeNode root, List<Integer> res, int d){
        if(root == null){
            return;
        }
       //expand list size
        if(d == res.size()){
            res.add(root.val);
        }
        else{
        //or set value
            res.set(d, Math.max(res.get(d), root.val));
        }
        helper(root.left, res, d+1);
        helper(root.right, res, d+1);
    }
}

//Java + BFS
  public int[] findValueMostElement(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<Integer> res = new ArrayList<Integer>();
        queue.add(root);
        int queueSize = root == null ? 0 : 1;
        while (queueSize > 0) {
            int largestElement = Integer.MIN_VALUE;
            for (int i=0;i<queueSize;i++) {
                TreeNode cur = queue.poll();
                largestElement = Math.max(cur.val, largestElement);
                if (cur.left != null) queue.add(cur.left);
                if (cur.right != null) queue.add(cur.right);
            }
            res.add(largestElement);
            queueSize = queue.size();
        }
        int[] resArray = new int[res.size()];
        for (int i=0;i<res.size();i++) resArray[i] = res.get(i);
        return resArray;
    }