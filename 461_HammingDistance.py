class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        res, num = 0, x ^ y
        while num != 0:
            res += 1
            num &= (num - 1)
        return res

###This way is more Python than Mine		
class Solution(object):
def hammingDistance(self, x, y):
"""
:type x: int
:type y: int
:rtype: int
"""
return bin(x^y).count('1')