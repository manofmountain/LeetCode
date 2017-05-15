//38.66%
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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        unordered_map<int, int> intervalTable;
		vector<int> startOfIntervals(intervals.size());
		for(int i = 0; i < intervals.size(); ++i){
			intervalTable.insert(make_pair(intervals[i].start, i));
			startOfIntervals[i] = intervals[i].start;
		}
		sort(startOfIntervals.begin(), startOfIntervals.end());
		vector<int> res;
		res.reserve(intervals.size());
		for(int i = 0; i < intervals.size(); ++i){
			vector<int>::iterator ite(lower_bound(startOfIntervals.begin(), startOfIntervals.end(), intervals[i].end));
			if(ite == startOfIntervals.end())
				res.push_back(-1);
			else
				res.push_back(intervalTable[*ite]);
		}
		return res;		
    }
};


//80.56%
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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> intervalTable;
		for(int i = 0; i < intervals.size(); ++i){
			intervalTable.insert(make_pair(intervals[i].start, i));
		}
		vector<int> res;
		res.reserve(intervals.size());
		for(int i = 0; i < intervals.size(); ++i){
			map<int, int>::iterator ite(intervalTable.lower_bound(intervals[i].end));
			if(ite == intervalTable.end())
				res.push_back(-1);
			else
				res.push_back((*ite).second);
		}
		return res;		
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> hash;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            hash[intervals[i].start] = i;
        for (auto in : intervals) {
            auto itr = hash.lower_bound(in.end);
            if (itr == hash.end()) res.push_back(-1);
            else res.push_back(itr->second);
        }
        return res;
    }
};

//This java solution has similar idea with mine
public class Solution {
    public int[] findRightInterval(Interval[] intervals) {
        int[] result = new int[intervals.length];
        java.util.NavigableMap<Integer, Integer> intervalMap = new TreeMap<>();
        
        for (int i = 0; i < intervals.length; ++i) {
            intervalMap.put(intervals[i].start, i);    
        }
        
        for (int i = 0; i < intervals.length; ++i) {
            Map.Entry<Integer, Integer> entry = intervalMap.ceilingEntry(intervals[i].end);
            result[i] = (entry != null) ? entry.getValue() : -1;
        }
        
        return result;
    }
}