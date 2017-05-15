#54.55%
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        num, base, digits = 9, 1, 1
        while n - num > 0:
            n -= num
            digits += 1
            base *= 10
            num = 9 * base * digits
        
        res = base + (n / digits - 1 if n % digits == 0 else n / digits)
        mark = n % digits
        if mark == 0:
            mark = 0
        else:
            mark = digits - mark
        while mark:
            mark -= 1
            res /= 10
        return res % 10
        
def findNthDigit(self, n):
    n -= 1 #change to '0' base from '1' base
    for digits in range(1, 11):
        first = 10**(digits - 1)
        if n < 9 * first * digits:
            return int(str(first + n/digits)[n%digits])
        n -= 9 * first * digits