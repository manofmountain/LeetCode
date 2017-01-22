# 17.69%
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        numTable = {}
        for i, num in enumerate(nums):
            if num in numTable:
                if i - numTable[num] <= k:
                    return True
                else:
                    numTable[num] = i
            else:
                numTable[num] = i
        return False
		
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        numTable = {}
        for i, num in enumerate(nums):
            if num in numTable and i - numTable[num] <= k:
                 return True
            numTable[num] = i
        return False