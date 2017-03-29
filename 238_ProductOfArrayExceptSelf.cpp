//16.1%
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty())
			return {};
		vector<int> res(nums.size(), 1);
		for(int i = 1; i < nums.size(); ++i){
			res[i] = res[i - 1] * nums[i - 1];
		}
		int right(1);
		for(int i = nums.size() - 2; i >= 0; --i){
			right *= nums[i + 1];
			res[i] *= right;
		}
		return res;
    }
};

//A solution from LeetCode which only needs 1 loop
//72.88% which only need 1 loop-- great solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i];
        }
        return res;
    }
};