# 77.2%
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        import collections
        c = collections.Counter(nums1)
        res = list()
        for num in nums2:
            if num in c and c[num] > 0:
                c[num] -= 1
                res.append(num)
        return res

		
# A solution from LeetCode and pretty clear		
from collections import Counter

class Solution(object):
    def intersect(self, nums1, nums2):
        c1, c2 = Counter(nums1), Counter(nums2)
        return sum([[num] * min(c1[num], c2[num]) for num in c1 & c2], [])