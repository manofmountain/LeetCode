class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        numsSorted = nums[:]
        numsSorted.sort(reverse = True)
        map = dict()
        for i, num in enumerate(numsSorted):
            map[num] = i
        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        res = list()
        for num in nums:
            if map[num] < 3:
                res.append(medals[map[num]])
            else:
                res.append(str(map[num] + 1))
        return res
		
def findRelativeRanks(self, nums):
    sort = sorted(nums)[::-1]
    rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(str, range(4, len(nums) + 1))
    return map(dict(zip(sort, rank)).get, nums)