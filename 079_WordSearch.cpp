//77.37%
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int size(word.size());
		if(size == 0)
			return false;
		int rowNum(board.size());
		if(rowNum == 0)
			return false;
		int colNum(board[0].size());
		if(colNum == 0)
			return false;
		//if(size > rowNum * colNum)
		//	return false;
		
		//Find available start positions
		vector<vector<int>> traces(rowNum, vector<int>(colNum, 0));
		//vector<pair<int, int>> startPositions;
		for(int i = 0; i < rowNum; i++){
			for(int j = 0; j < colNum; j++){
				if(board[i][j] == word[0]){
					pair<int, int> startPos(i, j);
					traces[i][j] = 1;
					if(correctPosition(board, traces, word, startPos, rowNum, colNum, 1, size))
						return true;
					traces[i][j] = 0;
				}
			}
		}
		return false;
    }
private:
	bool correctPosition(vector<vector<char>>& board, vector<vector<int>>& traces, string& word, pair<int, int>& startPos, int rows, int cols, int index, int size){
		if(index == size)
			return true;
		
		//Try left
		if(startPos.second > 0 && !traces[startPos.first][startPos.second - 1] && word[index] == board[startPos.first][startPos.second - 1]){
			startPos.second--;
			//index++;
			traces[startPos.first][startPos.second] = 1;
			if(correctPosition(board, traces, word, startPos, rows, cols, index + 1, size))
				return true;
			traces[startPos.first][startPos.second] = 0;
			//index--;
			startPos.second++;
		}
		
		//Try right
		if(startPos.second < cols - 1f && !traces[startPos.first][startPos.second + 1] && word[index] == board[startPos.first][startPos.second + 1]){
			startPos.second++;
			//index++;
			traces[startPos.first][startPos.second] = 1;
			if(correctPosition(board, traces, word, startPos, rows, cols, index + 1, size))
				return true;
			traces[startPos.first][startPos.second] = 0;
			//index--;
			startPos.second--;
		}
		
		//Try up
		if(startPos.first > 0 && !traces[startPos.first - 1][startPos.second] && word[index] == board[startPos.first - 1][startPos.second]){
			startPos.first--;
			//index++;
			traces[startPos.first][startPos.second] = 1;
			if(correctPosition(board, traces, word, startPos, rows, cols, index + 1, size))
				return true;
			traces[startPos.first][startPos.second] = 0;
			//index--;
			startPos.first++;
		}
		
		//Try down
		if(startPos.first < rows - 1 && !traces[startPos.first + 1][startPos.second] && word[index] == board[startPos.first + 1][startPos.second]){
			startPos.first++;
			//index++;
			traces[startPos.first][startPos.second] = 1;
			if(correctPosition(board, traces, word, startPos, rows, cols, index + 1, size))
				return true;
			traces[startPos.first][startPos.second] = 0;
			//index--;
			startPos.first--;
		}
		return false;
	}		
};

//Same idea, but it's smarter and use no additional spaces
class Solution {
    public:
    	 bool exist(vector<vector<char> > &board, string word) {
    		 m=board.size();
    		 n=board[0].size();
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
    				if(isFound(board,word.c_str(),x,y))
    					return true;
                }
            return false;
        }
    private:
    	int m;
    	int n;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
        {
    		if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
    			return false;
            if(*(w+1)=='\0')
                return true;
    		char t=board[x][y];
    		board[x][y]='\0';
    		if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
    			return true; 
    		board[x][y]=t;
            return false;
        }
    };

//A simple use with DFS	
class Solution {
private:
    bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen)
    {
        char curC;
        bool res = false;
        if( (curC = board[row][col]) != word[start]) return false;
        if(start==sLen-1) return true;
        board[row][col] = '*';
        if(row>0) res = dfs(board, row-1, col, word, start+1, M, N, sLen);
        if(!res && row < M-1) res = dfs(board, row+1, col, word, start+1, M, N, sLen);
        if(!res && col > 0)   res = dfs(board, row, col-1, word, start+1, M, N, sLen);
        if(!res && col < N-1) res = dfs(board,  row, col+1, word, start+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M,N,i,j,sLen = word.size();
        if( (M=board.size()) && (N=board[0].size()) && sLen)
        {
            for(i=0; i<M; ++i)
                for(j=0; j<N; ++j)
                    if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
        }
        return false;
    }
};