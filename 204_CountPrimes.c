int countPrimes(int n) 
{	
	int i, j;
	int count = 0;
	int *flagNum = (int *)malloc(sizeof(int) * n);
	//int flagNum[n];
	for(i = 2; i < n; i++)
		flagNum[i] = 1;
	//int num = sqrt(n);
	for(i = 2; i * i < n; i++)
	{
		if(!flagNum[i])
			continue;
		else
		{
			j = i * i;
			while(j < n)
			{
				flagNum[j] = 0;
				j += i;
			}
		}
	}
	for(i = 2; i < n; i++)
		if(flagNum[i])
			count++;
	
	return count;
	
}