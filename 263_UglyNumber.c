//0.68%
bool isUgly(int num) {
	if(!num)
		return false;
    while(num && 0 == num % 5)
		num /= 5;
	while(num && 0 == num % 3)
		num /= 3;
	while(num && 0 == num % 2)
		num >>= 1;
	if(1 == num)
		return true;
	return false;
}