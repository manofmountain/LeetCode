class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def search(left, right):
            while left < right:
                mid = (left + right) / 2
                if nums[mid] < target:
                    left = mid + 1
                elif nums[mid] > target:
                    right = mid
                else:
                    return mid
            return left
        if nums[0]<= target <= nums[-1]:
            return search(0, len(nums) - 1)
        return 0 if target < nums[0] else len(nums)
        
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return bisect.bisect_left(nums, target)
        

