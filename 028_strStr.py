# 79.18%
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        lenH = len(haystack)
        lenN = len(needle)
        if lenN == 0:
            return 0
        if lenH < lenN:
            return -1
        if lenH == lenN:
            if haystack == needle:
                return 0
            else:
                return -1
        for i in range(lenH - lenN + 1):
            if haystack[i: i + lenN] == needle:
                return i
        
        return -1