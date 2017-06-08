class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        pattern = 'zabcdefghijklmnopqrstuvwxyz'
        cmap = collections.defaultdict(int)
        start = end = 0
        for c in range(len(p)):
            if c and p[c-1:c+1] not in pattern:
                for x in range(start, end):
                    cmap[p[x]] = max(end - x, cmap[p[x]])
                start = c
            end = c + 1
        for x in range(start, end):
            cmap[p[x]] = max(end - x, cmap[p[x]])
        return sum(cmap.values())
		
		
class Solution(object):
    def findSubstringInWraproundString(self, p):
        p, d, lo = '0'+p, collections.defaultdict(int), 0
        for hi in range(1, len(p)):
            if p[hi-1]+p[hi] not in 'abcdefghijklmnopqrstuvwxyza':
                lo = hi
            d[p[hi]] = max(d[p[hi]], hi+1-lo)
        return sum(d.values())