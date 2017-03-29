###62.63%
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        total, remainSum, start = 0, 0, 0
        i = 0
        while i < len(gas):
            remainSum += (gas[i] - cost[i])
            if remainSum < 0:
                total += remainSum
                start = i + 1
                remainSum = 0
            i += 1
        return start if (total + remainSum) >= 0 else -1