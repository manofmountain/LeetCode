#49.6%
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = list()
        size = len(s)
        for a in xrange(1, 4):
            for b in xrange(1, 4):
                for c in xrange(1, 4):
                    for d in xrange(1, 4):
                        if a + b + c + d == size:
                            A, B, C, D = map(int, [s[:a], s[a: a + b], s[a + b: a + b + c], s[a + b + c : size]])
                            if A <= 255 and B <= 255 and C <= 255 and D <= 255:
                                target = '.'.join(list(map(str, [A, B, C, D])))
                                if len(target) == size + 3:
                                    res.append(target)
        return res
                            