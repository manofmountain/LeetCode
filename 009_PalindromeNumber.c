
//9.15% -> 47.91%
bool isPalindrome(int x) {	
	//Check if it's negative and it's not a palindrome
	if(x < 0)
		return false;
	if(x >= 0 && x <= 9)
		return true;
	//Now x is a positive number
	long rvsX = 0;
	int origX = x;
	while(x)
	{
		rvsX = rvsX * 10 + x % 10;
		x /= 10;
	}
	if(rvsX >= INT_MAX)
		return false;
	if(origX == rvsX)
		return true;
	else
		return false;
}