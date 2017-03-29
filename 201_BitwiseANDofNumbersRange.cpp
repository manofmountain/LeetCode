//80.06%
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n || m == 0)
			return m;
		int cnt(0);
		while(m && m != n){
			m >>= 1;
			n >>= 1;
			++cnt;
		}
		if(!m)
			return 0;
		else
			return m << cnt;
    }
};

int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}

//A java solution---which is really the best
 public int rangeBitwiseAnd(int m, int n) {
        while(m<n) n = n & (n-1);
        return n;
}