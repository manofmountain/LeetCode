# 22.86%
import collections
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        c = collections.Counter(s)
        res, odd = 0, False
        for _, num in c.items():
            if num % 2 != 0:
                odd = True
                num -= 1
            res += num
        return res if not odd else res + 1
		
def longestPalindrome(self, s):
    odds = sum(v & 1 for v in collections.Counter(s).values())
    return len(s) - odds + bool(odds)

def longestPalindrome(self, s):
    use = sum(v & ~1 for v in collections.Counter(s).values())
    return use + (use < len(s))

def longestPalindrome(self, s):
    counts = collections.Counter(s).values()
    return sum(v & ~1 for v in counts) + any(v & 1 for v in counts)