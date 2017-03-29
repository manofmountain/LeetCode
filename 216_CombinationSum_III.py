###85.62%
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def combinationHelper(start, n):
            if start == k and n == 0:
                res.append(vec[:])
                return
            if not vec:
                i = 1
            else:
                i = vec[-1] + 1
            while i <= 9:
                if n - i < 0:
                    return
                vec.append(i)
                combinationHelper(start + 1, n - i)
                vec.pop()
                i += 1
        
        res, vec = list(), list()
        combinationHelper(0, n)
        return res