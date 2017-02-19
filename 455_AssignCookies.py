class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        res, i, size = 0, 0, len(s)
        g.sort()
        s.sort()
        for greed in g:
            while i < size:
                if s[i] >= greed:
                    res += 1
                    i += 1
                    break
                i += 1
            if i >= size:
                break
        return res               