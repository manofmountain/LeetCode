##90.83%
class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        if not s or k <= 0:
            return s
        start, step = 0, k * 2
        s = list(s)
        while start < len(s):
            end = start + k if start + k < len(s) else len(s)
            s[start:end] = s[start:end][::-1]
            start += step
        return "".join(s)

##97.9%		
class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        return s[:k][::-1] + s[k:2*k] + self.reverseStr(s[2*k:], k) if s else ""