//77.88%
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix): sumMatrix(matrix.begin(), matrix.end()) {
		if(matrix.empty() || matrix[0].empty())
			return;
        int rows(matrix.size()), cols(matrix[0].size());
		sumMatrix[0][0] = matrix[0][0];
		for(int i = 1; i < cols; ++i)
			sumMatrix[0][i] = sumMatrix[0][i - 1] + matrix[0][i];
		for(int i = 1; i < rows; ++i)
			sumMatrix[i][0] = sumMatrix[i - 1][0] + matrix[i][0];
		for(int i = 1; i < rows; ++i){
			for(int j = 1; j < cols; ++j)
				sumMatrix[i][j] = sumMatrix[i - 1][j] + sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1] + matrix[i][j];
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		if(sumMatrix.empty())
			return 0;
		if(row1 && col1)
			return sumMatrix[row2][col2] - sumMatrix[row1 - 1][col2] + sumMatrix[row1 - 1][col1 - 1] - sumMatrix[row2][col1 - 1];
		if(row1)
			return sumMatrix[row2][col2] - sumMatrix[row1 - 1][col2];
		if(col1)
			return sumMatrix[row2][col2] - sumMatrix[row2][col1 - 1];
		return sumMatrix[row2][col2];
    }
private:
	vector<vector<int> > sumMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
 
 //Same thinking as mine but more concise
 class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};