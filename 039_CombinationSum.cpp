//33.57%
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
		if(candidates.empty()) return res;
		int size(candidates.size());
		return combinationSumHelper(candidates, 0, size, target);
    }
private:
	vector<vector<int>> combinationSumHelper(vector<int>& candidates, int left, int right, int target){
		vector<vector<int>> res;
		for(int i = left ; i < right; i++){
			int first = candidates[i];
			int times(1);
			while(first < target){
				vector<vector<int>> subRes = combinationSumHelper(candidates, i + 1, right, target - first);
				if(!subRes.empty()){
					for(auto vec : subRes){
						for(int j = 0; j < times; j++)
							vec.push_back(candidates[i]);
						res.push_back(vec);
					}
				}
				first += candidates[i];
				times++;
			}
			if(first == target){
				vector<int> vec(times, candidates[i]);
				res.push_back(vec);
			}
		}
		return res;
	}
};

//Use backtracing method
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if  (!target) {
			res.push_back(combination);
			return;
		}
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};