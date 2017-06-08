//39.35%
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
		if(S.empty() || K <= 0)
			return "";
		//auto not_eqaul_dash = bind(not_equal_to<char>(), placeholders::_1, '-');
        int size(S.size()), notDashNum(count_if(S.begin(), S.end(), [](const char& c){ return c != '-';} ));
		if(!notDashNum)
			return "";
		int firstGroup(notDashNum % K);
		int dashNum(notDashNum / K);
		string res;
		int index(0);
		//Append firstGroup
		appendChars(S, firstGroup, res, index);
		
		//Append other dashNum groups
		while(dashNum--){
			res += '-';
			appendChars(S, K, res, index);
		}
		if(firstGroup)
			return res;
		else
			return res.substr(1);
    }
private:
	void appendChars(const string& S, int groupSize, string& res, int& index){
		while(groupSize--){
			while(S[index] == '-') ++index;
			if(S[index] >= 'a' && S[index] <= 'z')
				res += (S[index] - 'a' + 'A');
			else
				res += S[index];
			++index;
		}
	}
};


//A clean Java solution
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--)
            if (s.charAt(i) != '-')
                sb.append(sb.length() % (k + 1) == k ? '-' : "").append(s.charAt(i));
        return sb.reverse().toString().toUpperCase();
    } 

    string licenseKeyFormatting(string S, int K) {
      string res;
      for (auto i = S.rbegin(); i < S.rend(); i++)
        if (*i != '-') (res.size()%(K+1)-K? res : res+='-') += toupper(*i);
      return reverse(res.begin(), res.end()), res;
    }
	
	 string licenseKeyFormatting(string S, int K) {
      string res;
      for (auto i = S.rbegin(); i < S.rend(); i++)
        if (*i != '-') { // ignore '-' in original string
          if (res.size()%(K+1) == K) res += '-'; // every (K+1)th char is '-' from tail
          res += toupper(*i);
        }
        
      reverse(res.begin(), res.end());
      return res;
    }