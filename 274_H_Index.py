##33.23%
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations:
            return 0
        citations.sort(key = lambda x : -x)
        cnt = 0
        for i, citation in enumerate(citations):
            if citation >= i + 1:
                cnt += 1
        return cnt