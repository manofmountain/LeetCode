//72.38%
class Solution {
public:
    bool isAnagram(string s, string t) {
        const int alpha_num(26);
		vector<int> count(alpha_num, 0);
		int s_len(0), t_len(0);
		for(char charS : s){
			s_len++;
			count[charS - 'a']++;
		}
		for(char charT : t){
			t_len++;
			if(--count[charT - 'a'] < 0)
				return false;
		}
		if(s_len != t_len)
			return false;
		return true;
    }
};

//Do things in a same circulation
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) { 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};