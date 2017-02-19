# 20.19%
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        res = 0
        for c in s + t:
            res = res ^ ord(c)
        return chr(res)
		
class Solution(object):
    def findTheDifference(self, s, t):
        return chr(reduce(operator.xor, map(ord, s + t)))
		
class Solution(object):
    def findTheDifference(self, s, t):
        return list((collections.Counter(t) - collections.Counter(s)))[0]
		
class Solution(object):
    def findTheDifference(self, s, t):
        s, t = sorted(s), sorted(t)
        return t[-1] if s == t[:-1] else [x[1] for x in zip(s, t) if x[0] != x[1]][0]