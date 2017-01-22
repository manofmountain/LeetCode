//36.49%
bool isAnagram(char* s, char* t) {
    #define ALPHA_NUM 26
	int count[ALPHA_NUM];
	for(int i = 0; i < ALPHA_NUM; i++)
		count[i] = 0;
	while(*s != '\0'){
		count[*s - 'a']++;
		s++;
	}
	while(*t != '\0'){
		if(--count[*t - 'a'] < 0)
			return false;
		t++;
	}
	for(int i = 0; i < ALPHA_NUM; i++)
	    if(count[i])
	        return false;
	return true;
}

bool isAnagram(char* s, char* t) 
{
    if(!s || !t)
		return	false;
	
	const int alphaNum = 26;
	int *alphaArray = (int *)calloc(alphaNum, sizeof(int));
	int i;
	for(i = 0; i < alphaNum; i++)
		alphaArray[i] = 0;
	int s_len = 0;
	int t_len = 0;
	while(*s != '\0')
	{
		int index = *s;
		alphaArray[index]++;
		s++;
		s_len++;
	}
	
	while(*t != '\0')
	{
		int index = *t;
		if(--alphaArray[index] < 0)
			return false;
		t++;
		t_len++;
	}
	
	if(s_len != t_len)
		return false;
	
	return true;	
}