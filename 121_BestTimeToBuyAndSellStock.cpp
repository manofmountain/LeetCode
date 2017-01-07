class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxAll = 0;
		int maxCurr = 0;
		for(int i = 1; i < prices.size(); i++){
			maxCurr = max(0, maxCurr + prices[i] - prices[i - 1]);
			maxAll = max(maxCurr, maxAll);
		}
		return maxAll;
    }
};