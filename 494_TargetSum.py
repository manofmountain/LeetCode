##A kind of DFS
class Solution(object):
    def findTargetSumWays(self, nums, S):
        if not nums:
            return 0
        dic = {nums[0]: 1, -nums[0]: 1} if nums[0] != 0 else {0: 2}
        for i in range(1, len(nums)):
            tdic = {}
            for d in dic:
                tdic[d + nums[i]] = tdic.get(d + nums[i], 0) + dic.get(d, 0)
                tdic[d - nums[i]] = tdic.get(d - nums[i], 0) + dic.get(d, 0)
            dic = tdic
        return dic.get(S, 0)

##Memory limit exceeded
class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        def subsetSum(subTotal):
            #dp = [0] * (subTotal + 1)
            dp = [0 for _ in xrange(subTotal + 1)]
            dp[0] = 1
            for num in nums:
                for s in range(subTotal, num - 1, -1):
                    dp[s] += dp[s - num]
            return dp[subTotal]
        total = sum(nums)
        subTotal = total + S
        return 0 if (subTotal & 1) != 0 else subsetSum(subTotal / 2)