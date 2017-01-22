int hammingWeight(uint32_t n) {
    uint32_t mask = 1;
	int count = 0;
	while(n){
		if(n & mask)
			count++;
		n >>= 1;
	}
	return count;
}