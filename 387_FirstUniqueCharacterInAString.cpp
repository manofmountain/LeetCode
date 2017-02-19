//35.58%
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counter;
		//unordered_map<char, int> indices;
		int i(0);
		for(char c : s){
			//if(!counter[c])
			//	indices[c] = i;
			i++;
			counter[c]++;
		}
		i = 0;
		for(char c : s){
			if(counter[c] == 1)
				return i;
			i++;
		}
		return -1;
    }
};


//Brute force method like mine from LeetCode
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(auto &c : s) {
            m[c]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};

//Seems a better way
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for(int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for(auto &p : m) {
            if(p.second.first == 1) idx = min(idx, p.second.second);
        }
        return idx == s.size() ? -1 : idx;
    }
};