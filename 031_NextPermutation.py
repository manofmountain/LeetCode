#1.92%
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        start = size - 1
        while start > 0 and nums[start - 1] >= nums[start]:
            start -= 1
        if start == 0:
            nums.reverse()
        else:
            pos = size - 1
            while nums[pos] <= nums[start - 1]:
                pos -= 1
            nums[pos], nums[start - 1] = nums[start - 1], nums[pos]
            left, right = start, size - 1
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1