//27.06%
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
			return false;
		int maxDim(0);
		int rowNum(matrix.size()), colNum(matrix[0].size());
		for(int i = 0; i < rowNum; ++i){
			//int dim(0);
			for(int j = 0; j < colNum; ++j){
				if(matrix[i][j] == '0')
					continue;
				//start en-large since left-top point
				int l(1);
				while(i + l < rowNum && j + l < colNum){
					if(matrix[i][j + l] == '0'){
						j += l;
						break;
					}
					if(matrix[i + l][j] == '0')
						break;
					int m;
					for(m = 1; m <= l; ++m){
						if(matrix[i + l][j + m] == '0')
							break;
						if(matrix[i + m][j + l] == '0'){
							j += l;
							break;
						}
					}
					if(m <= l)
						break;
					l += 1;
				}
				maxDim = max(maxDim, l);
			}
		}
		return maxDim * maxDim;	
    }
};

//A DP problem
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (!m) return 0;
    int n = matrix[0].size();
    vector<vector<int> > size(m, vector<int>(n, 0));
    int maxsize = 0;
    for (int j = 0; j < n; j++) {
        size[0][j] = matrix[0][j] - '0';
        maxsize = max(maxsize, size[0][j]);
    }
    for (int i = 1; i < m; i++) {
        size[i][0] = matrix[i][0] - '0';
        maxsize = max(maxsize, size[i][0]);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                maxsize = max(maxsize, size[i][j]);
            }
        }
    }
    return maxsize * maxsize;
}

//Only use o(row Dim)
int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size();
	if (!m) return 0;
	int n = matrix[0].size();
	vector<int> pre(m, 0);
	vector<int> cur(m, 0);
	int maxsize = 0;
	for (int i = 0; i < m; i++) {
		pre[i] = matrix[i][0] - '0';
		maxsize = max(maxsize, pre[i]);
	}
	for (int j = 1; j < n; j++) {
		cur[0] = matrix[0][j] - '0';
		maxsize = max(maxsize, cur[0]);
		for (int i = 1; i < m; i++) {
			if (matrix[i][j] == '1') {
				cur[i] = min(cur[i - 1], min(pre[i - 1], pre[i])) + 1;
				maxsize = max(maxsize, cur[i]);
			}
		}
		swap(pre, cur);
		fill(cur.begin(), cur.end(), 0);
	}
	return maxsize * maxsize;
}

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, 0);
    int maxsize = 0, pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                maxsize = max(maxsize, dp[i]);
            }
            else dp[i] = 0; 
            pre = temp;
        }
    }
    return maxsize * maxsize;
}

//The best one has ever seen
int maximalSquare(vector<vector<char>>& matrix) {
    int rst = 0;
    for(int ii=0; ii<matrix.size(); ++ii)
    {
        for(int jj=0; jj<matrix[0].size(); ++jj)
        {
            int a = (ii&&jj) ? matrix[ii-1][jj-1] : 0;
            int b = (ii) ? matrix[ii-1][jj] : 0;
            int c = (jj) ? matrix[ii][jj-1] : 0;

            matrix[ii][jj] = (matrix[ii][jj]>'0') ? (min(a, min(b, c))+1) : 0;
            
            rst = max(rst, matrix[ii][jj]*matrix[ii][jj]);
        }
    }
    return rst;
}

// a more normal one
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;
    int maxSq=0;
    int nRow=matrix.size();
    int nCol=matrix[0].size();
    vector<vector<int>> dp(nRow+1,vector<int>(nCol+1,0));
    //dp[i][j] represents max square ending at position (i-1, j-1)
    for(int i=1;i<=nRow;++i){
        for(int j=1;j<=nCol;++j){
            if(matrix[i-1][j-1]=='1'){
                dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                maxSq=max(maxSq,dp[i][j]);
            }
        }
    }
    return maxSq*maxSq;
}