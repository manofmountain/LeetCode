//25.09%
//Recursive solution, DP
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
		if(sumTable.find(target) != sumTable.end())
			return sumTable[target];
		int sum(0);
		for(int i = 0; i < nums.size(); ++i){
			if(target > nums[i]){
				if(sumTable.find(target - nums[i]) == sumTable.end())
					sumTable.insert(make_pair(target - nums[i], combinationSum4(nums, target - nums[i])));
				sum += sumTable[target - nums[i]];
			}else if(target == nums[i])
				sum += 1;
		}
		return sum;
    }
private:
	unordered_map<int, int> sumTable;
};

//C++ solution with optimal DP
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};

//Java recursive solution
public int combinationSum4(int[] nums, int target) {
    if (target == 0) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < nums.length; i++) {
        if (target >= nums[i]) {
            res += combinationSum4(nums, target - nums[i]);
        }
    }
    return res;
}

//Java DP solution
private int[] dp;

public int combinationSum4(int[] nums, int target) {
    dp = new int[target + 1];
    Arrays.fill(dp, -1);
    dp[0] = 1;
    return helper(nums, target);
}

private int helper(int[] nums, int target) {
    if (dp[target] != -1) {
        return dp[target];
    }
    int res = 0;
    for (int i = 0; i < nums.length; i++) {
        if (target >= nums[i]) {
            res += helper(nums, target - nums[i]);
        }
    }
    dp[target] = res;
    return res;
}

//Another DP form (this's the solution i wanted)
public int combinationSum4(int[] nums, int target) {
    int[] comb = new int[target + 1];
    comb[0] = 1;
    for (int i = 1; i < comb.length; i++) {
        for (int j = 0; j < nums.length; j++) {
            if (i - nums[j] >= 0) {
                comb[i] += comb[i - nums[j]];
            }
        }
    }
    return comb[target];
}