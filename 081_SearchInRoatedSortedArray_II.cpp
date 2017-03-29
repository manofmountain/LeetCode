//10.48%
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
			return false;
		int left(0), right(nums.size() - 1);
		//In case nums[0] == nums[size - 1]
		while(nums[left] == nums[right] && left < right) right--;
		if(left == right)
			return nums[left] == target;
		int low(left), up(right), size(right + 1);
		//Find the possible position of rotating
		while(left < right){
			int mid = (left + right) / 2;
			if(nums[mid] >= nums[0])
				left = mid + 1;
			else
				right = mid;
		}
		
		int rotate(left);
		if(nums[left] > nums[0])
			rotate = 0;
		while(low <= up){
			int mid = (low + up) / 2;
			int actualMid = (mid + rotate) % size;
			if(nums[actualMid] > target)
				up = mid - 1;
			else if(nums[actualMid] < target)
				low = mid + 1;
			else
				return true;
		}
		return false;
    }
};

//What a genious function from LeetCode
class Solution {
public:
  bool search(int A[], int n, int target) {
    int lo =0, hi = n-1;
    int mid = 0;
    while(lo<hi){
          mid=(lo+hi)/2;
          if(A[mid]==target) return true;
          if(A[mid]>A[hi]){
              if(A[mid]>target && A[lo] <= target) hi = mid;
              else lo = mid + 1;
          }else if(A[mid] < A[hi]){
              if(A[mid]<target && A[hi] >= target) lo = mid + 1;
              else hi = mid;
          }else{
              hi--;
          }
          
    }
    return A[lo] == target ? true : false;
  }
};

//A better one and has much more readability
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        
        while(left<=right)
        {
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;

            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

            else if(nums[left] <= nums[mid])
            {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else
            {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};