##27.44%
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        nums.sort()
        res = [(1, -1)]
        for i in xrange(1, len(nums)):
            j = 0
            res.append((0, 0))
            while j < i:
                if nums[i] % nums[j] == 0:
                    if res[j][0] + 1 > res[i][0]:
                        res[i] = (res[j][0] + 1, j)
                j += 1
            if res[i][0] == 0:
                res[i] = (1, -1)
        maxHeight, index = 0, -1
        for i in xrange(len(nums)):
            if res[i][0] > maxHeight:
                maxHeight, index = res[i][0], i
        ans = [0] * maxHeight
        for i in range(maxHeight)[::-1]:
            ans[i] = nums[index]
            index = res[index][1]
        return ans

##An elegant Python solution		
def largestDivisibleSubset(self, nums):
    S = {-1: set()}
    for x in sorted(nums):
        S[x] = max((S[d] for d in S if x % d == 0), key=len) | {x}
    return list(max(S.values(), key=len))   