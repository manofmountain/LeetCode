//35.61%
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
			return 0;
		int cnt(0), prev(0);
		sort(intervals.begin(), intervals.end(), [](const Interval& val1, const Interval& val2){ return val1.start < val2.start || (val1.start == val2.start && val1.end < val2.end);});
		for(int i = 1; i < intervals.size(); ++i){
			if(intervals[i].start >= intervals[prev].end){
				prev = i;
			}else if(intervals[i].end <= intervals[prev].end){
				prev = i;
				++cnt;
			}else{
				++cnt;
			}
		}
		return cnt;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[pre].end) {
                res++;
                if (intervals[i].end < intervals[pre].end) pre = i;
            }
            else pre = i;
        }
        return res;
    }
};

//A good java solution, only sort the 'end'
public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length == 0)  return 0;

        Arrays.sort(intervals, new myComparator());
        int end = intervals[0].end;
        int count = 1;        

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i].start >= end) {
                end = intervals[i].end;
                count++;
            }
        }
        return intervals.length - count;
    }
    
    class myComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.end - b.end;
        }
    }