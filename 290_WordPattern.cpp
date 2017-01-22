//Mine is not working
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> map1;
		map<string, char> map2;
		int pre(0), curr(0);
		for(char c : pattern){
			while(str[curr] == ' ')
				curr++;
			pre = curr;
			while(curr != str.size() && str[curr] != ' ')
				curr++;
			if(pre != curr){
				string word = str.substr(pre, curr - pre);
				curr++;
				if(map1.find(c) == map1.end() && map2.find(word) == map2.end())
				{
					map1[c] = word;
					map2[word] = c;
				}else{
					if(map1.find(c) != map1.end() && map1[c] != word || map2.find(word) != map2.end() && map2[word] != c)
						return false;
				}
			}else
				return false;
		}
		if(curr != str.size())
			return false;
		return true;
    }
};

//A smart code from LeetCode
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}

//This is the solution i want to initialize at first
bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }