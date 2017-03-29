#23.98%
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
		//Default, we can have '[]' included anytime
		vector<int> vec;
		res.push_back(vec);
		if(nums.empty())
			return res;
		
		int size(nums.size());
		for(int k = size; k > 0; k--){
			//all vectors having size as 'k'
			vector<int> vecK(k, 0);
			subsetsHelper(res, nums, vecK, 0, size, k);
		}
		return res;
    }
private:
	void subsetsHelper(vector<vector<int>>& res, vector<int>& nums, vector<int>&vec, int left, int right, int k){
		if(k == 0){
			res.push_back(vec);
			return;
		}
		
		for(int i = left; i < right; i++){
			vec[k - 1] = nums[i];
			subsetsHelper(res, nums, vec, i + 1, right, k - 1);
		}
	}
};


//A solution from LeetCode using bit manipulation
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};

//The typical back-tracing solutions
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;  
        genSubsets(nums, 0, sub, subs);
        return subs; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};


/*
Initially: \[\[\]\]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};