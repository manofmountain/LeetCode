##96.59%
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations:
            return 0
        left, size, index = 1, len(citations), 0
        right = size
        while left <= right:
            mid = left + (right - left) / 2
            if citations[size - mid] >= mid:
                index = mid
                left = mid + 1
            else:
                right = mid - 1
        return index