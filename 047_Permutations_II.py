#69.19%
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def permuteHelper(nums, left):
            if left == size:
                res.append(nums[:])
                return
            table = set()
            i = left
            while i < size:
                if nums[i] in table:
                    i += 1
                    continue
                table.add(nums[i])
                nums[i], nums[left] = nums[left], nums[i]
                permuteHelper(nums, left + 1)
                nums[i], nums[left] = nums[left], nums[i]
                i += 1
        size = len(nums)
        res = list()
        if size == 0:
            return res
        permuteHelper(nums, 0)
		return res
        