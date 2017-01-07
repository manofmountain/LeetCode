//18.89%

void clearFlags(int *flags, int size){
	for(int i = 0; i < size; i++)
		flags[i] = 0;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    //Check boundary conditions
	if(!board || 0 >= boardRowSize || 0 >= boardColSize)
		return false;
	
	int size = 9;
	int squareColSize = 3;
	int squareRowSize = 3;
	int *flags = (int *)malloc(size * sizeof(int));
	clearFlags(flags, size);
	
	//Check each row
	for(int i = 0; i < boardRowSize; i++){
		for(int j = 0; j < boardColSize; j++){
			char val = board[i][j];
			if(val >= '1' && val <= '9'){
				int index = val - '1';
				if(flags[index])
				{
					free(flags);
					return false;
				}
				else
					flags[index] = 1;
			}
			else if(val == '.')
				continue;
			else
			{
				free(flags);
				return false;
			}
		}
		clearFlags(flags, size);
	}
	
	//Check each col
	for(int i = 0; i < boardColSize; i++){
		for(int j = 0; j < boardRowSize; j++){
			char val = board[j][i];
			if(val >= '1' && val <= '9'){
				int index = val - '1';
				if(flags[index])
					{
						free(flags);
						return false;
					}
				else
					flags[index] = 1;
			}
			else if(val == '.')
				continue;
			else
				{
					free(flags);
					return false;
				}
		}
		clearFlags(flags, size);
	}
	
	//Check each square
	for(int i = 0; i < boardRowSize; i += squareRowSize){
		for(int j = 0; j < boardColSize; j += squareColSize){
			for(int k = i; k < i + squareRowSize; k++){
				for(int l = j ; l < j + squareColSize; l++){
					char val = board[k][l];
					if(val >= '1' && val <= '9'){
						int index = val - '1';
						if(flags[index])
						{
							free(flags);
							return false;
						}
						else
							flags[index] = 1;
					}
					else if(val == '.')
						continue;
					else
					{
						free(flags);
						return false;
					}
				}	
			}
			clearFlags(flags, size);
		}
	}
	
	free(flags);
	return true;
}