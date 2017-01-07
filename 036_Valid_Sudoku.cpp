
//A good solution from LeetCode website

//82.39%
class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
		#define ROW_SIZE 9
		#define COL_SIZE 9
		#define SQUARE_SIZE 9
		#define SQUARE_ROW_SIZE 3
		#define SQUARE_COL_SIZE 3
		#define SYMBOL_SIZE 9
        int flagRows[ROW_SIZE][SYMBOL_SIZE] = {0}, flagCols[COL_SIZE][SYMBOL_SIZE] = {0}, flagSquares[SQUARE_SIZE][SYMBOL_SIZE] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '1', k = i / SQUARE_ROW_SIZE * SQUARE_COL_SIZE + j / SQUARE_COL_SIZE;
                    if(flagRows[i][num] || flagCols[j][num] || flagSquares[k][num])
                        return false;
                    flagRows[i][num] = flagCols[j][num] = flagSquares[k][num] = 1;
                }
        
        return true;
    }
};

//Another good solution from LeetCOde
//30.43%
bool isValidSudoku(vector<vector<char>>& board) {
	const int boardColSize = 9;
	const int boardRowSize = 9;
	const int boardSquareSize = 9;
	const int squareRowSize = 3;
	const int squareColSize = 3;
    vector<short> col(boardColSize, 0);
    vector<short> square(boardSquareSize, 0);
    vector<short> row(boardRowSize, 0);
    for (int i = 0; i < boardRowSize; i++)
     for (int j = 0; j < boardColSize; j++) {
         if (board[i][j] != '.') {
             int idx = 1 << (board[i][j] - '0');
             if (row[i] & idx || col[j] & idx || square[i/squareRowSize * squareColSize + j / squareColSize] & idx)
                return false;
            row[i] |= idx;
            col[j] |= idx;
            square[i/squareRowSize * squareColSize + j/squareColSize] |= idx;
         }
     }
     return true;
}