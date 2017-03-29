//60.08%
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0)
			return {0};
		vector<int> res(num + 1);
		for(int i = 1; i <= num; ++i){
			int l(i);
			//++res[i];
			while(l){
				++res[i];
				l &= (l - 1);
			}
		}
		return res;
    }
};


//98.81%
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0)
			return {0};
		vector<int> res(num + 1);
		for(int i = 1; i <= num; ++i){
			res[i] = res[i >> 1] + (i & 1);
		}
		return res;
    }
};

//Another great one, seems better
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};

//A great DP solution
public int[] countBits(int num) {
    int[] f = new int[num + 1];
    for (int i=1; i<=num; i++) f[i] = f[i >> 1] + (i & 1);
    return f;
}