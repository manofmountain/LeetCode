//11.95%
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numTable;
		for(int i = 0; i < nums.size(); i++){
			unordered_map<int, int>::iterator first = numTable.find(nums[i]);
			if(first != numTable.end()){
				if((i - first -> second) <= k)
					return true;
				else
					first -> second = i;
			}else
				numTable[nums[i]] = i;
		}
		return false;
	}
};

//16.53%
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};
//6.37%
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int> cand;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) cand.erase(nums[i-k-1]);
        if (!cand.insert(nums[i]).second) return true;
    }
    return false;
}