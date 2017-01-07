
//3.17%
int lengthOfLastWord(char* s) {
    if(!s)
		return 0;
	
	char *curr = s;
	int sum = 0;
	bool flag = false;
	int preSum = 0;
	while(*curr != '\0')
	{
		if(*curr == ' '){
			if(flag){
				preSum = sum;
				flag = false;
			}
			sum = 0;
		}else{
			flag = true;
			sum++;
		}
		curr++;
	}
	if(sum)
		return sum;
	return preSum;
}