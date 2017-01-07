//56.93%
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
		if(1 > numRows)
			return res;
		vector<int> row(1, 1);
		res.push_back(row);
		for(int i = 1; i < numRows; i++){
			vector<int> row;
			row.push_back(1);
			for(int j = 0; j < res[i - 1].size() - 1; j++){
				row.push_back(res[i - 1][j] + res[i - 1][j + 1]);
			}
			row.push_back(1);
			res.push_back(row);
		}
		return res;
    }
};

//Method from LeetCode
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(auto i=0;i<numRows;++i)
        {
            res.push_back(vector<int>(i+1,1));
            for(auto j=1; j<i; ++j) res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};