//32.96%
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
		if(n <= 0)
			return res;
		generateTreesHelper(res, 1, n);
		return res;
    }
private:
	void generateTreesHelper(vector<TreeNode*>& res, int start, int end){
		if(start > end){
			res.push_back(NULL);
			return;
		}
		if(start == end){
			res.push_back(new TreeNode(start));
			return;
		}
		for(int rootVal = start; rootVal <= end; ++rootVal){
			vector<TreeNode *> resLeft, resRight;
			generateTreesHelper(resLeft, start, rootVal - 1);
			generateTreesHelper(resRight, rootVal + 1, end);
			for(auto& leftNode : resLeft){
				for(auto& rightNode : resRight){
					TreeNode *root(new TreeNode(rootVal));
					root -> left = leftNode;
					root -> right = rightNode;
					res.push_back(root);
				}
			}
		}
	}
};


//A DP solution which is really a good one
class Solution {
    public:
        TreeNode* clone(TreeNode* root){
            if(root == nullptr)
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }
        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> res(1,nullptr);
            for(int i = 1; i <= n; i++){
                vector<TreeNode *> tmp;
                for(int j = 0; j<res.size();j++){
                    TreeNode* oldroot = res[j];
                    TreeNode* root = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    root->left = target;
                    tmp.push_back(root);
                   
                    if(oldroot!=nullptr){
                        TreeNode* tmpold = oldroot;
                        while(tmpold->right!=nullptr){
                            TreeNode* nonroot = new TreeNode(i);
                            TreeNode *tright = tmpold->right;
                            tmpold->right = nonroot;
                            nonroot->left = tright;
                            TreeNode *target = clone(oldroot);
                            tmp.push_back(target);
                            tmpold->right = tright;
                            tmpold = tmpold->right;
                        }
                        tmpold->right = new TreeNode(i);
                        TreeNode *target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = nullptr;
                    }
                }
                res=tmp;
            }
            return res;
        }
    };