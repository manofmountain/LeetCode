class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(0 >= n) return false;
		return !(n & (n - 1));
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};