//Memory limit encountered
class Solution {
public:
    Solution(vector<int> nums) {
		for(int i = 0; i < nums.size(); ++i){
			if(numTable.find(nums[i]) == numTable.end())
				numTable.insert(make_pair(nums[i], vector<int>(1, i)));
			else
				numTable[nums[i]].push_back(i);
		}
    }
    
    int pick(int target) {
        return numTable[target][rand() % numTable[target].size()];
    }
private:
	unordered_map<int, vector<int> > numTable;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

//24.42%
 class Solution {
public:
    Solution(vector<int> nums):vals(nums.begin(), nums.end()) {
		
    }
    
    int pick(int target) {
        int index(rand() % vals.size());
		while(vals[index] != target)
			index = rand() % vals.size();
		return index;
    }
private:
	vector<int> vals;
};


//Simple Reservoir Sampling solution
public class Solution {

    int[] nums;
    Random rnd;

    public Solution(int[] nums) {
        this.nums = nums;
        this.rnd = new Random();
    }
    
    public int pick(int target) {
        int result = -1;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != target)
                continue;
            if (rnd.nextInt(++count) == 0)
                result = i;
        }
        
        return result;
    }
}`

public class Solution {
    int[] nums;
    Random rand;
    public Solution(int[] nums) {
        this.nums = nums;
        this.rand = new Random();
    }
    public int pick(int target) {
        int total = 0;
        int res = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                // randomly select an int from 0 to the nums of target. If x equals 0, set the res as the current index. The probability is always 1/nums for the latest appeared number. For example, 1 for 1st num, 1/2 for 2nd num, 1/3 for 3nd num (1/2 * 2/3 for each of the first 2 nums).
                int x = rand.nextInt(++total); 
                res = x == 0 ? i : res;
            }
        }
        return res;
    }
}

class Solution {
public:
    vector<int> n;
    Solution(vector<int> nums) 
    {
        n = nums;
    }
    
    int pick(int target) 
    {
        int count = 0, res = -1;
        for (int i = 0; i < n.size(); ++i)
        {
            if(n[i] != target) continue;
            if(++count == 1) res = i;
            else
                if(!(rand()%count)) res = i;
        }
        return res;
    }
};

//Another thinking way
class Solution {
public:
    typedef pair<int, int> pp; // <value, index>

    static bool comp(const pp& i, const pp& j) { return (i.first < j.first); }

    vector<pp> mNums;

    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) {
            mNums.push_back(pp({nums[i], i}));
        }
        sort(mNums.begin(), mNums.end(), comp);
    }

    int pick(int target) {
        pair<vector<pp>::iterator, vector<pp>::iterator> bounds = equal_range(mNums.begin(), mNums.end(), pp({target,0}), comp);
        int s = bounds.first - mNums.begin();
        int e = bounds.second - mNums.begin();
        int r = e - s;
        return mNums[s + (rand() % r)].second;
    }
};
