//6.25%
//Remember it need to avoid 'integer overflow' issue
bool isPerfectSquare(int num) {
	if(num < 0)
		return false;
	if(1 >= num)
		return true;
    int i = 1, j = num / 2;
	while(i <= j){
		long mid = (i + j) / 2;
		long square = mid * mid;
		if(square == num)
			return true;
		else if(square < num)
			i = mid + 1;
		else
			j = mid - 1;
	}
	return false;
}