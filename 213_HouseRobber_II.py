class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def robHelper(start, right):
            pre, curr = 0, 0
            for i in xrange(start, right):
                temp = max(nums[i] + pre, curr)
                pre, curr = curr, temp
			return curr
        if not nums: return 0
        if len(nums) == 1: return nums[0]
        return max(robHelper(0, len(nums) - 1), robHelper(1, len(nums)))