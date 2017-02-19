# 0.94%
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        return list(set([num for num in nums2 if num in set(nums1)]))

# Better solution than mine		
class Solution(object):
def intersection(self, nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: List[int]
    """
    nums1=set(nums1)
    nums2=set(nums2)
    return list(nums1&nums2)