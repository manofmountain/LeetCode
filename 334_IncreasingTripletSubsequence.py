##37.74%
import sys
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        s1, s2 = nums[0], sys.maxint
        for num in nums:
            if num <= s1:
                s1 = num
            elif num <= s2:
                s2 = num
            else:
                return True
        return False
		
def increasingTriplet(nums):
    first = second = float('inf')
    for n in nums:
        if n <= first:
            first = n
        elif n <= second:
            second = n
        else:
            return True
    return False