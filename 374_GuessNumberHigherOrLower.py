# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):
# 15.78%
class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        i, j = 1, n
        while i <= j:
            mid = (i + j) // 2
            res = guess(mid)
            if res == 0:
                return mid
            elif res > 0:
                i = mid + 1
            else:
                j = mid - 1
        return -1
	
	#A good one from LeetCode
    def guessNumber(self, n):
        lo, hi = 1, n
        while lo < hi:
            mid = (lo + hi) / 2
            lo, hi = ((mid, mid), (mid+1, hi), (lo, mid-1))[guess(mid)]
        return lo

# This is more 'python' from LeetCode		
 def guessNumber(self, n):
        class C: __getitem__ = lambda _, i: -guess(i)
        return bisect.bisect(C(), -1, 1, n)