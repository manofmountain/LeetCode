class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = len(nums)
        sumNums = reduce(lambda x, y : x + y, nums)
        return (s + 1) * s / 2 - sumNums

#Need to be familar with Python's standard functions		
def missingNumber(self, nums):
    n = len(nums)
    return n * (n+1) / 2 - sum(nums)