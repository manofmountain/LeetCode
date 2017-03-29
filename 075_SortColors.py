class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        left, right = 0, size - 1
        #First round, puts all '0' to left side
        while left < right:
            if nums[left] == 0:
                left += 1
            elif nums[right] != 0:
                right -= 1
            else:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        
        if nums[left] == 0:
            left += 1
        right = size - 1
        #Second round, separate all '1's and '2's
        while left < right:
            if nums[left] == 1:
                left += 1
            elif nums[right] != 1:
                right -= 1
            else:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1