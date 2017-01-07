
# 2.74%
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        #if len(nums) == 0:
        #    return 0
        cnt = 0
        for i in range(len(nums)):
            if nums[i] == val:
                cnt = cnt + 1
            else:
                nums[i - cnt] = nums[i]
        
        return len(nums) - cnt


#Wrong solution as it can't pass as reference
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        if nums[0] == val:
            nums.remove(val)
            return self.removeElement(nums,val)
        else:
            return 1 + self.removeElement(nums[1:], val)