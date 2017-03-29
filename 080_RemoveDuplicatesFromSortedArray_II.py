#97.85%
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        size = len(nums)
        length, repeated, pre = 1, False, nums[0]
        for num in nums[1:]:
            if num == pre:
                if not repeated:
                    nums[length] = num
                    length += 1
                    repeated = True
            else:
                pre = num
                nums[length] = num
                length += 1
                repeated = False
        return length
		
def removeDuplicates(self, nums):
    i = 0
    for n in nums:
        if i < 2 or n > nums[i-2]:
            nums[i] = n
            i += 1
    return i