class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
		vector<int> combination;
		int start(0);
		sort(begin(candidates), end(candidates));
		combinationSum2Helper(candidates, target, 0, res, combination);
		return res;
    }
private:
	void combinationSum2Helper(vector<int>& candidates, int target, int start, vector<vector<int>>& res, vector<int> combination){
		if(!target){
			res.push_back(combination);
			return;
		}
		int size(candidates.size());
		for(int i = start; i < size && candidates[i] <= target;){
			combination.push_back(candidates[i]);
			combinationSum2Helper(candidates, target - candidates[i], i + 1, res, combination);
			combination.pop_back();
			i++;
			while(i < size && candidates[i] == candidates[i - 1]) i++;
		}
	}
};