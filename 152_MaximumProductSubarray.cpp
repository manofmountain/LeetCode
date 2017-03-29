//A clearly DP programme
int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}

//14.05%
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
			return 0;
		int r(nums[0]);
		for(int i = 1, iMax = r, iMin = r; i < nums.size(); ++i){
			if(nums[i] < 0)
				swap(iMax, iMin);
			iMax = max(nums[i], nums[i] * iMax);
			iMin = min(nums[i], nums[i] * iMin);
			r = max(iMax, r);
		}
		return r;
    }
};

//Another good solution from LeetCode
class Solution {
 // author : s2003zy
 // weibo : http://weibo.com/574433433
 // blog : http://s2003zy.com
 // Time : O(n)
 // Space : O(1)
 public:
    int maxProduct(int A[], int n) {
    	int frontProduct = 1;
    	int backProduct = 1;
  		int ans = INT_MIN;
  		for (int i = 0; i < n; ++i) {
  			frontProduct *= A[i];
  			backProduct *= A[n - i - 1];
  			ans = max(ans,max(frontProduct,backProduct));
  		    frontProduct = frontProduct == 0 ? 1 : frontProduct;
  		    backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};