import math
class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        width, res = int(math.sqrt(area)), list()
        while width != 0:
            if area % width == 0:
                res.append(area / width)
                res.append(width)
                break
            width -= 1
        return res