//Timelimit exceeded
//O(n^2) time + O(n) space
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
			return 0;
		int size(nums.size());
		vector<int> numOnes(size + 1);
		numOnes[1] = nums[0];
		for(int i = 2; i <= size; ++i)
			numOnes[i] = numOnes[i - 1] + nums[i - 1];
		for(int i = size; i >= 2; --i){
			for(int j = 1; j <= size - i + 1; ++j){
				if((numOnes[j + i - 1] - numOnes[j - 1]) * 2 == i)
					return i;
			}
		}
		return 0;
	}
};

//A clever java way
public class Solution {
    public int findMaxLength(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        
        Map<Integer, Integer> sumToIndex = new HashMap<>();
        sumToIndex.put(0, -1);
        int sum = 0, max = 0;
        
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (sumToIndex.containsKey(sum)) {
                max = Math.max(max, i - sumToIndex.get(sum));
            }
            else {
                sumToIndex.put(sum, i);
            }
        }
        
        return max;
    }
}