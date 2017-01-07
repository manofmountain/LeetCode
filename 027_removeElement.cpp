
//A solution from LeetCode
int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for(int i = 0 ; i < nums.size() ; ++i) {
        if(nums[i] == val)
            cnt++;
        else
            nums[i-cnt] = nums[i];
    }
    return nums.size()-cnt;
}

//Can't make this work out
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
			return 0;
		if(nums[nums.size() - 1] == val){
			//nums[0] = nums[nums.size() - 1];
			nums.pop_back();
			return removeElement(nums, val);
		}
		else{
			return 1 + removeElement(temp, val);
    }
};