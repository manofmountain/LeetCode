//27.38%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size(nums.size());
		
		//Find start number need to be moved forward
		int start(size - 1);
		while(start > 0 && nums[start - 1] >= nums[start]) start--;
		if(start > 0){
			int pos(size - 1);
			while(nums[pos] <= nums[start - 1])
				pos--;
			swap(nums[pos], nums[start - 1]);
			reverse(nums.begin() + start, nums.end());
		}else
			reverse(nums.begin(), nums.end());
    }
};

//They use a 'upper_bound' here which is interesting
class Solution {
public:
    void nextPermutation(vector<int> &num) 
    {
        if (num.empty()) return;
        
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = num.size()-2; i >= 0; --i)
        {
            if (num[i] < num[i+1]) break;
        }
        
        // reverse all the numbers after violated number
        reverse(begin(num)+i+1, end(num));
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(begin(num)+i+1, end(num), num[i]);
        // swap them, done!
        swap(num[i], *itr);
    }
};