//48.13%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return -1;
		int size(nums.size());
		int maxSum(nums[0]), currSum(nums[0]);
		for(int i = 1; i < size; i++){
			if(nums[i] < 0){
				maxSum = max(maxSum, currSum);
				if(currSum + nums[i] < 0){
					if(currSum >= 0)
						currSum += nums[i];
					else
						currSum = nums[i];
				}else
					currSum += nums[i];
			}else{
				if(currSum < 0)
					currSum = nums[i];
				else
					currSum += nums[i];
			}
		}
		return max(maxSum, currSum);
    }
};

//6.88%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return -1;
		int size(nums.size());
		int maxSum(nums[0]), currSum(nums[0]);
		for(int i = 1; i < size; i++){
			if(currSum < 0)
				currSum = nums[i];
			else
				currSum += nums[i];
			maxSum = max(maxSum, currSum);
		}
		return max(maxSum, currSum);
    }
};

/*
Idea is very simple. Basically, keep adding each integer to the sequence until the sum drops below 0.
If sum is negative, then should reset the sequence.
*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans=A[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};