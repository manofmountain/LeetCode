//51.23%
int firstUniqChar(char* s) {
	if(!s)
		return -1;
    #define CHAR_NUM 256
	int counter[CHAR_NUM] = {0};
	//int indice[CHAR_NUM] = {-1};
	char *ptr = s;
	int i = 0;
	while(ptr[i] != '\0'){
		//if(!counter[ptr[i]])
		//	indice[ptr[i]] = i;
		counter[ptr[i]]++;
		i++;
	}
	i = 0;
	while(ptr[i] != '\0'){
		if(counter[ptr[i]] == 1)
			return i;
			//return indice[ptr[i]];
		i++;
	}
	return -1;			
}