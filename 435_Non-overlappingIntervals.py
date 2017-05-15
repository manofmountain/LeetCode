# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e
## 57.89%
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if len(intervals) <= 1:
            return 0
        
        intervals.sort(key = lambda x : (x.start, x.end))
        prev, cnt = 0, 0
        for i in xrange(1, len(intervals)):
            if intervals[i].start >= intervals[prev].end:
                prev = i
            elif intervals[i].end <= intervals[prev].end:
                prev = i
                cnt += 1
            else:
                cnt += 1
        return cnt
		
def eraseOverlapIntervals(self, intervals):
    end = float('-inf')
    erased = 0
    for i in sorted(intervals, key=lambda i: i.end):
        if i.start >= end:
            end = i.end
        else:
            erased += 1
    return erased