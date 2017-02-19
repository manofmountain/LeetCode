# 70.07%
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = [-1] * 2
        size = len(nums)
        if size == 0:
            return res
        #Find low bound
        low, up = -1, -1
        if nums[0] > target:
            return res
        elif nums[0] == target:
            low = 0
        else:
            left, right = 0, size - 1
            while left <= right:
                mid = (left + right) / 2
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                elif nums[mid - 1] < target:
                    low = mid
                    break
                else:
                    right = mid - 1
        
        #Find up bound
        if nums[size - 1] < target:
            return res
        elif nums[size - 1] == target:
            up = size - 1
        else:
            left, right = 0, size - 1
            while left <= right:
                mid = (left + right) / 2
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                elif nums[mid + 1] > target:
                    up = mid
                    break
                else:
                    left = mid + 1
        
        res[0], res[1] = low, up
        return res
	
# A very elegant recursive function	
def searchRange(self, nums, target):
    def search(lo, hi):
        if nums[lo] == target == nums[hi]:
            return [lo, hi]
        if nums[lo] <= target <= nums[hi]:
            mid = (lo + hi) / 2
            l, r = search(lo, mid), search(mid+1, hi)
            return max(l, r) if -1 in l+r else [l[0], r[1]]
        return [-1, -1]
    return search(0, len(nums)-1)
	
# What a genious
def searchRange(self, nums, target):
    def search(n):
        lo, hi = 0, len(nums)
        while lo < hi:
            mid = (lo + hi) / 2
            if nums[mid] >= n:
                hi = mid
            else:
                lo = mid + 1
        return lo
    lo = search(target)
    return [lo, search(target+1)-1] if target in nums[lo:lo+1] else [-1, -1]

def searchRange(self, nums, target):
    lo = bisect.bisect_left(nums, target)
    return [lo, bisect.bisect(nums, target)-1] if target in nums[lo:lo+1] else [-1, -1]
