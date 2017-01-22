//43.09%
uint32_t reverseBits(uint32_t n) {
	uint32_t count = 0;
    while(n && !(n & 1)){
		n >>= 1;
		count++;
	}	
	uint32_t res = 0;
	uint32_t mask = 0x80000000;
	while(n){
		if(n & 1)
			res |= mask;
		n >>= 1;
		mask >>= 1;
	}
	res >>= count;
	return res;
}

//My old solution
uint32_t reverseBits(uint32_t n) 
{
    uint32_t m = 0;
	uint32_t mask = 1;
	int i = 0;
	int length = 32;
	while(i < length)
	{
		m <<= 1;
		if(n & mask > 0)
			m |= mask;
		n >>= 1;
		i++;
	}
	
	return m;
}