class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count(0);
		uint32_t mask(1);
		while(n){
			if(n & mask)
				count++;
			n >>= 1;
		}
		return count;
    }
};

//Better solution than mine
int hammingWeight(uint32_t n)
{
    int res = 0;
    while(n)
    {
        n &= n - 1;
        ++ res;
    }
    return res;
}