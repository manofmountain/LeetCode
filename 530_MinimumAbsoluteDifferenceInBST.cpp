//37%
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
    int getMinimumDifference(TreeNode* root) {
        if(!root)
			return 0;
		int minLeft(INT_MAX), minRight(INT_MAX);
		if(root -> left){
			TreeNode* curr(root -> left);
			while(curr -> right) curr = curr -> right;
			minLeft = min(abs(root -> val - curr -> val), getMinimumDifference(root -> left));
		}
		if(root -> right){
			TreeNode *curr(root -> right);
			while(curr -> left) curr = curr -> left;
			minRight = min(abs(root -> val - curr -> val), getMinimumDifference(root -> right));
		}
		return min(minLeft, minRight);
    }
};

//Solution 1 - In-Order traverse, time complexity O(N), space complexity O(1).
public class Solution {
    int min = Integer.MAX_VALUE;
    Integer prev = null;
    
    public int getMinimumDifference(TreeNode root) {
        if (root == null) return min;
        
        getMinimumDifference(root.left);
        
        if (prev != null) {
            min = Math.min(min, root.val - prev);
        }
        prev = root.val;
        
        getMinimumDifference(root.right);
        
        return min;
    }
    
}

//Solution 2 - Pre-Order traverse, time complexity O(NlgN), space complexity O(N).
public class Solution {
    TreeSet<Integer> set = new TreeSet<>();
    int min = Integer.MAX_VALUE;
    
    public int getMinimumDifference(TreeNode root) {
        if (root == null) return min;
        
        if (!set.isEmpty()) {
            if (set.floor(root.val) != null) {
                min = Math.min(min, root.val - set.floor(root.val));
            }
            if (set.ceiling(root.val) != null) {
                min = Math.min(min, set.ceiling(root.val) - root.val);
            }
        }
        
        set.add(root.val);
        
        getMinimumDifference(root.left);
        getMinimumDifference(root.right);
        
        return min;
    }
}

//In-order traversal of BST yields sorted sequence. So, we just need to subtract the previous element from the current one, //and keep track of the minimum. We need O(1) memory as we only store the previous element, but we still need O(h) for the stack.

void inorderTraverse(TreeNode* root, int& val, int& min_dif) {
    if (root->left != NULL) inorderTraverse(root->left, val, min_dif);
    if (val >= 0) min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) inorderTraverse(root->right, val, min_dif);
}
int getMinimumDifference(TreeNode* root) {
    auto min_dif = INT_MAX, val = -1;
    inorderTraverse(root, val, min_dif);
    return min_dif;
}

//Another solution with the member variables (6 lines):
class Solution {
    int min_dif = INT_MAX, val = -1;
public:
int getMinimumDifference(TreeNode* root) {
    if (root->left != NULL) getMinimumDifference(root->left);
    if (val >= 0) min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) getMinimumDifference(root->right);
    return min_dif;
}
};

//Regular Version:
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        long mindiff = INT_MAX;
        TreeNode* prev = nullptr;
        find(root, prev, mindiff);
        return mindiff;
    }
private:
    void find(TreeNode* node, TreeNode*& prev, long& mindiff) {
        if (node->left) { 
            find(node->left, prev, mindiff);
        }

        if (prev != nullptr) {
            mindiff = std::min(mindiff, (long)abs(node->val - prev->val));
        }
        prev = node;

        if (node->right) {
            find(node->right, prev, mindiff);
        }
    }
};

//Lambda Version
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        long mindiff = INT_MAX;
        TreeNode* prev = nullptr;
        find(root, prev, mindiff);
        return mindiff;
    }
private:
    bool find(TreeNode* node, TreeNode*& prev, long& mindiff) {
        return (node->left && find(node->left, prev, mindiff)) | [&]() { mindiff = !prev ? mindiff : std::min(mindiff, (long)abs(node->val - prev->val)); prev = node; return true; }() | (node->right && find(node->right, prev, mindiff));
    }
};