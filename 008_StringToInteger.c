//10.87
int myAtoi(char* str) {
    //Check boundary conditions
	if(!str || !strlen(str))
		return 0;
	
	//Find first un-blank character
	char *ptr = str;
	while(*ptr == ' ')
		ptr++;
	long rst = 0;
	bool flag = true; // false while encounter '-', true otherwise
	
	//Check first non-blank character
	char firstChar = *ptr;
	if(firstChar == '-')
	{
		flag = false;
		ptr++;
	}
	else if(firstChar == '+')
	{
		ptr++;
	}
	else if(firstChar < '0' || firstChar > '9')
		return 0;
	
	
	//Check the second integer unit
	//char secChar = *ptr;
	//if(secChar < '0' || secChar > '9')
		//return 0;
	
	//Process the string iteratively
	while(*ptr != '\0')
	{
		char currChar = *ptr;
		if(currChar >= '0' && currChar <= '9')
		{
			int currUnit = currChar - '0';	
			rst *= 10;
			rst += currUnit;
			ptr++;
			//Check if it is overflow
			if(rst < INT_MAX)
				continue;
			else if(flag)
				return INT_MAX;
			else if(-rst <= INT_MIN)
				return INT_MIN;
		}
		else
			break;
	}
	
	if(!flag)
		rst = -rst;
	return rst;		
}

int myAtoi001(char* str) {
    //Check boundary conditions
	if(!str || !strlen(str))
		return 0;
	
	//Find first un-blank character
	char *ptr = str;
	while(*ptr == ' ')
		ptr++;
	long rst = 0;
	bool flag = true; // false while encounter '-', true otherwise
	
	//Check first non-blank character
	char firstChar = *ptr;
	if(firstChar == '-')
	{
		flag = false;
		ptr++;
	}
	else if(firstChar == '+')
	{
		ptr++;
	}
	else if(firstChar < '0' || firstChar > '9')
		return 0;
	
	
	//Check the second integer unit
	char secChar = *ptr;
	if(secChar < '0' || secChar > '9')
		return 0;
	
	//Process the string iteratively
	while(*ptr != '\0')
	{
		char currChar = *ptr;
		if(currChar >= '0' && currChar <= '9')
		{
			int currUnit = currChar - '0';	
			rst *= 10;
			rst += currUnit;
			//Check if it is overflow
			if(flag && rst >= INT_MAX)
				return INT_MAX;
			if(!flag && -rst <= INT_MIN)
				return INT_MIN;
			ptr++;
		}
		else
		{
			//ptr++;
			break;
		}
	}
	
	if(!flag)
		rst = -rst;
	return rst;		
}