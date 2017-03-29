class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size(nums.size());
		if(1 >= size)
			return true;
		int i = size - 2;
		while(i > 0){
			if(nums[i] + i >= size - 1)
				size = i + 1;
			i--;
		}
		return nums[0] >= size - 1;		
    }
};