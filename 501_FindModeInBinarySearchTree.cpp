class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> result;
        int modeCount = getModeCount(root, map);
        
        for(pair<int,int> p : map) {
            if(p.second == modeCount) {
                result.push_back(p.first);
            }
        }
        
        return result;
        
    }
    
    /**
     * Traverse the tree using depth first search.
     * Return the mode count (i.e. The count of a repeated number that occurs the most.) of the tree.
     */
    int getModeCount(TreeNode* root, unordered_map<int, int> &map) {
        if(root == NULL)
            return 0;
        
        if(map.find(root->val) == map.end()) {
            map.insert(pair<int, int>(root->val, 1));
        }
        else {
            map[root->val]++;
        }
        
        return max(map[root->val], max(getModeCount(root->left, map), getModeCount(root->right, map)));
    }
};


//I can't have it out with O(1) space
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
    vector<int> findMode(TreeNode* root) {
		int num(0);
		vector<int> res;
        findModeHelper(root, res, num);
		return res;
    }
private:
	void findModeHelper(TreeNode *root, vector<int>& res, int &num){
		vector<int> res;
		if(!root){
			num = 0;
			return res;
		}
		if(!root -> left && !root -> right){
			num = 1;
			res.push_back(root -> val);
			return res;
		}
		
		int numL(0), numR(0);
		vector<int> resL, resR;
		if(root -> left){
			findModeHelper(root -> left, resL, numL);
			for(int val : resL){
				if(val == root -> val){
					numL += 1;
					resL.clear();
					resL.push_back(root -> val);
				}
			}
		}
		
		if(root -> right){
			findModeHelper(root -> right, resR, numR);
			for(int val : resR){
				if(val == root -> val){
					numR += 1;
					resR.clear();
					resR.push_back(root -> val);
				}
			}
		}
		
		
		int numRoot = numberOfRootValue(root, root -> val);
		if(numRoot > max(numL, numR)){
			res.push_back(root -> val);
			return res;
		}
	}
			
			
};