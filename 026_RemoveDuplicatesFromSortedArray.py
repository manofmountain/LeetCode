class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size =  len(nums)
        if size <= 1:
            return size
        
        val = nums[0]
        size = 0
        for num in nums[1:]:
            if num > nums[size]:
                size, nums[size] = size + 1, num
        
        return size + 1
            