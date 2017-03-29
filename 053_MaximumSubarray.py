# 76.39%
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return -1
        maxSum = currSum = nums[0]
        for num in nums[1:]:
            if num < 0:
                maxSum = max(maxSum, currSum)
                if num + currSum < 0:
                    if currSum >= 0:
                        currSum += num
                    else:
                        currSum = num
                else:
                    currSum += num
            else:
                if currSum < 0:
                    currSum = num
                else:
                    currSum += num
        return max(currSum, maxSum)