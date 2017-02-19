class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(s.split())
        #return len(s.split(' ')) if ' ' * len(s) != s else 0