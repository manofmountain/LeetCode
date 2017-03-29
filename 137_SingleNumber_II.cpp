//29.22%
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int res(0);
		for(int i = 0; i < 32; ++i){
			int cnt(0);
			for(int j = 0; j < nums.size(); ++j){
				if(nums[j] & (1 << i))
					++cnt;
			}
			if(cnt % 3)
				res |= (1 << i);
		}
		return res;		
    }
};

public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}