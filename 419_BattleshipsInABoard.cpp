//29.63%
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
			return 0;
		
		int cnt(0);
		for(int i = 0; i < board.size(); ++i){
			for(int j = 0; j < board[0].size(); ++j){
				if(board[i][j] == 'X'){
					//Check up
					if(i > 0 && board[i - 1][j] == 'X')
						continue;
					
					//Check left
					if(j > 0 && board[i][j - 1] == 'X')
						continue;
					
					++cnt;
				}
			}
		}
		return cnt;
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
			return 0;
		
		int cnt(0);
		for(int i = 0; i < board.size(); ++i){
			for(int j = 0; j < board[0].size(); ++j){
				if(board[i][j] == 'X'){
					if((i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
						++cnt;
				}
			}
		}
		return cnt;
    }
};




//Two ideas which are very insteresting
//DFS:
class Solution {
public:
    int m, n; 
    vector<vector<bool>> flag;
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.' || flag[i][j]) return;
        flag[i][j] = true;
        for (int d = 0; d < 4; ++d) dfs(board, i+go[d][0], j+go[d][1]);
    }

    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        m = board.size(), n = board[0].size();
        flag.resize(m, vector<bool>(n, false));
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'X' && !flag[i][j]) {
                    ++result;
                    dfs(board, i, j);
                }
        return result;
    }
};

//BFS
class Solution {
public:
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !flag[i][j]) {
                    ++result;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto t = q.front(); q.pop();
                        flag[t.first][t.second] = true;
                        for (int d = 0; d < 4; ++d) {
                            int ni = t.first+go[d][0], nj = t.second+go[d][1];
                            if (ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] == '.' || flag[ni][nj]) continue;
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
        return result;
    }
};