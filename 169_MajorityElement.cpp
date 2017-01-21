//22.03%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> table;
		for(int i = 0; i < nums.size(); i++){
			if(table.find(nums[i]) == table.end())
				table[nums[i]] = 1;
			else
				table[nums[i]]++;
		}
		int maxVal = 0, maxKey = 0;
		for(map<int, int>::iterator tbl_ite = table.begin(); tbl_ite != table.end(); tbl_ite++){
			if(tbl_ite -> second > maxVal){
				maxVal = tbl_ite -> second;
				maxKey = tbl_ite -> first;
			}
		}
		return maxKey;		
	}
};

//1.64%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		if(nums.size() == 1)
			return nums[0];
		vector<int>& numsLeft(nums.begin(), nums.begin() + nums.size() / 2);
		vector<int>& numsRight(nums.begin() + nums.size() / 2, nums.end());
		int left = majorityElement(numsLeft);
		int right = majorityElement(numsRight);
		if(left == right)
			return left;
		int leftNum(0), rightNum(0);
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] == left)
				leftNum++;
			else if(nums[i] == right)
				rightNum++;
		}
		if(leftNum > rightNum)
			return left;
		return right;
	}
};

//Wonderful solutions
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    } 
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
}; 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    } 
};