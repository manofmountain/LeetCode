#13.65%
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        subRes = [0] * n
        subRes[0] = 1
        for i in xrange(2, n + 1):
            for j in xrange(1, i / 2 + 1):
                subRes[i - 1] = max(subRes[i - 1], j * (i - j))
                subRes[i - 1] = max(subRes[i - 1], j * subRes[i - j - 1])
                subRes[i - 1] = max(subRes[i - 1], subRes[j - 1] * (i - j))
                subRes[i - 1] = max(subRes[i - 1], subRes[j - 1] * subRes[i - j - 1])
        return subRes[n - 1]