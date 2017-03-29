//30.63%
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 2)
			return vector<int>();
		int left(0), right(numbers.size() - 1);
		
		while(left < right){
			int sum(numbers[left] + numbers[right]);
			if(sum < target)
				++left;
			else if(sum > target)
				--right;
			else{
				vector<int> res(2, left + 1);
				res[1] = right + 1;
				return res;
			}
		}
		return vector<int>();
    }
};