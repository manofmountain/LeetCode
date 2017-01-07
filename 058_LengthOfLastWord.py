
#47.76%
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        strList = s.lstrip().strip().split(' ')
        return 0 if len(strList) == 0 else len(strList[-1])
		#Or just
		#return len(s.lstrip().strip().split(' ')[-1])