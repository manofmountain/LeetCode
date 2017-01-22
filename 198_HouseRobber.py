# 20.74%
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        s0, s1 = nums[0], nums[1] if nums[1] > nums[0] else nums[0]
        for num in nums[2:]:
            temp = num + s0 if num + s0 > s1 else s1
            s0, s1 = s1, temp
        return s1
		
class Solution:
    
    def rob(self, nums):
        
        last, now = 0, 0
        
        for i in nums: last, now = now, max(last + i, now)
                
        return now