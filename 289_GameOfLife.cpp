//7.78%
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty())
			return;
		int rows(board.size()), cols(board[0].size());
		//First calculate out surrounding live numbers
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < cols; ++j){
				int num(0);
				if(i - 1 >= 0){
					num += (board[i - 1][j] & 1);
					if(j - 1 >= 0)
						num += (board[i - 1][j - 1] & 1);
					if(j + 1 < cols)
						num += (board[i - 1][j + 1] & 1);
				}
				if(j - 1 >= 0)
					num += (board[i][j - 1] & 1);
				if(j + 1 < cols)
					num += board[i][j + 1];
				if(i + 1 < rows){
					num += board[i + 1][j];
					if(j - 1 >= 0)
						num += board[i + 1][j - 1];
					if(j + 1 < cols)
						num += board[i + 1][j + 1];
				}
				board[i][j] |= (num << 1);
			}
		}
		
		//Then update life status
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < cols; ++j){
				int num(board[i][j] >> 1);
				if(board[i][j] & 1){
					if(num < 2 || num > 3)
						board[i][j] = 0;
					else
						board[i][j] = 1;
				}else{
					if(num == 3)
						board[i][j] = 1;
					else
						board[i][j] = 0;
				}
				//board[i][j] &= 1;
			}
		}
    }
};


//A Java solution from LeetCode which using the same idea
public void gameOfLife(int[][] board) {
    if (board == null || board.length == 0) return;
    int m = board.length, n = board[0].length;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int lives = liveNeighbors(board, m, n, i, j);

            // In the beginning, every 2nd bit is 0;
            // So we only need to care about when will the 2nd bit become 1.
            if (board[i][j] == 1 && lives >= 2 && lives <= 3) {  
                board[i][j] = 3; // Make the 2nd bit 1: 01 ---> 11
            }
            if (board[i][j] == 0 && lives == 3) {
                board[i][j] = 2; // Make the 2nd bit 1: 00 ---> 10
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] >>= 1;  // Get the 2nd state.
        }
    }
}

public int liveNeighbors(int[][] board, int m, int n, int i, int j) {
    int lives = 0;
    for (int x = Math.max(i - 1, 0); x <= Math.min(i + 1, m - 1); x++) {
        for (int y = Math.max(j - 1, 0); y <= Math.min(j + 1, n - 1); y++) {
            lives += board[x][y] & 1;
        }
    }
    lives -= board[i][j] & 1;
    return lives;
}

//A C++ solution which is more concise
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
}