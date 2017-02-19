//28.53%
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int size(str.size());
		for(int i = 1; i <= size / 2; i++){
			if(size % i == 0){
				string temp(str.begin(), str.begin() + i);
				string res;
				for(int j = 0; j < size / i; j++){
					res += temp;
				}
				if(res == str)
					return true;
			}
		}
		return false;
    }
};