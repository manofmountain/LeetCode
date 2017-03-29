###51.7%
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        maxP = 0
        i, size = 1, len(prices)
        while i != size:
            curr = prices[i] - prices[i - 1]
            if curr > 0:
                maxP += curr
            i += 1
        return maxP

##A good solution from LeetCode		
class Solution(object):
    def maxProfit(self, prices):
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(len(prices) - 1))