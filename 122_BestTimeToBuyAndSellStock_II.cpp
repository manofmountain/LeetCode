//38.83%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.empty())
			return 0;
        int currDiff, maxP(0);
		for(int i = 1; i < prices.size(); ++i){
			currDiff = max(0, prices[i] - prices[i - 1]);
			maxP += max(0, currDiff);
		}
		return maxP;
    }
};