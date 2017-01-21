class Solution {
public:
    int titleToNumber(string s) {
       int res(0);
		for(string::const_iterator s_ite = s.begin(); s_ite != s.end(); s_ite++){
			res = res * 26 + (*s_ite - 'A') + 1;
		}
		return res;
    }
};