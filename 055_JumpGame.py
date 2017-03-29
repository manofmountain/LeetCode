class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        size = len(nums)
        i = size - 2
        for num in nums[1:-1][::-1]:
            if i + num >= size - 1:
                size = i + 1
            i -= 1
        return nums[0] >= size - 1