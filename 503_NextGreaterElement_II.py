##59.42%
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return nums
        res = [-1] * len(nums)
        stack = []
        for i, num in enumerate(nums):
            while stack and num > nums[stack[-1]]:
                res[stack[-1]] = num
                stack.pop()
            stack.append(i)
        start = 0
        while stack and start < stack[-1]:
            if nums[start] > nums[stack[-1]]:
                res[stack[-1]] = nums[start]
                stack.pop()
            else:
                start += 1
        return res

##A more concise method		
def nextGreaterElements(self, nums):
        stack, res = [], [-1] * len(nums)
        for i in range(len(nums)) * 2:
            while stack and (nums[stack[-1]] < nums[i]):
                res[stack.pop()] = nums[i]
            stack.append(i)
        return res