# 45.06%
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        num5 = 0
        while n >= 5:
            n /= 5
            num5 += n
        return num5
		
return 0 if n <=5 else n / 5 + self.trailingZeroes(n / 5)