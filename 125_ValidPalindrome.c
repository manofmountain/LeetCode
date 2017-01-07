//21.49%
bool isPalindrome(char* s) {
    if(!s)
		return true;
	char *front = s, *back = s + strlen(s);
	while(front < back){
		while(front < back && !isalnum(*front))
			front++;
		while(back > front && !isalnum(*back))
			back--;
		if(front < back)
			if(isalpha(*front) && isalpha(*back)){
				if(tolower(*front) != tolower(*back))
					return false;
			}
			else if(*front != *back)
				return false;
		front++;
		back--;
	}
	return true;	
}