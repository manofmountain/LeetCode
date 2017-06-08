#54.35
class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        stack = list()
        s3 = -2147483647
        for num in nums[::-1]:
            if num < s3: return True
            else:
                while stack and num > stack[-1]:
                    s3 = stack.pop()
            stack.append(num)
        return False