#9.18%
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        if not nums:
            return False
        left, right = 0, len(nums) - 1
        while nums[left] == nums[right] and left < right: right -= 1
        if left == right: return nums[left] == target
        size = right + 1
        
        #Find out the rotating position
        while left < right:
            mid = (left + right) / 2
            if nums[mid] >= nums[0]:
                left = mid + 1
            else:
                right = mid
        rotate = right
        if nums[rotate] > nums[0]:
            rotate = 0
        
        #Try to find if target existed
        low, up = 0, size - 1
        while low <= up:
            mid = (low + up) / 2
            actualMid = (mid + rotate) % size
            if nums[actualMid] > target:
                up = mid - 1
            elif nums[actualMid] < target:
                low = mid + 1
            else:
                return True
        return False