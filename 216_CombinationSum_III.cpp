//64.98%
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
		if((19 - k) * k / 2 < n)
			return {};
		if(1 == k)
			return vector<vector<int> >(1, vector<int>(1, n));
		vector<vector<int> > res;
		vector<int> vec(k);
		for(int i = 1; i <= n / 2; ++i){
			vec[0] = i;
			combinationSum3Helper(res, vec, 1, k, n - i);
		}
		return res;
    }
private:
	void combinationSum3Helper(vector<vector<int> >& res, vector<int>& vec, int start, int k, int n){
		if(start == k - 1){
			if(n > vec[start - 1] && n <= 9){
				vec[start] = n;
				res.push_back(vec);
			}
			return;
		}
		for(int i = vec[start - 1] + 1; i <= n / 2; ++i){
			vec[start] = i;
			combinationSum3Helper(res, vec, start + 1, k, n - i);
		}
	}			
};

//A back tracing one like mine
class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
    if (sol.size() < k) {
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        sol.push_back(i);
        combination(result, sol, k, n - i);
        sol.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
  }
}