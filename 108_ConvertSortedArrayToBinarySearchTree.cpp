//40.89%
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
private:
	TreeNode *sortedArrayToBSTHelper(const vector<int>& nums, int left, int right){
		if(left > right)
			return NULL;
		if(left == right)
			return new TreeNode(nums[left]);
		int mid = (left + right) / 2;
		TreeNode *root(new TreeNode(nums[mid]));
		root -> left = sortedArrayToBSTHelper(nums, left, mid - 1);
		root -> right = sortedArrayToBSTHelper(nums, mid + 1, right);
		return root;
	}
};


//A java iterative solution
public class Solution {
    
    public TreeNode sortedArrayToBST(int[] nums) {
        
        int len = nums.length;
        if ( len == 0 ) { return null; }
        
        // 0 as a placeholder
        TreeNode head = new TreeNode(0); 
        
        Deque<TreeNode> nodeStack       = new LinkedList<TreeNode>() {{ push(head);  }};
        Deque<Integer>  leftIndexStack  = new LinkedList<Integer>()  {{ push(0);     }};
        Deque<Integer>  rightIndexStack = new LinkedList<Integer>()  {{ push(len-1); }};
        
        while ( !nodeStack.isEmpty() ) {
            TreeNode currNode = nodeStack.pop();
            int left  = leftIndexStack.pop();
            int right = rightIndexStack.pop();
            int mid   = left + (right-left)/2; // avoid overflow
            currNode.val = nums[mid];
            if ( left <= mid-1 ) {
                currNode.left = new TreeNode(0);  
                nodeStack.push(currNode.left);
                leftIndexStack.push(left);
                rightIndexStack.push(mid-1);
            }
            if ( mid+1 <= right ) {
                currNode.right = new TreeNode(0);
                nodeStack.push(currNode.right);
                leftIndexStack.push(mid+1);
                rightIndexStack.push(right);
            }
        }
        return head;
    }

}




