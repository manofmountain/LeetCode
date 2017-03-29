//1.62%
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if(nums.empty())
			return -1;
        if(nums.size() == 1)
			return 0;
		if(nums[0] > nums[1])
			return 0;
		for(int i = 1; i < nums.size() - 1; ++i)
			if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
				return i;
		return nums[nums.size() - 1] > nums[nums.size() - 2] ? nums.size() - 1 : -1;
    }
};

//16.47%
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if(nums.empty())
			return -1;
        if(nums.size() == 1)
			return 0;
		
		int left(0), right(nums.size() - 1);
		while(left + 1 < right){
			int mid(left + (right - left) / 2);
			if(nums[mid] <= nums[right])
				left = mid;
			else if(nums[mid] <= nums[left])
				right = mid;
			else{
				if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
					return mid;
				else if(nums[mid] < nums[mid + 1])
					left = mid;
				else
					right = mid;
			}
		}
		return nums[left] >= nums[right] ? left : right;		
    }
};

//Recursive
class Solution {
public:

int findPeakElement(const vector<int> &num) {
    return Helper(num, 0, num.size()-1);
}
int Helper(const vector<int> &num, int low, int high)
{
    if(low == high)
        return low;
    else
    {
        int mid1 = (low+high)/2;
        int mid2 = mid1+1;
        if(num[mid1] > num[mid2])
            return Helper(num, low, mid1);
        else
            return Helper(num, mid2, high);
    }
}
};

class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};