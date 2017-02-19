//13.01%
bool isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	return false;
}

char* reverseVowels(char* s) {
    if(!s)
		return s;
	
	char *front = s;
	char *back = s + strlen(s) - 1;
	/*
	#define ALPHA_NUM 26
	int flags[ALPHA_NUM] = {0};
	flags['a' - 'a'] = 1;
	flags['e' - 'a'] = 1;
	flags['i' - 'a'] = 1;
	flags['o' - 'a'] = 1;
	flags['u' - 'a'] = 1;
	*/
	while(front < back){
		while(front < back && !isVowel(*front))
			front++;
		while(front < back && !isVowel(*back))
			back--;
		if(front < back){
			char temp = *front;
			*front = *back;
			*back = temp;
			front++;
			back--;
		}
	}
	return s;		
}