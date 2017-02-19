//40.97%
char* reverseString(char* s) {
    if(!s)
		return s;
	
	int len = strlen(s);
	char *front = s, *back = s + len - 1;
	while(front < back){
		char temp = *front;
		*front = *back;
		*back = temp;
		front++;
		back--;
	}
	return s;
}