bool isPowerOfTwo(int n) {
    if(0 >= n) return false;
    if(!(n & (n - 1)))
		return true;
	else
	    return false;
}