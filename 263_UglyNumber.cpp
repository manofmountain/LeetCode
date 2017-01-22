class Solution {
public:
    bool isUgly(int num) {
        while(num && num % 5 == 0)
			num /= 5;
		while(num && num % 3 == 0)
			num /= 3;
		while(num && (num & 1) == 0)
			num >>= 1;
		return 1 == num;
    }
};