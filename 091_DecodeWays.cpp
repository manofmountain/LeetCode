//14.59%
//Need to use DP
class Solution {
public:
    int numDecodings(string s) {
		int size(s.size());
		if(size == 0)
			return 0;
		//if having prefix chars as '0's, return 0
		//int start(0);
		if(s[0] == '0')
			return 0;
		
		if(1 == size){
			if(s[0] != '0')
				return 1;
			else
				return 0;
		}
		vector<int> res(size, 0);
		if(s[size - 1] == '0'){
			res[size - 1] = 0;
			if(s[size - 2] == '0' || s[size - 2] >= '3')
				return 0;
			else
				res[size - 2] = 1;
		}
		else{
			res[size - 1] = 1;
			if(s[size - 2] == '1' || s[size - 2] == '2' && s[size - 1] <= '6')
				res[size - 2] = 2;
			else
				res[size - 2] = 1;
		}

		for(int i = size - 3; i >= 0; i--){
			if(s[i + 1] == '0'){
				if(s[i] == '0' || s[i] >= '3')
					return 0;
				else
					res[i] = res[i + 1];
			}else{
				if(s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
					res[i] = res[i + 2] + res[i + 1];
				else
					res[i] = res[i + 1];
			}
		}
        return res[0];			
    }
};

//A concise solution from LeetCode
int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
    int r1 = 1, r2 = 1;
    
    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        } // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}


//Another solution from LeetCode
 int n = s.size();
    if(n == 0 || s[0] == '0') return 0;
    if(n == 1) return 1;
    int res = 0,fn_1 = 1,fn_2 = 1;
    for(int i = 1;i < n;i++){
        int temp = fn_1;
        if(isValid(s[i])&&isValid(s[i-1],s[i]))  res+=fn_1+fn_2;
        if(!isValid(s[i])&&isValid(s[i-1],s[i])) res+=fn_2;
        if(isValid(s[i])&&!isValid(s[i-1],s[i])) res+=fn_1;
        if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
        fn_1 = res;
        fn_2 = temp;
        res = 0;
    }
    return fn_1;
}
bool isValid(char a,char b){
    return a == '1'||(a == '2' && b <='6');
}
bool isValid(char a){
    return a != '0';
}