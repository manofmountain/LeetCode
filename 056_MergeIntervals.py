# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        size = len(intervals)
        if 1 >= size:
            return intervals
        intervals.sort(key = lambda x : x.start)
        res = list()
        for i in xrange(1, size):
            if intervals[i].start <= intervals[i - 1].end:
                intervals[i].start = intervals[i - 1].start
                intervals[i].end = max(intervals[i - 1].end, intervals[i].end)
            else:
                res.append(intervals[i - 1])
        res.append(intervals[-1])
        return res

# This method won't change the input parameters		
def merge(self, intervals):
    out = []
    for i in sorted(intervals, key=lambda i: i.start):
        if out and i.start <= out[-1].end:
            out[-1].end = max(out[-1].end, i.end)
        else:
            out += i,
    return out
            