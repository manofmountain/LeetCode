//96.47%
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		int maxDist(0);
		sort(heaters.begin(), heaters.end());
        for(int house : houses){
			int dist = maxDistance(heaters, house);
			if(maxDist < dist)
				maxDist = dist;
		}
		return maxDist;
    }
private:
	int maxDistance(vector<int>& heaters, int house){
		int size(heaters.size());
		int left(0), right(size - 1);
		while(left < right){
			int mid = (left + right) / 2;
			if(heaters[mid] == house)
				return 0;
			else if(heaters[mid] > house)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if(heaters[left] > house){
			if(left > 0)
				return min(heaters[left] - house, house - heaters[left - 1]);
			return heaters[left] - house;
		}else{
			if(right < size - 1)
				return min(house - heaters[right], heaters[right + 1] - house);
			return house - heaters[right];
		}
	}
};

//A more C++ way to solve this problem
int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int minRadius = 0;
    for (int i = 0; i < houses.size(); i++) {
    	// search for the closest heater whose position is at least the current house's position
    	auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
    	int curRadius = INT_MAX;
    	// if there is such a heater, update the radius for that heater to cover this house if necessary
    	if (larger != heaters.end())
    	    curRadius = *larger - houses[i];
    	// if the heater we found is not the first one, then the previous heater is the closest heater
    	// whose position is smaller than the current house's position
    	if (larger != heaters.begin()) {
    	    auto smaller = larger - 1;
    	   // the heater with the smaller required radius to cover the house wins
    	    curRadius = min(curRadius, houses[i] - *smaller);
    	}
    	minRadius = max(minRadius, curRadius);
    }
    return minRadius;
}