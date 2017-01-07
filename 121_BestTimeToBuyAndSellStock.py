# 22.76%
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        diffPrices = map(lambda x, y: x - y, prices[1:], prices[:-1])
        maxCurr = 0
        maxAll = 0
        for diffPrice in diffPrices:
            maxCurr = max(0, maxCurr + diffPrice)
            maxAll = max(maxCurr, maxAll)
        return maxAll