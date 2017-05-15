##50.57%
from collections import Counter
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        counter = Counter(nums).items()
        counter.sort(key = lambda x : -x[1])
        return [c[0] for c in counter[:k]]
        