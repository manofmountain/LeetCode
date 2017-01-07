
//72.14%
class Solution {
public:
    int reverse(int x) {
        //Check boundaries
		if( -10 < x && x < 10)
			return x;
		int intMax = 0x7fffffff;
		int intMin = 0x80000000;
		//if(x == intMin)
		//	return 0;
		//int absX = x;
		//if(x < 0)
		//	absX = -x;
		long rstX = 0;
		//Main routine
		while(x != 0)
		{
			int unitVal = x % 10;
			rstX = rstX * 10 + unitVal;
			x /= 10;
		}
		
		if(rstX > intMax || rstX < intMin)
			return 0;
		return rstX;	
    }
};