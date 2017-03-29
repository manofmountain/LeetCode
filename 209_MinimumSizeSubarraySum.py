#49.86%
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        res, past, start = len(nums) + 1, 0, 0
        for i in xrange(len(nums)):
            past += nums[i]
            if past >= s:
                while past - nums[start] >= s:
                    past -= nums[start]
                    start += 1
                res = min(res, i - start + 1)
                past -= nums[start]
                start += 1
        if res == len(nums) + 1:
            return 0
        return res