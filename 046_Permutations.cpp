//43.5%
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
		if(nums.empty()) return res;
		int size(nums.size());
		vector<int> vec(size, 0);
		permuteHelper(nums, 0, size, res, vec);
		return res;
	}
private:
	void permuteHelper(vector<int>& nums, int left, int right, vector<vector<int>>& res, vector<int>& vec){
		if(left == right){
			res.push_back(vec);
			return;
		}
			
		for(int i = left; i < right; i++){
			swap(nums[i], nums[left]);
			vec[left] = nums[left];
			permuteHelper(nums, left + 1, right, res, vec);
			swap(nums[i], nums[left]);
		}
    }
};

//Why we still need the redundant 'vec'.. this one is better than mine
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};