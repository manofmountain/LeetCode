//86.73%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size(nums.size());
		//assert(size >= 3);
		sort(nums.begin(), nums.end());
		int res(nums[0] + nums[1] + nums[2]);
		for(int i = 0; i < size - 2; i++){
			int angle = target - nums[i];
			int left(i + 1);
			int right(size - 1);
			while(left < right){
				if(nums[left] + nums[right] > angle){
					right--;
					if(abs(nums[left] + nums[right + 1] + nums[i] - target) < abs(res - target))
						res = nums[left] + nums[right + 1] + nums[i];
					while(right > left && nums[right] == nums[right + 1]) right--;
				}
				else if(nums[left] + nums[right] < angle){
					left++;
					if(abs(nums[left - 1] + nums[right] + nums[i] - target) < abs(res - target))
						res = nums[left - 1] + nums[right] + nums[i];
					while(left < right && nums[left] == nums[left - 1]) left++;
				}else
					return target;
			}
		}
		return res;	
    }
};