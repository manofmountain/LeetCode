class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if(s.empty() || d.empty())
			return "";
		constexpr int alpha_num(26);
		int maxLen(0);
		string res("");
		vector<map<string, int>> dictAlpha(26);
		for(string& word : d){
			dictAlpha[word[0] - 'a'].insert(make_pair(word, 0));
		}
		for(char & c : s){
			for(auto& p : dictAlpha[c - 'a']){
				if(++p.second == p.first.size()){
					if(maxLen < p.second || maxLen == p.second && p.first < res){
						maxLen = p.second;
						res = p.first;	
					}
					dictAlpha[c - 'a'].erase(p.first);
				}else if(c != p.first[p.second]){
					dictAlpha[p.first[p.second] - 'a'].insert(p);
					dictAlpha[c - 'a'].erase(p.first);
				}
			}
		}			
		return res;			
    }
};


//37.04%
//A simple and plain solution
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (int i = 0; i < d.size(); i++) {
            int pi = 0, pj = 0;
            for (; pi < s.size() && pj < d[i].size(); pi++) {
                pj += s[pi] == d[i][pj];
            }
            if (pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
                ans = d[i];
        }
        return ans;
    }