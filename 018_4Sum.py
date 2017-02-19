# 20.44%
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def threeSum(nums, start, size, target):
            tuples = list()
            while start <= size - 3:
                left, right = start + 1, size - 1
                goal = target - nums[start]
                while left < right:
                    temp = nums[left] + nums[right]
                    if temp > goal:
                        right -= 1
                        while left < right and nums[right] == nums[right + 1]: right -= 1
                    elif temp < goal:
                        left += 1
                        while left < right and nums[left] == nums[left - 1]: left += 1
                    else:
                        tuple = [0] * 4
                        tuple[1], tuple[2], tuple[3] = nums[start], nums[left], nums[right]
                        left += 1
                        right -= 1
                        while left < right and nums[right] == nums[right + 1]: right -= 1
                        while left < right and nums[left] == nums[left - 1]: left += 1
                        tuples.append(tuple)
                start += 1
                while start <= size - 3 and nums[start] == nums[start - 1]: start += 1
            return tuples
            
        res, size = list(), len(nums)
        first = 0
		nums.sort()
        while first <= size - 4:
            tuples = threeSum(nums, first + 1, size, target - nums[first])
            for tuple in tuples:
                tuple[0] = nums[first]
                res.append(tuple)
            first += 1
            while first <= size - 4 and nums[first] == nums[first - 1]: first += 1
        return res
   

def fourSum(self, nums, target):
    nums.sort()
    results = []
    self.findNsum(nums, target, 4, [], results)
    return results

## In this way we can get N-Sums by O(n^(N - 1))
def findNsum(self, nums, target, N, result, results):
    if len(nums) < N or N < 2: return

    # solve 2-sum
    if N == 2:
        l,r = 0,len(nums)-1
        while l < r:
            if nums[l] + nums[r] == target:
                results.append(result + [nums[l], nums[r]])
                l += 1
                r -= 1
                while l < r and nums[l] == nums[l - 1]:
                    l += 1
                while r > l and nums[r] == nums[r + 1]:
                    r -= 1
            elif nums[l] + nums[r] < target:
                l += 1
            else:
                r -= 1
    else:
        for i in range(0, len(nums)-N+1):   # careful about range
            if target < nums[i]*N or target > nums[-1]*N:  # take advantages of sorted list
                break
            if i == 0 or i > 0 and nums[i-1] != nums[i]:  # recursively reduce N
                self.findNsum(nums[i+1:], target-nums[i], N-1, result+[nums[i]], results)
    return   