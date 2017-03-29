//45.39%
O(lognlogn)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
			return {};
		vector<string> res;
		summaryRangesHelper(res, nums, 0, nums.size() - 1);
		return res;
    }
private:
	void summaryRangesHelper(vector<string>& res, const vector<int>& nums, int left, int right){
		if(left > right)
			return;
		if(left == right){
			res.push_back(to_string(nums[left]));
			return;
		}
		if(right - left == (nums[right] - nums[left])){
			res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
			return;
		}
		int lMid(left + (right - left) / 2);
		int rMid(lMid);
		while(lMid > left && nums[lMid] - nums[lMid - 1] == 1)
			--lMid;
		while(rMid < right && nums[rMid + 1] - nums[rMid] == 1)
			++rMid;
		
		summaryRangesHelper(res, nums, left, lMid - 1);
		if(lMid == rMid)
			res.push_back(to_string(nums[lMid]));
		else
			res.push_back(to_string(nums[lMid]) + "->" + to_string(nums[rMid]));
		summaryRangesHelper(res, nums, rMid + 1, right);
	}
};

//O(n)
 vector<string> summaryRanges(vector<int>& nums) {
    const int size_n = nums.size();
    vector<string> res;
    if ( 0 == size_n) return res;
    for (int i = 0; i < size_n;) {
        int start = i, end = i;
        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
        if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else res.push_back(to_string(nums[start]));
        i = end+1;
    }
    return res;
}