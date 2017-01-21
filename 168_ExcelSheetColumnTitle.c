char* convertToTitleRecursive(int n, int depth){
	if(!n)
		return NULL;
	char *str = (char *)malloc(depth + 1);
	*str = (n - 1) % 26 + 'A';
	*(str + 1) = '\0';
	char *leftStr = convertTotitleRecursive((n - 1) / 26, depth + 1);
	if(!leftStr)
		return str;
	strcat(leftStr, str);
	free(str);
	return leftStr;
}
char* convertToTitle(int n) {
	return convertToTitleRecursive(n, 1);
}