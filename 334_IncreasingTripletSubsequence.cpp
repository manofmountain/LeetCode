//35.2%
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
			return false;
		int s1(INT_MAX), s2(INT_MAX);
		for(int num : nums){
			if(num <= s1){	
				s1 = num;
			}else if(num <= s2)
				s2 = num;
			else
				return true;
		}
		return false;
    }
};