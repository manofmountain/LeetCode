//38.15%
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
			return 0;
		char mark('A');
		int cnt(0);
		for(int i = 0; i < grid.size(); ++i){
			for(int j = 0; j < grid[0].size(); ++j){
				if(grid[i][j] == '1'){
					++cnt;
					//grid[i][j] = 'A';
					infectBoundaries(grid, i, j, grid.size(), grid[0].size());
				}
			}
		}
		//Recover
		for(int i = 0; i < grid.size(); ++i){
			for(int j = 0; j < grid[0].size(); ++j){
				if(grid[i][j] == 'A')
					grid[i][j] = '1';
			}
		}
		return cnt;
    }
private:
	void infectBoundaries(vector<vector<char> >& grid, int x, int y, int rowNum, int colNum){
		grid[x][y] = 'A';
		if(x + 1 < rowNum && grid[x + 1][y] == '1')
			infectBoundaries(grid, x + 1, y, rowNum, colNum);
		if(x - 1 >= 0 && grid[x - 1][y] == '1')
			infectBoundaries(grid, x - 1, y, rowNum, colNum);
		if(y + 1 < colNum && grid[x][y + 1] == '1')
			infectBoundaries(grid, x, y + 1, rowNum, colNum);
		if(y - 1 >= 0 && grid[x][y - 1] == '1')
			infectBoundaries(grid, x, y - 1, rowNum, colNum);
	}		
};