//Memory limit exceeded
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int pointNum(points.size());
		int res(0);
		vector<map<int, int> > distPoints(pointNum);
		for(int i = 0; i < pointNum - 1; i++)
			for(int j = i + 1; j < pointNum; j++){
				int d(distance(points[i], points[j]));
				distPoints[i][d]++;
				distPoints[j][d]++;
			}
		for(auto &distCounter : distPoints){
			for(auto &counter : distCounter){
				if(counter.second > 1)
					res += ((counter.second - 1) * counter.second);
			}
		}
		return res;	
	}
private:
	inline int distance(const pair<int, int>& point1, const pair<int, int>& point2){
		int x1(point1.first), y1(point1.second), x2(point2.first), y2(point2.second);
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
};

//88.16%
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int pointNum(points.size());
		int res(0);
		for(int i = 0; i < pointNum; i++){
			map<int, int> distCounter;
			for(int j = 0; j < pointNum; j++){
				int d(distance(points[i], points[j]));
				distCounter[d]++;
			}
			for(auto& item : distCounter){
				//if(item.second > 1)
				res += ((item.second - 1) * item.second);
			}
		}
		return res;	
	}
private:
	inline int distance(const pair<int, int>& point1, const pair<int, int>& point2){
		int x1(point1.first), y1(point1.second), x2(point2.first), y2(point2.second);
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
};

//Wonderful solution from LeetCode
int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int booms = 0;
    for (auto &p : points) {
        unordered_map<double, int> ctr(points.size());
        for (auto &q : points)
            booms += 2 * ctr[hypot(p.first - q.first, p.second - q.second)]++;
    }
    return booms;
}

