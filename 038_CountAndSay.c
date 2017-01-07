//First trying recursive method
//20.55%
char* countAndSay(int n) {
    if(0 >= n)
		return NULL;
	char *rst = NULL;
	if(n == 1){
		rst = (char *)malloc(sizeof(char) * 2);
		*rst = '1';
		*(rst + 1) = '\0';
	}else{
		char *prev = countAndSay(n - 1);
		rst = (char *)malloc(2 * strlen(prev) + 1);
		char *curr = rst;
		int count = 1;
		char *prevHead = prev;
		char val = *prev++;
		while(*prev != '\0'){
			if(*prev == val){
				count++;
			}else{
				*curr++ = '0' + count;
				*curr++ = val;
				val = *prev;
				count = 1;
			}
			prev++;
		}
		if(count){
			*curr++ = '0' + count;
			*curr++ = val;
			*curr = '\0';
		}
		free(prevHead);
	}
	
	return rst;
}