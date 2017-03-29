##29.39%
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        r = iMax = iMin = nums[0]
        for num in nums[1:]:
            if num < 0:
                iMax, iMin = iMin, iMax
            iMax, iMin = max(num, num * iMax), min(num, num * iMin)
            r = max(r, iMax)
        return r