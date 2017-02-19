# 42.86%
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def distance(point1, point2):
            return (point1[0] - point2[0]) * (point1[0] - point2[0]) + (point1[1] - point2[1]) * (point1[1] - point2[1])
            
        size, res = len(points), 0
        #map = dict{}
        for i in range(size):
            distMap = dict()
            for j in range(size):
                d = distance(points[i], points[j])
                if d in distMap:
                    distMap[d] += 1
                else:
                    distMap[d] = 1
            for value in distMap.values():
                #if value >= 2:
                 res += (value - 1) * value;
        return res

##This one looks like mine		
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """	
		res = 0
        for p in points:
            cmap = {}
            for q in points:
                f = p[0]-q[0]
                s = p[1]-q[1]
                cmap[f*f + s*s] = 1 + cmap.get(f*f + s*s, 0)
            for k in cmap:
                res += cmap[k] * (cmap[k] -1)
        return res
        