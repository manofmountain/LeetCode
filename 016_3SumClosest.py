class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        size, res = len(nums), nums[0] + nums[1] + nums[2]
        nums.sort()
        for first in range(size - 2):
            left, right = first + 1, size - 1
            goal = target - nums[first]
            while left < right:
                if nums[left] + nums[right] > goal:
                    right -= 1
                    if abs(nums[left] + nums[right + 1] + nums[first] - target) < abs(res - target):
                        res = nums[left] + nums[right + 1] + nums[first]
                    while right > left and nums[right] == nums[right + 1]:    right -= 1
                elif nums[left] + nums[right] < goal:
                    left += 1
                    if abs(nums[left - 1] + nums[right] + nums[first] - target) < abs(res - target):
                        res = nums[left - 1] + nums[right] + nums[first]
                    while left < right and nums[left] == nums[left - 1]: left += 1
                else:
                    return target
        return res
                    