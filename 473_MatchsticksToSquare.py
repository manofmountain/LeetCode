##99.32%
class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def dfs(start, currWidth):
            for i in xrange(start, len(nums)):
                if traced[i] == 0:
                    if currWidth + nums[i] == width:
                        traced[i] = 1
                        return True
                    elif (currWidth + nums[i]) < width:
                        traced[i] = 1
                        if dfs(i + 1, currWidth + nums[i]):
                            return True
                        else:
                            traced[i] = 0
            return False
        if not nums or len(nums) < 4:
            return False
        total = sum(nums)
        if (total & 3) != 0:
            return False
        width = total >> 2
        traced = [0 for _ in nums]
        nums.sort(reverse = True)
        for i in xrange(4):
            if not dfs(0, 0):
                return False
        if 0 in traced:
            return False
        return True