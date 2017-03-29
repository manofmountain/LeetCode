//58.17%
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size(nums.size());
		for(int i = 0; i < size; ++i){
			while(nums[i] != i + 1){
				if(nums[nums[i] - 1] == nums[i])
					return nums[i];
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		return nums[size - 1];
    }
};

//Wonderful solution which didn't change input variable parameters
int findDuplicate3(vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
}

class Solution {
public:
int findDuplicate(vector<int>& nums) {
    int slow = 0;
	int fast = 0;
	int finder = 0;

	while (true)
	{
		slow = nums[slow];
		fast = nums[nums[fast]];

		if (slow == fast)
			break;
	}
	while (true)
	{
		slow = nums[slow];
		finder = nums[finder];
		if (slow == finder)
			return slow;
	}
}