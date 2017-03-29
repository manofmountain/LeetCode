##46.65%
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left < right and nums[left] == nums[right]:
            left += 1;
        if left >= right:
            return nums[right]
        
        while left < right:
            if nums[left] <= nums[right]:
                return nums[left]
            mid = left + (right - left) / 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        return nums[right]