//1.37%
int compareVersion(char* version1, char* version2) {
    char *ptr1 = version1, *ptr2 = version2;
	while(*ptr1 != '\0' && *ptr2 != '\0'){
		int ver1 = 0, ver2 = 0;
		while(*ptr1 != '\0' && *ptr1 != '.'){
			ver1 = ver1 * 10 + (*ptr1 - '0');
			ptr1++;
		}
		
		
		while(*ptr2 != '\0' && *ptr2 != '.'){
			ver2 = ver2 * 10 + (*ptr2 - '0');
			ptr2++;
		}
		
		if(ver1 > ver2)
			return 1;
		else if(ver1 < ver2)
			return -1;
		if(*ptr1 == '.')
			ptr1++;
		if(*ptr2 == '.')
			ptr2++;
	}

	while(*ptr1 != '\0'){
		if(*ptr1 == '.')
			ptr1++;
		int ver1 = *ptr1 - '0';
		if(ver1)
			return 1;
		ptr1++;	
	}

	while(*ptr2 != '\0'){
		if(*ptr2 == '.')
			ptr2++;
		int ver2 = *ptr2 - '0';
		if(ver2)
			return -1;
		ptr2++;
	}

	return 0;
}