class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 1:
            return 1
        res = [0] * (n + 1)
        res[0], res[1], res[2] = 1, 1, 2
        for total in xrange(3, n + 1):
            for left in xrange(total):
                res[total] += res[left] * res[total - left - 1]
        return res[n]