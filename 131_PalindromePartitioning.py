##73.75%
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def isPalindrome(left, right):
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True
        
        def partitionHelper(left, right):
            if left >= right:
                res.append(vec[:])
            for i in xrange(left, right):
                if isPalindrome(left, i):
                    vec.append(s[left : i + 1])
                    partitionHelper(i + 1, right)
                    vec.pop()
        
        if not s:
            return list()
        if len(s) == 1:
            return [[s]]
        res = list()
        vec = []
        partitionHelper(0, len(s))
        return res