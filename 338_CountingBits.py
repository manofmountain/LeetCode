##29.55%
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if 0 == num:
            return [0]
        res = [0] * (num + 1)
        for i in xrange(1, num + 1):
            l = i
            while l != 0:
                res[i] += 1
                l &= (l - 1)
        return res