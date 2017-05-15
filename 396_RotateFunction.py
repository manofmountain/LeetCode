##76.5%
class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) <= 1:
            return 0
        if len(A) == 2:
            return max(A)
        
        res, subRes, sumAll = 0, 0, 0
        for i, val in enumerate(A):
            subRes += i * val
            sumAll += val
        res = subRes
        for val in A[:0:-1]:
            subRes += (sumAll - len(A) * val)
            res = max(res, subRes)
        return res
            