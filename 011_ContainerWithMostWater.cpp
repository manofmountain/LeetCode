//29.38%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left(0), right(height.size() - 1), maxRes(-1);
		while(left < right){
			if(height[left] > height[right]){
				int lowerBound(height[right]);
				maxRes = max(maxRes, lowerBound * (right - left));
				while(height[--right] <= lowerBound);
			}else{
				int lowerBound(height[left]);
				maxRes = max(maxRes, lowerBound * (right - left));	
				while(left < right && height[++left] <= lowerBound);
			}
		}
		return maxRes;
    }
};

//A more clear way
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}