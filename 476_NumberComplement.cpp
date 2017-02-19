//2.27%
class Solution {
public:
    int findComplement(int num) {
        int res(0), cnt(0);
		while(num){
			if(!(num & 1))
				res |= (1 << cnt);
			cnt++;
			num >>= 1;
		}
		return res;
    }
};

//A great solution from LeetCode
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};

