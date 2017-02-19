//8.81%
class Solution {
public:
    int search(vector<int>& nums, int target) {
		if(nums.empty())
			return -1;
		int pivotPos = posOfPivot(nums);
		int index = binarySearch(nums, 0, pivotPos - 1, target);
		if(index >= 0)
			return index;
		return binarySearch(nums, pivotPos, nums.size() - 1, target);	
    }
private:
	//Return '-1' if not found
	int binarySearch(vector<int>& nums, int left, int right, int target){
		while(left <= right){
			int mid = (left + right) / 2;
			if(nums[mid] > target)
				right = mid - 1;
			else if(nums[mid] < target)
				left = mid + 1;
			else
				return mid;
		}
		return -1;
	}
	int posOfPivot(vector<int>& nums){
		int size(nums.size());
		int left(0), right(size - 1);
		int boundMin, boundMax;
		if(nums[0] > nums[size - 1]){
			boundMin = nums[size - 1];
			boundMax = nums[0];
		}else{
			return 0;
		}
		while(left < right){
			int mid = (left + right) / 2;
			if(nums[mid] < boundMin){
				if(nums[mid - 1] < boundMin)
					right = mid - 1;
				else
					return mid;
			}
			else if(nums[mid] > boundMax){
				if(nums[mid + 1] > boundMax)
					left = mid + 1;
				else
					return mid + 1;
			}
			else if(nums[mid] == boundMin)
				return mid;
			else
				return mid + 1;
		}	
	}		
};

//A function with wisdom from LeetCode which is far better than mine
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};