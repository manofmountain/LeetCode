//67.42%
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
			return 0;
		
		int totalDuration(0);
		int timeSize(timeSeries.size());		
		int lastSmallTimePos(findLastSmallerTime(timeSeries, 0, timeSize - 1, timeSeries[0] + duration));
		int prevPos(0);

		while(lastSmallTimePos < timeSize){
			if(prevPos == lastSmallTimePos){
				totalDuration += duration;
				++prevPos;
				if(prevPos == timeSize)
					break;
			}else{
				totalDuration += (timeSeries[lastSmallTimePos] - timeSeries[prevPos]);
				prevPos = lastSmallTimePos;
			}
			
			lastSmallTimePos = findLastSmallerTime(timeSeries, prevPos, timeSize - 1, timeSeries[prevPos] + duration);
		}
		return totalDuration;
    }
private:
	int findLastSmallerTime(const vector<int>& timeSeries, int left, int right, int val){
		while(left <= right){
			int mid(left + (right - left) / 2);
			if(timeSeries[mid] > val)
				right = mid - 1;
			else if(timeSeries[mid] < val)
				left = mid + 1;
			else
				return mid;
		}
		return right;
	}
};

//1.97%
class Solution {
public:
    int findPosisonedDuration(vector<int>& ts, int duration) {
        int tp = 0, pe = 0;
        for(int i=0; i<ts.size(); ++i){
            tp += duration - (ts[i] < pe) *(pe - ts[i]);
            pe = ts[i] + duration;
        }
        return tp;
    }
};

public class Solution {
    public int findPosisonedDuration(int[] timeSeries, int duration) {
        if (timeSeries == null || timeSeries.length == 0 || duration == 0) return 0;
        
        int result = 0, start = timeSeries[0], end = timeSeries[0] + duration;
        for (int i = 1; i < timeSeries.length; i++) {
            if (timeSeries[i] > end) {
                result += end - start;
                start = timeSeries[i];
            }
            end = timeSeries[i] + duration;
        }
        result += end - start;
        
        return result;
    }
}