
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		if(x <= 9)
			return true;
			
		int origX = x;
		int rvsX = 0;
		while(x)
		{
			rvsX = rvsX * 10 + x % 10;
			x /= 10;
		}

		if(rvsX == origX)
			return true;
		return false;
    }
};

//75.55%
class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		if(x >= 0 && x <= 9)
			return true;
			
		int origX = x;
		int rvsX = 0;
		while(x)
		{
			rvsX = rvsX * 10 + x % 10;
			x /= 10;
		}
		
		if(rvsX >= INT_MAX)
			return false;
		if(rvsX == origX)
			return true;
		return false;
    }
};