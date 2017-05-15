//28.94%
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty())
			return 0;
		
		auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.first < p2.first; };
		sort(points.begin(), points.end(), cmp);
		int cnt(1);
		for(int i = 1; i < points.size(); ++i){
			if(points[i].first <= points[i - 1].second)
				points[i].second = min(points[i - 1].second, points[i].second);
			else
				++cnt;
		}
		return cnt;
    }
};

int findMinArrowShots(vector<pair<int, int>>& points) {
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), mysort);
        for(int i = 0; i<points.size(); i++){
            if(points[i].first > arrow){
				arrow = points[i].second; // new arrow shot the end of points[i]
				++count;
			}
        }
        return count;
    }
    static bool mysort(const pair<int, int>& a, const pair<int, int>& b){
        return a.second<b.second;
    }