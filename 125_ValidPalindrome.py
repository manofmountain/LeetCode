# 7.39%
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if l < r:
                if s[l].isalpha() and s[r].isalpha:
                    if s[l].lower() != s[r].lower():
                        return False
                elif s[l] != s[r]:
                    return False
            l += 1
            r -= 1
        return True