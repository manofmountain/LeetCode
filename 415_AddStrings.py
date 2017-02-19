# 27.37%
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        l1, l2 = map(int, num1), map(int, num2)
        len1, len2 = len(l1), len(l2)
        if len1 > len2:
            l2 = [0] * (len1 - len2) + l2
        else:
            l1 = [0] * (len2 - len1) + l1
        res = list()
        remain = 0
        for n1, n2 in zip(l1[::-1], l2[::-1]):
            num = (n1 + n2 + remain)
            res.insert(0, str(num % 10))
            remain = num / 10
        if remain == 1:
            res.insert(0, '1')
        return ''.join(res)
		
def addStrings(self, num1, num2):
    z = itertools.izip_longest(num1[::-1], num2[::-1], fillvalue='0')
    res, carry, zero2 = [], 0, 2*ord('0')
    for i in z:
        cur_sum = ord(i[0]) + ord(i[1]) - zero2 + carry
        res.append(str(cur_sum % 10))
        carry = cur_sum // 10
    return ('1' if carry else '') + ''.join(res[::-1])
	
from itertools import izip_longest
class Solution(object):
    def addStrings(self, num1, num2):
        res, c = "", 0
        for (x, y) in izip_longest(num1[::-1], num2[::-1], fillvalue='0'):
            s = (int(x) + int(y) + c)
            d, c = s % 10, int(s / 10)
            res = str(d) + res
        
        if c > 0: res = str(c) + res

        return res