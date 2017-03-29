#14.93%
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def combineHelper(left, right, k):
            if k == 0:
                res.append(vecK[:])
                return
            for i in xrange(left, right):
                vecK[k - 1] = vecN[i]
                combineHelper(i + 1, right, k - 1)
        vecN = range(1, n + 1)
        vecK = [0] * k
        res = list()
        combineHelper(0, n, k) 
        return res

#Use the library		
from itertools import combinations

class Solution:
    def combine(self, n, k):
        return list(combinations(range(1, n+1), k))

# This is the one i truly want		
class Solution:
    def combine(self, n, k):
        if k == 0:
            return \[\[\]\]
        return [pre + [i] for i in range(1, n+1) for pre in self.combine(i-1, k-1)]
		
		
class Solution:
    def combine(self, n, k):
        combs = \[\[\]\]
        for _ in range(k):
            combs = [[i] + c for c in combs for i in range(1, c[0] if c else n+1)]
        return combs
		
class Solution:
  def combine(self, n, k):
    return reduce(lambda C, _: [[i]+c for c in C for i in range(1, c[0] if c else n+1)],
                  range(k), \[\[\]\])