//90.65%
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
    vector<Interval> merge(vector<Interval>& intervals) {
        int size(intervals.size());
		if(size <= 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), compareInterval);
		vector<Interval> res;
		for(int i = 1; i < size; i++){
			if(intervals[i].start <= intervals[i - 1].end){
				intervals[i].start = intervals[i - 1].start;
				intervals[i].end = max(intervals[i - 1].end, intervals[i].end);
			}else
				res.push_back(intervals[i - 1]);
		}
		res.push_back(intervals[size - 1]);
		return res;
    }
private:
	static bool compareInterval(Interval& v1, Interval& v2){
		return v1.start < v2.start;
	}

};

//In this way, we won't change the input reference parameter
vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}