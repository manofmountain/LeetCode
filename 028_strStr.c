//I know there existed a KMP method which could be used to solve this problem


//Solution from LeetCode
int strStr(char *haystack, char *needle) {
        if (!haystack || !needle) return -1;
        for (int i = 0; ; ++i) {
            for (int j = 0; ; ++j) {
                if (needle[j] == 0) return i;
                if (haystack[i + j] == 0) return -1;
                if (haystack[i + j] != needle[j]) break;
            }
        }
}

//This is a wrong one
bool strCmp(char *haystack, char *needle){
	while(*haystack != '\0' && *needle != '\0'){
		if(*haystack == *needle){
			haystack++;
			needle++;
		}else
			return false;
	}
	if(*needle == '\0')
		return true;
	return false;
}

int strStr(char* haystack, char* needle) {
    if(*needle == '\0')
		return 0;
	
	int index = 0;
	while(*haystack != '\0'){
		if(strCmp(haystack, needle))
			return index;
		else{
			haystack++;
			//needle++;
			index++;
		}
	}
	
	return -1;
}