# 36.8%
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        res = [1]
        for i in range(0, rowIndex):
            res = map(lambda x, y: x + y, res + [0], [0] + res)
        return res