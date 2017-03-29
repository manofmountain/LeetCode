//69.34%
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
		int m(matrix.size());
		if(0 == m){
			vector<int> temp;
			return temp;
		}
		int n(matrix[0].size());
		if(0 == n){
			vector<int> temp;
			return temp;
		}
		vector<int> res(m * n);
		int index(0);
		spiralOrderHelper(matrix, 0, 0, m, n, res, index);
		return res;
    }
private:
	void spiralOrderHelper(vector<vector<int>>& matrix, int startX, int startY, int m, int n, vector<int>& res, int index){
		if(m <= 0 || n <= 0)
			return;
		if(m == 1){
			for(int i = 0; i < n; i++)
				res[index++] = matrix[startX][i + startY];
			return;
		}
		if(n == 1){
			for(int i = 0; i < m; i++)
				res[index++] = matrix[i + startX][startY];
			return;
		}
		
		//Outter border pushed in
		for(int i = 0; i < n - 1; i++){
			res[index++] = matrix[startX][i + startY];
		}
		for(int i = 0; i < m - 1; i++){
			res[index++] = matrix[startX + i][startY + n - 1];
		}
		for(int i = 0; i < n - 1; i++){
			res[index++] = matrix[startX + m - 1][startY + n - i - 1];
		}
		for(int i = 0; i < m - 1; i++){
			res[index++] = matrix[startX + m - i - 1][startY];
		}	
		spiralOrderHelper(matrix, startX + 1, startY + 1, m - 2, n - 2, res, index);
	}
};


//A good solution and use a different thinking
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    int nr = matrix.size();     if (nr == 0) return res;
    int nc = matrix[0].size();  if (nc == 0) return res;
    
    vector<int> nSteps{nc, nr-1};
    
    int iDir = 0;   // index of direction.
    int ir = 0, ic = -1;    // initial position
    while (nSteps[iDir%2]) {
        for (int i = 0; i < nSteps[iDir%2]; ++i) {
            ir += dirs[iDir][0]; ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[iDir%2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
}

//This one has the same thinking with mine
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m * n);
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while (true) {
            // up
            for (int col = l; col <= r; col++) spiral[k++] = matrix[u][col];
            if (++u > d) break;
            // right
            for (int row = u; row <= d; row++) spiral[k++] = matrix[row][r];
            if (--r < l) break;
            // down
            for (int col = r; col >= l; col--) spiral[k++] = matrix[d][col];
            if (--d < u) break;
            // left
            for (int row = d; row >= u; row--) spiral[k++] = matrix[row][l];
            if (++l > r) break;
        }
        return spiral;
    }
};