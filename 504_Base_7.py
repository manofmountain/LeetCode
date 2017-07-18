##26.34%
class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        temp = num if num > 0 else -num
        res = []
        while temp != 0:
            res.append(chr(ord('0') + temp % 7))
            temp /= 7
        if num < 0: res.append('-')
        return ''.join(res[::-1])
		
def convertTo7(self, num):
    if num < 0: return '-' + self.convertTo7(-num)
    if num < 7: return str(num)
    return self.convertTo7(num // 7) + str(num % 7)
	
def convertTo7(self, num):
    if num == 0: return '0'
    n, res = abs(num), ''
    while n:
      res = str(n % 7) + res
      n //= 7
    return res if num > 0 else '-' + res