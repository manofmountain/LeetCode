//57.46%
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
			return;
		int m(matrix.size()), n(matrix[0].size());
		if(n == 0)
			return;
		
		set<int> rows, cols;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(!matrix[i][j]){
					rows.insert(i);
					cols.insert(j);
				}
		for(set<int>::iterator ite = rows.begin(); ite != rows.end(); ite++){
			for(int j = 0; j < n; j++)
				matrix[*ite][j] = 0;
		}
		for(set<int>::iterator ite = cols.begin(); ite != cols.end(); ite++){
			for(int i = 0; i < m; i++)
				matrix[i][*ite] = 0;
		}
    }
};

//This only used O(1)
void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}