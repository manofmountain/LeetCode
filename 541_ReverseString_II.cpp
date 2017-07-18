//69.3%
class Solution {
public:
    string reverseStr(string s, int k) {
		if(s.empty() || k <= 0)
			return s;
		int step(k * 2);
        for(int start = 0; start < s.size(); start += step){
			int pend = start + k  < s.size() ? start + k : s.size();
			int pstart(start);
			reverse(s.begin() + start, s.begin() + pend);
		}
		return s;		
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) reverse(s.begin()+i, min(s.begin()+i+k, s.end()));
        return s;
    }
};