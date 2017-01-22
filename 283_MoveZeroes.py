# 73.41
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        left = right = 0
        while right < len(nums):
            if nums[right] != 0:
                if left != right:
                    nums[right], nums[left] = nums[left], nums[right]
                left += 1
            right += 1