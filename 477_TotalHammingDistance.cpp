class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() <= 1)
			return 0;
		int size(nums.size()), res(0);
		for(int i = 0; i < 32; ++i){
			int cnt(0);
			for(auto num : nums)
				if((num >> i) & 1)
					++cnt;
			res += (size - cnt) * cnt;
		}
		return res;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        int *zeroOne = new int[2];
        while(true)
        {
            int zeroCount = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if(zeroCount == nums.size()) return ans;
        }
    }
};

//O(n^2), timelimit exceeded
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() <= 1)
			return 0;
		int cnt(0);
		//nums.erase(unique(nums.begin(), nums.end()), nums.end());
		for(int i = 0; i < nums.size() - 1; ++i){
			for(int j = i + 1; j < nums.size(); ++j){
				int num(nums[i] ^ nums[j]);
				if(numOnesHistory.find(num) == numOnesHistory.end())
					numOnesHistory.insert(make_pair(num, numOnes(num)));
				cnt += numOnesHistory[num];
			}
		}
		return cnt;
    }
private:
	unordered_map<int, int> numOnesHistory;
	int numOnes(int num){
		int cnt(0);
		while(num){
			++cnt;
			num &= (num - 1);
		}
		return cnt;
	}
};

//A simple java solution
public int totalHammingDistance(int[] nums) {
    int total = 0, n = nums.length;
    for (int j=0;j<32;j++) {
        int bitCount = 0;
        for (int i=0;i<n;i++) 
            bitCount += (nums[i] >> j) & 1;
        total += bitCount*(n - bitCount);
    }
    return total;
}