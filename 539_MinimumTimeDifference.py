##54.3%
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        timePoints.sort()
        timeList = map(lambda timePoint: int(timePoint[:2]) * 60 + int(timePoint[3:]), timePoints)
        timeList.append(timeList[0] + 24 * 60)
        minDiff = 0x7fffffff
        for prevTime, currTime in zip(timeList[:len(timeList) - 1], timeList[1: len(timeList)]):
            minDiff = min(minDiff, currTime - prevTime)
        return minDiff
		
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        timePoints.sort()
        timeList = map(lambda timePoint: (int(timePoint[:2]), int(timePoint[3:])), timePoints)
        timeList.append((timeList[0][0] + 24, timeList[0][1]))
        minDiff = (0x7fffffff, 0x7fffffff)
        for prevTime, currTime in zip(timeList[:len(timeList) - 1], timeList[1: len(timeList)]):
            minDiff = min(minDiff, (currTime[0] - prevTime[0], currTime[1] - prevTime[1]))
        return minDiff[0] * 60 + minDiff[1]
		
def findMinDifference(self, A):
    def convert(time):
        return int(time[:2]) * 60 + int(time[3:])
    minutes = map(convert, A)
    minutes.sort()
    
    return min( (y - x) % (24 * 60) 
                for x, y in zip(minutes, minutes[1:] + minutes[:1]) )