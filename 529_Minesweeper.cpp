//31.57%
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.empty() || board[0].empty() || click.empty())
			return board;
		updateBoardHelper(board, click);
		return board;		
    }
private:
	void updateBoardHelper(vector<vector<char>>& board, vector<int> click){
		if(click[0] < 0 || click[0] >= board.size() || click[1] < 0 || click[1] >= board[0].size())
			return;
		if(board[click[0]][click[1]] == 'M'){
			board[click[0]][click[1]] = 'X';
			return;
		}
		if(board[click[0]][click[1]] != 'E')
			return;
		int cntMine(0);
		countMineNumber(board, click, cntMine);
		if(cntMine){
			board[click[0]][click[1]] = '0' + cntMine;
			return;
		}
		board[click[0]][click[1]] = 'B';
		updateBoardHelper(board, {click[0] - 1, click[1] - 1});
		updateBoardHelper(board, {click[0] - 1, click[1]});
		updateBoardHelper(board, {click[0] - 1, click[1] + 1});
		updateBoardHelper(board, {click[0], click[1] - 1});
		updateBoardHelper(board, {click[0], click[1] +1});
		updateBoardHelper(board, {click[0] + 1, click[1] - 1});
		updateBoardHelper(board, {click[0] + 1, click[1]});
		updateBoardHelper(board, {click[0] + 1, click[1] + 1});
	}
	void countMineNumber(vector<vector<char>>& board, vector<int> click, int& cntMine){
		cntMine += isMine(board, {click[0] - 1, click[1] - 1});
		cntMine += isMine(board, {click[0] - 1, click[1]});
		cntMine += isMine(board, {click[0] - 1, click[1] + 1});
		cntMine += isMine(board, {click[0], click[1] - 1});
		cntMine += isMine(board, {click[0], click[1] +1});
		cntMine += isMine(board, {click[0] + 1, click[1] - 1});
		cntMine += isMine(board, {click[0] + 1, click[1]});
		cntMine += isMine(board, {click[0] + 1, click[1] + 1});
	}
	int isMine(vector<vector<char>>& board, vector<int> click){
		if(click[0] < 0 || click[0] >= board.size() || click[1] < 0 || click[1] >= board[0].size())
			return 0;
		if(board[click[0]][click[1]] == 'M')
			return 1;
		return 0;
	}
};


//DFS solution. the same thinking like mine
public class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length, n = board[0].length;
        int row = click[0], col = click[1];
        
        if (board[row][col] == 'M') { // Mine
            board[row][col] = 'X';
        }
        else { // Empty
            // Get number of mines first.
            int count = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) continue;
                    int r = row + i, c = col + j;
                    if (r < 0 || r >= m || c < 0 || c < 0 || c >= n) continue;
                    if (board[r][c] == 'M' || board[r][c] == 'X') count++;
                }
            }
            
            if (count > 0) { // If it is not a 'B', stop further DFS.
                board[row][col] = (char)(count + '0');
            }
            else { // Continue DFS to adjacent cells.
                board[row][col] = 'B';
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i == 0 && j == 0) continue;
                        int r = row + i, c = col + j;
                        if (r < 0 || r >= m || c < 0 || c < 0 || c >= n) continue;
                        if (board[r][c] == 'E') updateBoard(board, new int[] {r, c});
                    }
                }
            }
        }
        
        return board;
    }
}

//BFS solution. As you can see the basic logic is almost the same as DFS. Only added a queue to facilitate BFS.
public class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length, n = board[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(click);
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int row = cell[0], col = cell[1];
            
            if (board[row][col] == 'M') { // Mine
                board[row][col] = 'X';
            }
            else { // Empty
                // Get number of mines first.
                int count = 0;
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i == 0 && j == 0) continue;
                        int r = row + i, c = col + j;
                        if (r < 0 || r >= m || c < 0 || c < 0 || c >= n) continue;
                        if (board[r][c] == 'M' || board[r][c] == 'X') count++;
                    }
                }
                
                if (count > 0) { // If it is not a 'B', stop further DFS.
                    board[row][col] = (char)(count + '0');
                }
                else { // Continue BFS to adjacent cells.
                    board[row][col] = 'B';
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            if (i == 0 && j == 0) continue;
                            int r = row + i, c = col + j;
                            if (r < 0 || r >= m || c < 0 || c < 0 || c >= n) continue;
                            if (board[r][c] == 'E') {
                                queue.add(new int[] {r, c});
                                board[r][c] = 'B'; // Avoid to be added again.
                            }
                        }
                    }
                }
            }
        }
        
        return board;
    }
}

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        reveal(board,click[0],click[1]);
        return board;
    }
    
    bool inboard(const vector<vector<char>>& board, int x, int y){
        return ( x>=0 && x<board.size() && y>=0 && y<board[0].size() );
    }
    
    void reveal(vector<vector<char>>& board, int x, int y){
        if(!inboard(board,x,y)) return;
        if(board[x][y] == 'E'){
            //search 8 adjacent squares
            int count = 0;
            if(inboard(board,x-1,y-1) && board[x-1][y-1] == 'M') count++;
            if(inboard(board,x-1,y  ) && board[x-1][y  ] == 'M') count++;
            if(inboard(board,x-1,y+1) && board[x-1][y+1] == 'M') count++;
            if(inboard(board,x  ,y-1) && board[x  ][y-1] == 'M') count++;
            if(inboard(board,x  ,y+1) && board[x  ][y+1] == 'M') count++;
            if(inboard(board,x+1,y-1) && board[x+1][y-1] == 'M') count++;
            if(inboard(board,x+1,y  ) && board[x+1][y  ] == 'M') count++;
            if(inboard(board,x+1,y+1) && board[x+1][y+1] == 'M') count++;

            if(count>0)
                board[x][y] = '0'+count;
            else{
                board[x][y] = 'B';
                reveal(board,x-1,y-1);
                reveal(board,x-1,y  );
                reveal(board,x-1,y+1);
                reveal(board,x  ,y-1);
                reveal(board,x  ,y+1);
                reveal(board,x+1,y-1);
                reveal(board,x+1,y  );
                reveal(board,x+1,y+1);
            }
        }
    }
};