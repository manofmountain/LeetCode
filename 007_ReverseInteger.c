


//8.42%
int reverse(int x) {
    //Check boundary conditions
	int valX = x;
	//Consider INT_MAX && INT_MIN
	#define INT_MAX 0x7fffffff
	#define INT_MIN 0x80000000
	if(x == INT_MIN)
		return 0;
	if(x < 0)
		valX = -x;
	if(valX < 10)
		return x;
	
	//Main routine
	long long rstX = 0;
	while(valX)
	{
		int unitX = valX % 10;
		rstX *= 10;
		rstX += unitX;
		valX /= 10;
	}
	
	if(rstX <= INT_MAX)
	{
		if(x > 0)
			return (int)rstX;
		else
			return -(int)rstX;
	}
	else
		return 0;
}

//24.6%
int reverse001(int x) {
    //Check boundary conditions
	int valX = x;
	//Consider INT_MAX && INT_MIN
	unsigned intMax = (unsigned)(~0) >> 1;
	unsigned intMin = intMax + 1;
	if(x == intMin)
		return 0;
	if(x < 0)
		valX = -x;
	if(valX < 10)
		return x;
	
	//Main routine
	long long unsigned rstX = 0;
	while(valX)
	{
		int unitX = valX % 10;
		rstX *= 10;
		rstX += unitX;
		valX /= 10;
	}
	

	if(rstX <= intMax)
	{
		if(x > 0)
			return (int)rstX;
		else
			return -(int)rstX;
	}
	else if(rstX == intMin && x < 0)
		return (int)rstX;
	else
		return 0;
}