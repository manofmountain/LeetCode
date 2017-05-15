class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        curr, res = 0, 0
        for i in xrange(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                curr += 1
                res += curr
            else:
                curr = 0
        return res