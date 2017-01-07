#Method from others : https://discuss.leetcode.com/topic/6308/simple-python-solution/2
#13.88%
class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
            
        for i, letter_group in enumerate(zip(*strs)):
            if len(set(letter_group)) > 1:
                return strs[0][:i]
        else:
            return min(strs)

#Another method from others: https://discuss.leetcode.com/topic/6308/simple-python-solution/2
#57.73%
class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        def lcp(s, t):
            if len(s)>len(t):
                s, t = t, s
            for i in range(len(s)):
                if s[i]!=t[i]:
                    return s[:i]
            return s
        return reduce(lcp,strs) if strs else ""

#26.99% (my method. a shame to python. ^_^)
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        
        flag = True
		pos = 0
        for charFirst in strs[0]:
            for str in strs[1:]:
                if len(str) <= pos or str[pos] != charFirst:
                    flag = False
                    break
            if not flag:
                break
            pos = pos + 1
        
        return strs[0][:pos]