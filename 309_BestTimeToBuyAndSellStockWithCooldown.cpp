//11.5% --- O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.empty())
			return 0;
		vector<int> profits(prices.size() + 1);
		for(int i = 2; i <= prices.size(); ++i){
			profits[i] = max(profits[i - 1], prices[i - 1] - prices[0]);
			if(prices[i - 1] <= prices[i - 2])
				continue;
			for(int k = 2; k <= i - 1; ++k){
				profits[i] = max(profits[i], prices[i - 1] - prices[k - 1] + profits[k - 2]);
			}
		}
		return profits.back();
    }
};

//Has a states matchine thinking inside
class Solution {
public:
	int maxProfit(vector<int>& prices){
		if (prices.size() <= 1) return 0;
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
		s1[0] = -prices[0];
		s0[0] = 0;
		s2[0] = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);
	}
};

//Such an elegant solutions
int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}