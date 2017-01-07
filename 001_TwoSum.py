
#72.09%
class Solution001(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        rst = []
        numsDict = {}
        index = 0
        for num in nums:
            valSec = target - num
            if valSec in numsDict:
                rst.append(numsDict[valSec])
                rst.append(index)
                break
            else:
                numsDict[num] = index
                index++
        return rst

#95.63
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        rst = []
		if 0 == len(nums):
		    return rst
        numsDict = {}
        index = 0
        for num in nums:
            valSec = target - num
            if valSec in numsDict:
                rst.append(numsDict[valSec])
                rst.append(index)
                break
            else:
                numsDict[num] = index
                index++
        return rst