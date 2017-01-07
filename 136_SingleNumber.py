# 12.76%
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        recordDict = {}
        for num in nums:
            if num in recordDict:
                recordDict.pop(num)
            else:
                recordDict[num] = 0
        return recordDict.keys()[0]
		
def singleNumber2(self, nums):
    res = 0
    for num in nums:
        res ^= num
    return res
	
def singleNumber3(self, nums):
    return 2*sum(set(nums))-sum(nums)
    
def singleNumber4(self, nums):
    return reduce(lambda x, y: x ^ y, nums)
    
def singleNumber(self, nums):
    return reduce(operator.xor, nums)