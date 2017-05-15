//90.47%
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())
			return true;
		if(t.empty())
			return false;
		
		int tIndex(0), sIndex(0);
		while(tIndex < t.size() && sIndex < s.size()){
			tIndex = t.find_first_of(s[sIndex], tIndex);
			if(tIndex == string::npos)
				return false;
			++tIndex;
			++sIndex;
		}
		if(sIndex == s.size())
			return true;
		return false;
    }
};

class Solution {
public:
	static void initializeTable(string t){
		if(t.empty())
			return;
		for(int i = 0; i < t.size(); ++i)
			tTable[t[i] - 'a'].push_back(i);
	}
	
    bool isSubsequence(string s, string t) {
        if(s.empty())
			return true;
		if(t.empty())
			return false;
		initializeTable(t);
		vector<int> index(alpha_num);
		if(tTable[s[0] - 'a'].empty())
			return false;
		else
			index[s[0] - 'a'] = tTable[s[0] - 'a'].front();
		for(int i = 1; i < s.size(); ++i){
			if(tTable[s[i] - 'a'].empty() || tTable[s[i] - 'a'].back() < index[s[i - 1] - 'a'])
				return false;
			index[s[i] - 'a'] = *(upper_bound(tTable[s[i] - 'a'].begin(), tTable[s[i] - 'a'].end(), index[s[i - 1] - 'a']));
		}
		return true;
    }
private:
	const static int alpha_num = 26;
	static vector<vector<int> > tTable(alpha_num);
};