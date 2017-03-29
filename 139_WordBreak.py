###28.97%
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        size = len(s)
        flag = [False] * (size + 1)
        flag[0] = True
        
        wordMap = set(wordDict)
        for i in xrange(1, size + 1):
            for j in xrange(i):
                if flag[j] and s[j:i] in wordMap:
                    flag[i] = True
                    break
        return flag[size]
        