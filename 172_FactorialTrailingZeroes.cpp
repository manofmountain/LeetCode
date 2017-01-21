class Solution {
public:
    int trailingZeroes(int n) {
        int num5(0);
		while(n >= 5)
			num5 += (n /= 5);
		return num5;
    }
};

return n <= 5 ? 0 : n / 5 + trailingZeroes(n / 5);