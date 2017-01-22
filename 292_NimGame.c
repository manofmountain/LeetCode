//O(3^n)
bool canWinNim(int n) {
    if(n <= 3)
		return true;
	return !canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3);
}

//O(n)
bool canWinNim(int n) {
    if(n <= 3)
		return true;
	//n == 1, 2, 3
	bool a = true, b = true, c = true;
	for(int i = 4; i <= n; i++){
		bool d = !(a && b && c);
		a = b, b = c, c = d;
	}
	return c;	
}

//5.47%
//O(1) : n % 4
bool canWinNim(int n) {
	//return n % 4;
	return n & 3;
}