//2.82%
class Solution{
    public:
    int findNthDigit(int n) {
    if(n <= 9)
		return n;
	n -= 9;
	long num(180), start(10);
	int digits(2);
	while(n - num > 0){
		n -= num;
		++digits;
		start *= 10;
		//In case overflow
		num = 9 * start * digits;
	}
	
	int res(start + n / digits);
	int mark(n % digits);
	if(mark == 0){
		--res;
		mark = 0;
	}else
		mark = digits - mark;
	while(mark--)
		res /= 10;
	return res % 10;	
}
};


class Solution 
{
    // date: 2016-09-18     location: Vista Del Lago III Apartments
public:
    int findNthDigit(int n) 
    {
        // step 1. calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // step 2. calculate what the number is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;;

        // step 3. find out which digit in the number is we wanted.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};

//Java method
public int findNthDigit(int n) {
		int len = 1;
		long count = 9;
		int start = 1;

		while (n > len * count) {
			n -= len * count;
			len += 1;
			count *= 10;
			start *= 10;
		}

		start += (n - 1) / len;
		String s = Integer.toString(start);
		return Character.getNumericValue(s.charAt((n - 1) % len));
	}
	
public int findNthDigit(int n) {
    n -= 1;
    int digits = 1, first = 1;
    while (n / 9 / first / digits >= 1) {
        n -= 9 * first * digits;
        digits++;
        first *= 10;
    }
    return (first + n/digits + "").charAt(n%digits) - '0';
}
//Using divisions instead of multiplications to prevent overflow.