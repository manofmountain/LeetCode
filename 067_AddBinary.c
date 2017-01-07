
//19.15%
char* addBinary(char* a, char* b) {
    if(!a || !b)
		return NULL;
	
	int lenA = strlen(a);
	int lenB = strlen(b);
	
	//First ensure 'a' points to the longer one
	if(lenA < lenB){
		int temp = lenA;
		lenA = lenB;
		lenB = temp;
		char *ptrTemp = a;
		a = b;
		b = ptrTemp;
	}
	
	int addition = 0;
	int diffLen = lenA - lenB;
	for(int i = lenB - 1; i >= 0; i--){
		int temp = (a[i + diffLen] - '0') + (b[i] - '0') + addition;
		addition = temp >> 1;
		a[i + diffLen] = '0' + (temp & 1);
	}
	for(int i = diffLen - 1; i >= 0; i--){
		if(!addition)
			return a;
		int temp = (a[i] - '0') + addition;
		addition = temp >> 1;
		a[i] = '0' + (temp & 1);
	}
	if(!addition)
		return a;
		
	char *rst = (char *)malloc(lenA + 2);
	rst[0] = '1';
	for(int i = 0; i < lenA; i++)
		rst[i + 1] = a[i];
	rst[lenA + 1] = '\0';
	return rst;
}