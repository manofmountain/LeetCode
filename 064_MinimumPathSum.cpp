//28.72%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
		vector<int> curr(grid[m - 1]);
		for(int i = n - 2; i >= 0; i--)
			curr[i] = curr[i + 1] + grid[m - 1][i];
		
		for(int i = m - 2; i >= 0; i--){
			curr[n - 1] += grid[i][n - 1];
			for(int j = n - 2; j >= 0; j--){
				curr[j] = min(curr[j], curr[j + 1]) + grid[i][j];
			}
		}
		return curr[0];
    }
};
//Suddenly, i realized from 'up left' to 'down right' problem equals to the problem from 'down right' to 'top left'..^_^ 
//Same principle like mine
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};