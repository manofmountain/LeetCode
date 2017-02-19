# 45.07%
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.numSums = [0] * (len(nums) + 1)
        for i, num in enumerate(nums):
            self.numSums[i + 1] = self.numSums[i] + num

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.numSums[j + 1] - self.numSums[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)

# A solution from LeetCode, seems better than mine
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.accu = [0]
        for num in nums: 
            self.accu += self.accu[-1] + num,

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int 
        :type j: int
        :rtype: int 
        """
        return self.accu[j + 1] - self.accu[i]