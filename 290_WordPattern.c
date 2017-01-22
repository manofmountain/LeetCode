//13.64%
bool wordPattern(char* pattern, char* str) {
	if(!pattern && !str)
		return true;
	if(!pattern || !str)
		return false;
	
    #define ALPHA_NUM 26
	char* map[ALPHA_NUM];
	for(int i = 0; i < ALPHA_NUM; i++)
		map[i] = NULL;
	char *curr = str, *pre = str;
	while(*pattern != '\0'){
		char c = *pattern;
		while(*curr == ' ')
			curr++;
		pre = curr;
		while(*curr != ' ' && *curr != '\0')
			curr++;
		if(*curr != '\0'){
			*curr = '\0';
			curr++;
		}
		
		//Means 'str' shorter than 'pattern'
		if(pre == curr)
			return false;
			
		if(!map[c - 'a'])
			map[c - 'a'] = pre;
		else if(0 != strcmp(pre, map[c - 'a']))
			return false;
		pattern++;
	}
	
	//Means 'str' longer than 'pattern'
	if(*curr != '\0')
		return false;
	//Check the hash table
	for(int i = 0; i < ALPHA_NUM - 1; i++){
		for(int j = i + 1; j < ALPHA_NUM; j++){
			if(map[i] && map[j] && 0 == strcmp(map[i], map[j]))
				return false;
		}
	}
	return true;				
}