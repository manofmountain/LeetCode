# 93.68%
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = set()
        while n is not 1:
            if n not in s:
                s.add(n)
                temp = 0
                while n:
                    temp = temp + (n % 10) ** 2
                    n /= 10
                n = temp
            else:
                return False
        return True
		
def isHappy(self, n):
    mem = set()
    while n != 1:
        n = sum([int(i) ** 2 for i in str(n)])
        if n in mem:
            return False
        else:
            mem.add(n)
    else:
        return True
                
            