class Solution {
public:
    int hammingDistance(int x, int y) {
        int num(x^y), res(0);
		while(num){
			res++;
			num &= (num - 1);
		}
		return res;
    }
};