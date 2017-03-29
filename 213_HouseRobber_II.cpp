//4.65%
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
			return 0;
		if(nums.size() <= 3){
			int temp(nums[0]);
			for(int i = 1; i < nums.size(); ++i)
				temp = temp < nums[i] ? nums[i] : temp;
			return temp;
		}
		int gMax(-1);
		for(int start = 0; start < nums.size(); ++start){
			gMax = max(gMax, robHelper(nums, start, nums.size()));
		}
		return gMax;
	}
private:
	int robHelper(const vector<int>& nums, int start, int size){
		int s0(nums[start]), s1(nums[start]);
		for(int i = (start + 2) % size; i != (start - 1 + size) % size; i = (i + 1) % size){
			int temp(nums[i] + s0 > s1 ? nums[i] + s0 : s1);
			s0 = s1;
			s1 = temp;
		}
		return s1;
	}
};

//This solution from LeetCode seems to have real sense.
/*
This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

Rob houses 0 to n - 2;
Rob houses 1 to n - 1.
The code is as follows. Some edge cases (n < 2) are handled explicitly.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};