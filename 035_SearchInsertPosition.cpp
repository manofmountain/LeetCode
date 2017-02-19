//8.7%
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size(nums.size());
		int left(0), right(size - 1);
		if(nums[left] > target)
			return 0;
		if(nums[right] < target)
			return size;
		
		while(left < right){
			int mid = (left + right) / 2;
			if(nums[mid] < target)
				left = mid + 1;
			else if(nums[mid] == target)
				return mid;
			else
				right = mid;
		}
		return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		auto ite = upper_bound(nums.begin(), nums.end(), target);
		if(ite != nums.begin() && *(ite - 1) == target)
			return ite - nums.begin() - 1;
		return ite - nums.begin();
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }
};