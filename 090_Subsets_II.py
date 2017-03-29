#8.15%
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def subsetsWithDupHelper(start, vec):
            res.append(vec)
            i = start
            while i < sizeNum:
                subsetsWithDupHelper(i + 1, vec + [nums[i]])
                while i < sizeNum - 1 and nums[i + 1] == nums[i]: i += 1
                i += 1
        nums.sort()
        res = list()
        sizeNum = len(nums)
        subsetsWithDupHelper(0, [])
        return res
		
		
class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        res = \[\[\]\]
        S.sort()
        for i in range(len(S)):
            if i == 0 or S[i] != S[i - 1]:
                l = len(res)
            for j in range(len(res) - l, len(res)):
                res.append(res[j] + [S[i]])
        return res