##82.81%
class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == n or m == 0:
            return m
        cnt = 0
        while m != 0 and m != n:
            m >>= 1
            n >>= 1
            cnt += 1
        if m == 0:
            return 0
        else:
            return m << cnt