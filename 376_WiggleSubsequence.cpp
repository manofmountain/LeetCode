//82.41%
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
			return 0;
		if(nums.size() == 1)
			return 1;
		vector<int> res(1, nums[0]);
		int sign(0);
		for(int i = 1; i < nums.size(); ++i){
			if(nums[i] > res.back()){
				if(sign <= 0){
					res.push_back(nums[i]);
					sign = 1;
				}else
					res.back() = nums[i];
			}else if(nums[i] < res.back()){
				if(sign >= 0){
					res.push_back(nums[i]);
					sign = -1;
				}else
					res.back() = nums[i];
			}	
		}
		return res.size();
    }
};


//A java solution with the same thoughts and only O(1) space
    public class Solution {
	public int wiggleMaxLength(int[] nums) {
		if (nums.length == 0 || nums.length == 1) {
			return nums.length;
		}
		int k = 0;
		while (k < nums.length - 1 && nums[k] == nums[k + 1]) {  //Skips all the same numbers from series beginning eg 5, 5, 5, 1
			k++;
		}
		if (k == nums.length - 1) {
			return 1;
		}
		int result = 2;     // This will track the result of result array
		boolean smallReq = nums[k] < nums[k + 1];       //To check series starting pattern
		for (int i = k + 1; i < nums.length - 1; i++) {
			if (smallReq && nums[i + 1] < nums[i]) {
				nums[result] = nums[i + 1];
				result++;
				smallReq = !smallReq;    //Toggle the requirement from small to big number
			} else {
				if (!smallReq && nums[i + 1] > nums[i]) {
					nums[result] = nums[i + 1];
					result++;
					smallReq = !smallReq;    //Toggle the requirement from big to small number
				}
			}
		}
		return result;
	}
}

//A greedy C++ solution ( also a good one and there're state machine inherent the backend )
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), f=1, d=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) f=d+1;
            else if(nums[i]<nums[i-1]) d=f+1;
        }
        return min(size, max(f, d));
    }
};