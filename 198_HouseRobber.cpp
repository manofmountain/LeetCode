class Solution {
public:
    int rob(vector<int>& nums) {
        if(0 == nums.size())
			return 0;
		if(1 == nums.size())
			return nums[0];
		int s0(nums[0]), s1(nums[1] > nums[0] ? nums[1] : nums[0]);
		for(int i = 2; i < nums.size(); i++){
			int temp = nums[i] + s0 > s1 ? nums[i] + s0 : s1;
			s0 = s1;
			s1 = temp;
		}
		return s1;
    }
};