//92.23%
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
        for(int i = 1; i <= nums.size(); i++){
			while(nums[i - 1] != i && nums[nums[i - 1] - 1] != nums[i - 1]){
				swap(nums[i - 1], nums[nums[i - 1] - 1]);
			}
		}
		for(int i = 1; i <= nums.size(); i++)
			if(nums[i - 1] != i)
				res.push_back(i);
		return res;	
    }
};