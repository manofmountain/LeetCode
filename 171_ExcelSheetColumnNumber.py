class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        for str in s:
            res = res * 26 + int(ord(str) - ord('A')) + 1
        return res

# Better solution than mine which use 'reduce' here
return reduce(lambda x, y : x * 26 + y, [ord(c) - 64 for c in list(s)])