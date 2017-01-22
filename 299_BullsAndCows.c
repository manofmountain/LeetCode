//12.5%
char *toString(int num){
	char *res = (char *)malloc(num + 1);
	int i = 0;
	if(!num)
		res[i++] = '0';
	while(num){
		res[i++] = num % 10 + '0';
		num /= 10;
	}
	res[i] = '\0';
	return res;
}

char* getHint(char* secret, char* guess) {
    //assert(secret && guess);
	#define DIGIT_NUM 10
	char *res = NULL;
	int cows = 0, bulls = 0;
	int secretMap[DIGIT_NUM] = {0};
	while(*secret != '\0'){
		if(*secret == *guess)
			cows++;
		else{
			//secretMap[*secret - '0']++;
			if(0 > secretMap[*secret - '0'])
				bulls++;
			if(0 < secretMap[*guess - '0'])
				bulls++;
			secretMap[*guess - '0']--;
			secretMap[*secret - '0']++;
		}
		secret++;
		guess++;
	}
	char *cowStr = toString(cows);
	char *bullStr = toString(bulls);
	int cowLen = strlen(cowStr);
	int bullLen = strlen(bullStr);
	int resLen = cowLen + bullLen + 2;
	res = (char *)malloc(resLen + 1);
	int i = 0;
	while(cowLen > 0)
		res[i++] = cowStr[--cowLen];
	res[i++] = 'A';
	while(bullLen > 0)
		res[i++] = bullStr[--bullLen];
	res[i++] = 'B';
	res[i] = '\0';
	free(cowStr);
	free(bullStr);
	return res;		
}