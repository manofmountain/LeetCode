//0.72%
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
		if(n <= 0)
			return res;
		grayCodeHelper(res, n);
		return res;
    }
private:
	void grayCodeHelper(vector<int>& res, int n){
		if(n == 0)
			return;
		grayCodeHelper(res, n - 1);
		int size(res.size());
		for(int i = size - 1; i >= 0; i--){
			res.push_back(res[i] | (1 << (n - 1)));
		}
	}
};

//54.42%
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
		for(int i = 1; i <= n; i++){
			for(int j = res.size(); j > 0; j--){
				res.push_back(res[j - 1] | (1 << (i - 1)));
			}
		}
		return res;
    }
};