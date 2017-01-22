class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left(0), right(0);
		while(right < nums.size()){
			if(!nums[right])
				right++;
			else{
				if(left != right){
					nums[left] = nums[right];
					nums[right] = 0;
				}
				left++;
				right++;
			}
		}
    }
};

void moveZeroes(vector<int>& nums) {
    int last = 0, cur = 0;
    
    while(cur < nums.size()) {
        if(nums[cur] != 0) {
            swap(nums[last], nums[cur]);
            last++;
        }
        
        cur++;
    }
}

//A simple solution from LeetCode
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};