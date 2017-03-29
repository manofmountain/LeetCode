class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in xrange(0, 32):
            cnt = 0
            for num in nums:
                if num & (1 << i) != 0:
                    cnt += 1
            if cnt % 3 == 1:
                res += (1 << i)
        return res