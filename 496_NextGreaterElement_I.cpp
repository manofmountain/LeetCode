//1.85%
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
		int size(nums.size());
		for(int findNum : findNums){
			for(int i = 0; i < size; i++){
				if(nums[i] == findNum)
					res.push_back(numNextGreater(nums, i, size));
			}
		}
		return res;
    }
private:
	int numNextGreater(vector<int>& nums, int start, int end){
		int j = start + 1;
		while(j < end){
			if(nums[j] > nums[start])
				return nums[j];
			j++;
		}
		return -1;
	}
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};