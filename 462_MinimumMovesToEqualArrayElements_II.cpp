//30.25%
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <= 1)
			return 0;
		
		sort(nums.begin(), nums.end());
		int res(0);
		for(int i = 0, j = nums.size() - 1; i < j; ++i, --j){
			res += nums[j] - nums[i];
		}
		return res;
    }
};

//96.43%
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <= 1)
			return 0;
		nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
		int res(0);
		for(int i = 0, j = nums.size() - 1; i < j; ++i, --j){
			res += nums[j] - nums[i];
		}
		return res;
    }
};