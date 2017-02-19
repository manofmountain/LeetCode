//46.49%
class Solution {
public:
   int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCnt(0), maxCnt(0);
		int zeroFlag(true);
		for(auto num : nums){
			if(num == 1){
				if(zeroFlag){
					zeroFlag = false;
					currCnt = 1;
				}
				else
					currCnt++;
			}else{
				if(!zeroFlag){
					if(currCnt > maxCnt)
						maxCnt = currCnt;
					zeroFlag = true;
				}
			}
		}
		return max(maxCnt, currCnt);
   }
};