//1.49%
char* longestCommonPrefix(char** strs, int strsSize) {
    if(!strs || 0 >= strsSize)
		return "";
	if(1 == strsSize)
		return strs[0];
	
	//Track position of longest common prefix
	int pos = 0;
	bool flag = true; //'false' while need to break out the circular
	
	char charFirst = strs[0][pos];
	while(charFirst != '\0')
	{
		for(int index = 1; index < strsSize; index++)
			if(strs[index][pos] != charFirst || strs[index][pos] == '\0')
			{
				flag = false;
				break;
			}
		if(!flag)
			break;
		pos++;
		charFirst = strs[0][pos];
	}
	
	//Now we know the common prefix's length as 'pos'
	if(pos <= 0)
		return "";
		
	char *rstStr = (char *)malloc(pos + 1);
	for(int index = 0; index < pos; index++)
		rstStr[index] = strs[0][index];
	rstStr[pos] = '\0';
	
	return rstStr;		
}

//1.49%
char* longestCommonPrefix001(char** strs, int strsSize) {
    if(!strs || 0 >= strsSize)
		return "";
	if(1 == strsSize)
		return strs[0];
	
	//Track position of longest common prefix
	int pos = 0;
	bool flag = true; //'false' while need to break out the circular
	//Check if there exist 'empty' pointer
	for(int index = 0; index < strsSize; index++)
		if(*strs[index] == '\0')
			return "";
	while(true)
	{
		char charFirst = strs[0][pos];
		if(charFirst == '\0')
			break;
		for(int index = 1; index < strsSize; index++)
			if(strs[index][pos] != charFirst || strs[index][pos] == '\0')
			{
				//pos--;
				flag = false;
				break;
			}
		if(!flag)
			break;
		pos++;
	}
	
	//Now we know the common prefix's length as 'pos'
	char *rstStr = (pos <= 0 ? "" : (char *)malloc(pos + 1));
	if(pos <= 0)
		return "";
	for(int index = 0; index < pos; index++)
		rstStr[index] = strs[0][index];
	rstStr[pos] = '\0';
	
	return rstStr;
		
}