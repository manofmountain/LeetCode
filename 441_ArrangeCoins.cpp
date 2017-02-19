//25.66%
class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 0)
			return n;
		long x(n);
		return long(sqrt(1 + 8 * x) - 1) / 2;
    }
};


//Three way in LeetCode which have 'O(n), O(log(n)), O(1)'
class Solution {
public:
    int way1(int n) {
        int level = 1;
        for (long sum = 0; sum <= n; level++) 
            sum += level;
        return max(level - 2, 0);    
    }
    
    int way2(int n) {
        return sqrt(2 * (long)n + 1 / 4.0) - 1 / 2.0;
    }
    
    int arrangeCoins(int n) {
        long low = 1, high = n;
        while (low < high) {
            long mid = low + (high - low + 1) / 2;
            if ((mid + 1) * mid / 2.0 <= n) low = mid;
            else high = mid - 1;
        }
        return high;
    }
};