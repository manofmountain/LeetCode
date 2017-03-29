##39.92%
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return
        strList = s.lstrip().rstrip().split(' ')
        return ' '.join([str for str in strList[::-1] if str])