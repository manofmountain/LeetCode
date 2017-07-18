##73.93%
class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if mid < right and nums[mid] == nums[mid + 1]:
                mid += 1
            elif mid <= left or nums[mid] != nums[mid - 1]:
                return nums[mid]
            if mid & 1:
                left = mid + 1
            else:
                right = mid - 2
        return nums[left]
		
def singleNonDuplicate(self, nums):
    lo, hi = 0, len(nums) - 1
    while lo < hi:
        mid = (lo + hi) / 2
        if nums[mid] == nums[mid ^ 1]:
            lo = mid + 1
        else:
            hi = mid
    return nums[lo]