//50.66%
//A DP problems
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
			return 0;
		int res(nums.size() + 1), start(0), past(0);
		for(int i = 0; i < nums.size(); ++i){
			past += nums[i];
			if(past >= s){
				while(past - nums[start] >= s)
					past -= nums[start++];
				res = min(res, i - start + 1);
				past -= nums[start++];
			}
		}
		if(res == nums.size() + 1)
			return 0;
		return res;
    }
};