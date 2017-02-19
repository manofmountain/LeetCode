class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        def getDistance(heaters, house):
            left, right = 0, len(heaters) - 1
            while left < right:
                mid = (left + right) / 2
                if heaters[mid] == house:
                    return 0
                elif heaters[mid] > house:
                    right = mid - 1
                else:
                    left = mid + 1
            if heaters[left] > house:
                if left > 0:
                    return min(house - heaters[left - 1], heaters[left] - house)
                return heaters[left] - house
            else:
                if right < len(heaters) - 1:
                    return min(heaters[right + 1] - house, house - heaters[right])
                return house - heaters[right]
                
        maxDist = 0
        heaters.sort()
        for house in houses:
            dist = getDistance(heaters, house)
            if dist > maxDist:
                maxDist = dist
        return maxDist
		
def findRadius(self, houses, heaters):
    heaters = sorted(heaters) + [float('inf')]
    i = r = 0
    for x in sorted(houses):
        while x >= sum(heaters[i:i+2]) / 2.:
            i += 1
        r = max(r, abs(heaters[i] - x))
    return r