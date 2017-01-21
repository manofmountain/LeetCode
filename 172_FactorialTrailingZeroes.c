
//O(n)
int trailingZeroes(int n) {
    if(n <= 4)
		return 0;
	int num5 = 0, num2 = 0;
	int m5 = n, m2 = n;
	while(!(m2 & 1)){
		num2++;
		m2 >>= 1;
	}
	while(!(m5 % 5)){
		num5++;
		m5 /= 5;
	}
	return num5 > num2 ? num2 + trailingZeroes(n - 1) : num5 + trailingZeroes(n - 1);
}

//That's the efficient one
int trailingZeroes(int n) {
    if(n <= 4)
		return 0;
	int num5 = 0;
	int m5 = n;

	while(m5 >= 5){
		m5 /= 5;
		num5 += m5;
	}
	return num5;
}