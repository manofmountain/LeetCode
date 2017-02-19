#9.13%
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        size = len(nums)
        low, high = 0, size - 1
        while low < high:
            mid = (low + high) / 2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        pos = low
        low, high = 0, size - 1
        while low <= high:
            mid = (low + high) / 2
            realMid = (mid + pos) % size
            if nums[realMid] > target:
                high = mid - 1
            elif nums[realMid] < target:
                low = mid + 1
            else:
                return realMid
        return -1