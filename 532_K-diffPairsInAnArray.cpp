class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		if(k < 0 || nums.empty())
			return 0;
		sort(nums.begin(), nums.end());
		int res(0);
		for(int i = 0; i < nums.size() - 1; ++i){
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			if(binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k))
				++res;
		}
		return res;
    }
};

//A java way by using HashMap
public class Solution {
    public int findPairs(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k < 0)   return 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for (int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (k == 0) {
                //count how many elements in the array that appear more than twice.
                if (entry.getValue() >= 2) {
                    count++;
                } 
            } else {
                if (map.containsKey(entry.getKey() + k)) {
                    count++;
                }
            }
        }
        
        return count;
    }
}

//A two pointers solution
public int findPairs(int[] nums, int k) {
    int ans = 0;
    Arrays.sort(nums);
    for (int i = 0, j = 0; i < nums.length; i++) {
        for (j = Math.max(j, i + 1); j < nums.length && (long) nums[j] - nums[i] < k; j++) ;
        if (j < nums.length && (long) nums[j] - nums[i] == k) ans++;
        while (i + 1 < nums.length && nums[i] == nums[i + 1]) i++;
    }
    return ans;
}

//O(n) solution
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i)
           ++m[nums[i]];
        int res = 0;
        if(k != 0) {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(m.find(it->first+k) != m.end())
                   ++res;
        } else {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(it->second > 1)
                   ++res;
        }
        return res;
    }
};