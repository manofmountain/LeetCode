class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumNums(accumulate(nums.begin(), nums.end(), 0));
		int size(nums.size());
		return (size + 1) * size / 2 - sumNums;
    }
};


//A good solution from LeetCode by using bit-manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};

//Here use long to prevent 'Integer overflow'
int missingNumber(vector<int>& nums) {
    long n = nums.size();
    return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
}