//42.46%
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestHelper(nums, 0, nums.size() - 1, k);
    }
private:
	int findKthLargestHelper(vector<int>& nums, int start, int end, int k){
		if(start > end)
			return -1;
		if(start == end && k == 1)
			return nums[end];
		int sentry(nums[end]);
		int left(start), right(end - 1);
		while(left <= right){
			if(nums[left] < sentry)
				++left;
			else if(nums[right] >= sentry)
				--right;
			else
				swap(nums[left++], nums[right--]);
		}
		swap(nums[left], nums[end]);
		if(end - left + 1 == k)
			return nums[left];
		else if(end - left + 1 > k)
			return findKthLargestHelper(nums, left + 1, end, k);
		else
			return findKthLargestHelper(nums, start, left - 1, k - end + left - 1);
	}		
};

//47.53%
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start(0), end(nums.size() - 1);
		while(start < end){
			int sentry(nums[end]);
			int left(start), right(end - 1);
			while(left <= right){
				if(nums[left] < sentry)
					++left;
				else if(nums[right] >= sentry)
					--right;
				else
					swap(nums[left++], nums[right--]);
			}
			swap(nums[left], nums[end]);
			if(end - left + 1 == k)
				return nums[left];
			else if(end - left + 1 > k){
				start = left + 1;
			}else{
				k -= (end - left + 1);
				end = left - 1;
			}

		}
		if(k == 1 && start == end)
			return nums[start];
		return -1; //Just in case
    }	
};

//From leetcode
class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();
    }
}; 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        int n = nums.size();
        for (int i = 0; i < n; i++) { 
            mset.insert(nums[i]);
            if (mset.size() > k)
                mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};