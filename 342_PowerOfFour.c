bool isPowerOfFour(int num) {
	if(0 >= num)
		return false;
	if(1 == num)
		return true;
	//return 0x40000000 % num == 0;
    //return 0x7ffffff4 % num == 0;
	int zeroCount = 0;
	while(num){
		if((num & 1) == 0){
			zeroCount++;
			num >>= 1;
		}
		else{
			num >>= 1;
			break;
		}
	}
	return (!num && zeroCount && !(zeroCount & 1));	
}
