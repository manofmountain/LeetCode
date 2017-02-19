class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def permuteHelper(nums, left, right):
            if left == right:
                res.append(vec[:])
            i = left
            while i < right:
                nums[left], nums[i] = nums[i], nums[left]
                vec[left] = nums[left]
                permuteHelper(nums, left + 1, right)
                nums[i], nums[left] = nums[left], nums[i]
                i += 1
            
        res = list()
        vec = [0] * len(nums)
        permuteHelper(nums, 0, len(nums))
        return res

#What a genious	
def permute(self, nums):
    perms = \[\[\]\]   
    for n in nums:
        new_perms = []
        for perm in perms:
            for i in xrange(len(perm)+1):   
                new_perms.append(perm[:i] + [n] + perm[i:])   ###insert n
        perms = new_perms
    return perms