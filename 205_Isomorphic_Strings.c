//35.29%
bool isIsomorphic(char* s, char* t) {
	#define CHAR_NUM 256
	char mapTableS[CHAR_NUM];
	char mapTableT[CHAR_NUM];
	for(int i = 0; i < CHAR_NUM; i++){
		mapTableS[i] = '0';
		mapTableT[i] = '0';
	}
		
	while(*s != '\0'){
		if(mapTableT[*t] == '0' && mapTableS[*s] == '0'){
			mapTableT[*t] = *s;
			mapTableS[*s] = *t;
		}
		else if(mapTableT[*t] != *s || mapTableS[*s] != *t)
			return false;
		s++;
		t++;
	}
	return true;		
}

//A solution from LeetCode
bool isIsomorphic(char* s, char* t) {
	char charArrS[256] = { 0 };
	char charArrT[256] = { 0 };
	int i = 0;
	while (s[i] !=0)
	{
		if (charArrS[s[i]] == 0 && charArrT[t[i]] == 0)
		{
			charArrS[s[i]] = t[i];
			charArrT[t[i]] = s[i];
		}
		else
		if (charArrS[s[i]] != t[i] || charArrT[t[i]] != s[i])
			return false;
		i++;
	}

	return true;
}