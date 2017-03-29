//33.49%
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left(0), right(nums.size() - 1);
		while(left < right && nums[left] == nums[right])
			++left;
		if(left >= right)
			return nums[right];
		while(left < right){
			if(nums[left] < nums[right])
				return nums[left];
			int mid(left + (right - left) / 2);
			if(nums[mid] > nums[right])
				left = mid + 1;
			else
				right = mid;
		}
		return nums[right];
    }
};

//Another solution from LeetCode
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty())
            return 0;
        int i=0,j=num.size()-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(num[j]<num[mid]){
                i=mid+1;
            }
            else if(num[mid]<num[j]){
                j=mid;
            }
            else{//num[mid]==num[j]
                if(num[i]==num[mid]){//linear complexity
                    i++;
                    j--;
                }
                else
                    j=mid;
            }
        }
        return num[j];
    }
};