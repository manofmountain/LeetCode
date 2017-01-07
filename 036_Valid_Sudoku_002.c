void clearFlagArray(int *flagArray, int size)
{
	for(int i = 0; i < size; i++)
		flagArray[i] = 0;
}

bool isRowValid(char** board, int boardRowSize, int boardColSize, int *flagArray)
{
	for(int i = 0; i < boardRowSize; i++)
	{
		for(int j = 0; j < boardColSize; j++)
		{
			if(board[i][j] >= '1' && boardColSize <= '9')
			{
				int index = board[i][j] - '1';
				if(flagArray[index])
					return false;
				else
					flagArray[index] = 1;
			}
		}
		clearFlagArray(flagArray, 9);
	}
	return true;
}

bool isColValid(char** board, int boardRowSize, int boardColSize, int *flagArray)
{
	for(int i = 0; i < boardColSize; i++)
	{
		for(int j = 0; j < boardRowSize; j++)
		{
			if(board[j][i] >= '1' && boardColSize <= '9')
			{
				int index = board[j][i] - '1';
				if(flagArray[index])
					return false;
				else
					flagArray[index] = 1;
			}
		}
		clearFlagArray(flagArray, 9);
	}
	return true;
}

bool isGridValid(char** board, int boardRowSize, int boardColSize, int *flagArray)
{
	for(int i = 0; i < boardRowSize; i += 3)
	{
		for(int j = 0; j < boardColSize; j += 3)
		{
			for(int k = 0; k < 3; k++)
			{
				int m = i + k;
				for(int l = 0; l < 3; l++)
				{
					int n = j + l;
					if(board[m][n] >= '1' && board[m][n] <= '9')
					{
						int index = board[m][n] - '1';
						if(flagArray[index])
							return false;
						else
							flagArray[index] = 1;
					}
				}
			}
			clearFlagArray(flagArray, 9);
		}
	}
	return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
    if(!board || boardRowSize != 9 || boardColSize != 9)
		return false;
	int *flagArray = (int *)malloc(sizeof(int) * 9);
	clearFlagArray(flagArray, 9);
	
	bool flag = isRowValid(board, boardRowSize, boardColSize, flagArray);
	if(!flag)
	{
		free(flagArray);
		return false;
	}
	flag = isColValid(board, boardRowSize, boardColSize, flagArray);
	if(!flag)
	{
		free(flagArray);
		return false;
	}
	
	flag = isGridValid(board, boardRowSize, boardColSize, flagArray);
	if(!flag)
	{
		free(flagArray);
		return false;
	}
	
	free(flagArray);
	return true;
}