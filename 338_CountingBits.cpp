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