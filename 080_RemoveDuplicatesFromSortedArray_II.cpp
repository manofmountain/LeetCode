//15.81%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len(0), count(1);
		if(nums.empty())
			return len;
		len++;
		int pre(nums[0]);
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] == pre){
				if(count < 2){
					nums[len++] = nums[i];
					count++;
				}
			}else{
				pre = nums[i];
				count = 1;
				nums[len++] = nums[i];
			}
		}
		return len;
    }
};

//61.37%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len(0);
		bool repeated(false);
		if(nums.empty())
			return len;
		len++;
		int pre(nums[0]);
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] == pre){
				if(!repeated){
					nums[len++] = nums[i];
					repeated = true;
				}
			}else{
				pre = nums[i];
				repeated = false;
				nums[len++] = nums[i];
			}
		}
		return len;
    }
};

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}