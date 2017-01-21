int titleToNumber(char* s) {
    int res = 0;
	while(*s != '\0'){
		res = res * 26 + (*s - 'A') + 1;
		s++;
	}
	return res;
}