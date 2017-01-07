
//%57.62
char* convert(char* s, int numRows) {
    
	//First check the boundaries
	if(!s || 1 >= numRows)
		return s;
	int lengthS = strlen(s);
	if(lengthS <= numRows)
		return s;
	
	char *rst = (char *)malloc(lengthS + 1);
	//Start the calculating here
	int srcIndex = 0;
	int rstIndex = 0;
	bool flag = true;
	int deltaIndexDown = (numRows - 1) << 1;
	int deltaIndexUp;
	
	//For row '0' specifically
	while(srcIndex < lengthS)
	{
		rst[rstIndex++] = s[srcIndex];
		srcIndex += deltaIndexDown;
	}
	for(int row = 1; row < numRows - 1; row++)
	{   
	    srcIndex = row;
	    flag = true;
		deltaIndexDown = (numRows - row - 1) << 1;
		deltaIndexUp = row << 1;
		while(srcIndex < lengthS)
		{
			rst[rstIndex++] = s[srcIndex];
			if(flag)
				srcIndex += deltaIndexDown;
			else
				srcIndex += deltaIndexUp;
			flag = !flag;
		}
	}
	//For row 'numRows - 1' specificily
	deltaIndexUp = (numRows - 1) << 1;
	srcIndex = numRows - 1;
	while(srcIndex < lengthS)
	{
		rst[rstIndex++] = s[srcIndex];
		srcIndex += deltaIndexUp;
	}
	
	rst[rstIndex] = '\0';
	return rst;
}


//57.62% faster
char* convert001(char* s, int numRows) {
    
	//First check the boundaries
	if(!s || 1 >= numRows)
		return s;
	int lengthS = strlen(s);
	if(lengthS <= numRows)
		return s;
	
	char *rst = (char *)malloc(lengthS + 1);
	//Start the calculating here
	int srcIndex = 0;
	int rstIndex = 0;
	bool flag = true;
	for(int row = 0; row < numRows; row++)
	{   
	    srcIndex = row;
	    if(row != numRows - 1)
			flag = true;
		else
			flag = false;
		int deltaIndexDown = (numRows - row - 1) << 1;
		int deltaIndexUp = row << 1;
		while(srcIndex < lengthS)
		{
			rst[rstIndex++] = s[srcIndex];
			if(flag)
				srcIndex += deltaIndexDown;
			else
				srcIndex += deltaIndexUp;
			
			if(!row || row == numRows - 1)
			    continue;
			else
			    flag = !flag;
		}
	}
	
	rst[rstIndex] = '\0';
	return rst;
}