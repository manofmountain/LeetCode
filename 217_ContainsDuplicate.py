# 21.21%
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #return len(nums) == len(sets.Set(nums))
		return len(nums) == len(set(nums))