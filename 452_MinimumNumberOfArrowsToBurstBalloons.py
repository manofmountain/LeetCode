#19.81%
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if not points:
            return 0
        cnt = 1
        points.sort(key = lambda point: point[0])
        for i in xrange(1, len(points)):
            if points[i][0] <= points[i - 1][1]:
                points[i][1] = min(points[i - 1][1], points[i][1])
            else:
                cnt += 1
        return cnt

#69.56%		
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points = sorted(points, key = lambda x: x[1])
        res, end = 0, -float('inf')
        for interval in points:
            if interval[0] > end:
                res += 1
                end = interval[1]
        return res