#54.86%
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        array = [[0 for _ in xrange(n)]] * m
        for i in xrange(m):
            array[i][n - 1] = 1
        for j in xrange(n):
            array[m - 1][j] = 1
        for i in range(m - 1)[::-1]:
            for j in range(n - 1)[::-1]:
                array[i][j] = array[i + 1][j] + array[i][j + 1]
        return array[0][0]