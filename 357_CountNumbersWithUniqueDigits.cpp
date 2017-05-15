//43.57%
//n >= 10 ( won't change )

//res = A(10, 1) + A(9, 1) * 9 + A(9, 2) * 9 + .... + A(9, n - 1) * 9
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		if(n == 0)
			return 1;
		if(n >= 10)
			n = 10;
		int res(10);
		for(int i = 1; i < n; ++i)
			res += arrangeNums(i) * 9;
        return res;
    }
private:
	int arrangeNums(int choice){
		int res(1);
		for(int i = 0; i < choice; ++i){
			res *= (9 - i);
		}
		return res;
	}
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		if(n == 0)
			return 1;
		if(n >= 10)
			n = 10;
		vector<int> res(n + 1);
		res[0] = 1;
		res[1] = 10;
		res[2] = 91;
		for(int i = 3; i <= n; ++i)
			res[i] = (res[i - 1] - res[i - 2]) * (9 - i + 2) + res[i - 1];
        return res[n];
    }
};

//10.07%
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		if(n == 0)
			return 1;
		if(n >= 10)
			n = 10;
		vector<int> res(n + 1);
		res[0] = 1;
		res[1] = 10;
		res[2] = 91;
		for(int i = 3; i <= n; ++i)
			res[i] = (res[i - 1] - res[i - 2]) * (11 - i) + res[i - 1];
        return res[n];
    }
};

//A java method
 public int countNumbersWithUniqueDigits(int n) {
        if (n == 0)     return 1;
        
        int res = 10;
        int uniqueDigits = 9;
        int availableNumber = 9;
        while (n-- > 1 && availableNumber > 0) {
            uniqueDigits = uniqueDigits * availableNumber;
            res += uniqueDigits;
            availableNumber--;
        }
        return res;
    }

//The same thinking way like mine	
class Solution {
public:
    int permutation(int n, int r)
    {
        if(r == 0)
        {
            return 1;
        }else{
            return n * permutation(n - 1, r - 1);
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if(n > 0)
        {
           int end = (n > 10)? 10 : n;
           for(int i = 0; i < end; i++)
           {
               sum += 9 * permutation(9, i);
           }
        }
        return sum;
    }
};