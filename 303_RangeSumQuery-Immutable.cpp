//28.91%
class NumArray {
public:
    NumArray(vector<int> nums): sumNums(nums.size() + 1, 0) {
        for(int i = 0; i < nums.size(); i++){
			sumNums[i + 1] = sumNums[i] + nums[i];
		}
    }
    
    int sumRange(int i, int j) {
        return sumNums[j + 1] - sumNums[i];
    }
private:
	vector<int> sumNums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 
//Other solution from LeetCode
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};

//Use standard algorithm 'partial_sum'
class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};