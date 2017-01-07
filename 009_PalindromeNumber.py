
#60.64%
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x < 10:
            return True
        
        origX = x
        rstX = 0
        while x:
            rstX = rstX * 10 + x % 10
            x = x / 10
        
        if origX == rstX:
            return True
        return False