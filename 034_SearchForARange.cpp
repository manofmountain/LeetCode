//1.88%
//My first method
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size(nums.size());
		vector<int> res(2);
		int left(0), right(size - 1);
		int mid(-1);
		while(left <= right){
			mid = (left + right) / 2;
			if(nums[mid] > target)
				right = mid - 1;
			else if(nums[mid] < target)
				left = mid + 1;
			else
				break;
		}
		if(left > right){
			res[0] = -1;
			res[1] = -1;
			return res;
		}
		left = mid; right = mid;
		while(left > 0 && nums[left - 1] == target) left--;
		while(right < size - 1 && nums[right + 1] == target) right++;
		res[0] = left;
		res[1] = right;
		return res;	
    }
};

//43.77%
//My second method
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int size(nums.size());
		vector<int> res(2, -1);
		if(nums.empty()) return res;
		
		//Find out low bound
		int low(-1), up(-1);
		if(nums[0] == target)
			low = 0;
		else if(nums[0] > target)
			return res;
		else{
			int left(0), right(size - 1);
			while(left <= right){
				int mid = (left + right) / 2;
				if(nums[mid] > target)
					right = mid - 1;
				else if(nums[mid] < target)
					left = mid + 1;
				else if(nums[mid - 1] < target){
					low = mid;
					break;
				}else
					right = mid - 1;
			}
		}
		
		//Find up bound
		if(nums[size - 1] == target)
			up = size - 1;
		else if(nums[size - 1] < target)
			return res;
		else{
			int left = 0;
			int right = size - 1;
			while(left <= right){
				int mid = (left + right) / 2;
				if(nums[mid] > target)
					right = mid - 1;
				else if(nums[mid] < target)
					left = mid + 1;
				else if(nums[mid + 1] > target){
					up = mid;
					break;
				}else
					left = mid + 1;
			}
		}
		res[0] = low;
		res[1] = up;
		return res;			
    }
};

//A better solution than mine and told us how to obtain the bound value in a sorted sequence
vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
    
    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	// Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}

//By using std library
vector<int> searchRange(vector<int>& nums, int target) {
    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
        return {-1, -1};
    return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
}

vector<int> searchRange(vector<int>& nums, int target) {
    int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lo == nums.size() || nums[lo] != target)
        return {-1, -1};
    int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {lo, hi};
}
