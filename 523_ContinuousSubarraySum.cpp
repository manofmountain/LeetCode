//26.12%
//O(n^2)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
		//Size less than 2
        if(nums.size() < 2)
			return false;
		//Has two more consecutive zeroes
		for(int i = 1; i < nums.size(); ++i){
			if(nums[i] == 0 && nums[i - 1] == 0)
				return true;
		}
		//k is zero
		if(0 == k)
			return false;
		//Normal case
		for(int i = 0; i < nums.size() - 1; ++i){
			int sum(nums[i]);
			for(int j = i + 1; j < nums.size(); ++j){
				sum += nums[j];
				if(sum % k == 0)
					return true;
			}
		}
		return false;
    }
};



//A good java solution which has a better thinking
/*
We iterate through the input array exactly once, keeping track of the running sum mod k of the elements in the process. If we find that a running sum value at index j has been previously seen before in some earlier index i in the array, then we know that the sub-array (i,j] contains a desired sum.
*/
public boolean checkSubarraySum(int[] nums, int k) {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>(){{put(0,-1);}};;
    int runningSum = 0;
    for (int i=0;i<nums.length;i++) {
        runningSum += nums[i];
        if (k != 0) runningSum %= k; 
        Integer prev = map.get(runningSum);
        if (prev != null) {
            if (i - prev > 1) return true;
        }
        else map.put(runningSum, i);
    }
    return false;
}

//Has a better improvement here
//There is really no need to use map, the required length is at least 2, so we just need to insert the mod one iteration later.
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};