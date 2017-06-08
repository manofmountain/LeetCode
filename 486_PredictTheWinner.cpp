public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return helper(nums, 0, nums.length-1)>=0;
    }
    private int helper(int[] nums, int s, int e){        
        return s==e ? nums[e] : Math.max(nums[e] - helper(nums, s, e-1), nums[s] - helper(nums, s+1, e));
    }
}

public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return helper(nums, 0, nums.length-1, new Integer[nums.length][nums.length])>=0;
    }
    private int helper(int[] nums, int s, int e, Integer[][] mem){    
        if(mem[s][e]==null)
            mem[s][e] = s==e ? nums[e] : Math.max(nums[e]-helper(nums,s,e-1,mem),nums[s]-helper(nums,s+1,e,mem));
        return mem[s][e];
    }
}

//DP O(n^2)
public boolean PredictTheWinner(int[] nums) {
    int n = nums.length;
    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) { dp[i][i] = nums[i]; }
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}


//Space O(n)
public boolean PredictTheWinner(int[] nums) {
    if (nums == null) { return true; }
    int n = nums.length;
    if ((n & 1) == 0) { return true; } // Improved with hot13399's comment.
    int[] dp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i] = nums[i];
            } else {
                dp[j] = Math.max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
    }
    return dp[n - 1] >= 0;
}

//25.46%
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() <= 2)
			return true;
		unordered_map<int, int> historyTable;
		return predictTheWinnerHelper(nums, 0, nums.size() - 1, historyTable) >= 0;
    }
private:
	int predictTheWinnerHelper(const vector<int>& nums, int left, int right, unordered_map<int, int>& historyTable){
		int pos(left | (right << 5));
		if(historyTable.find(pos) != historyTable.end())
			return historyTable[pos];
		int sumScore(left == right ? nums[left] : max(nums[left] - predictTheWinnerHelper(nums, left + 1, right, historyTable), nums[right] - predictTheWinnerHelper(nums, left, right - 1, historyTable)));
		historyTable.insert(make_pair(pos, sumScore));
		return sumScore;
	}
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
            }
        }
        return dp[0][n-1] >= 0; // player1 get more score points than player2
    }
};