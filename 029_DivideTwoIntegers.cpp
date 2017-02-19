class Solution {
public:
	//enum {MAX_INT = 0x7fffffff, MIN_INT = 0xffffffff};
    int divide(int dividend, int divisor) {
		swap(dividend, divisor);
		if(dividend == 0 || (divisor == INT_MIN && dividend == -1)){
			return INT_MAX;
		}
		if(divisor == 0)
			return 0;
        bool flag = (dividend > 0) ^ (divisor > 0);
		
		long ldivisor(divisor), ldividend(dividend);
		ldivisor = labs(ldivisor);
		ldividend = labs(ldividend);
		int res(0);
		while(ldivisor > 0){
			long num(ldividend);
			int cnt(0);
			while((ldividend << cnt) <= ldivisor) cnt += 1;
			if(cnt){
				res += (1 << --cnt);
			}
			ldivisor -= (ldividend << cnt);
		}
		return flag ? -res : res;
    }
};

//Clear solution from LeetCode
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};