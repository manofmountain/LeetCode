//52.25%
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty())
			return nums;
		
		int size(nums.size());
		vector<int> res(size, -1);
		stack<int> positions;
		for(int i = 0; i < nums.size(); ++i){
			while(!positions.empty() && nums[positions.top()] < nums[i]){
				res[positions.top()] = nums[i];
				positions.pop();
			}
			positions.push(i);
		}
		
		int start(0);
		while(!positions.empty() && start < positions.top()){
			if(nums[start] > nums[positions.top()]){
				res[positions.top()] = nums[start];
				positions.pop();
			}else
				++start;
		}
		return res;
    }
};

//This way is more concise
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s; // index stack
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n]; 
            while (!s.empty() && nums[s.top()] < num) {
                next[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }   
        return next;
    }