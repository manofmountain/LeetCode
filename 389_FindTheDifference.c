//16.27%
char findTheDifference(char* s, char* t) {
    if(!s || !t)
		return ' ';
	char res = 0;
	while(*s != '\0')
		res ^= (*s++);
	while(*t != '\0')
		res ^= (*t++);
	return res;
}