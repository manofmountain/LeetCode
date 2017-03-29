class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
		if(strs.empty()) return res;
		unordered_map<string, int> indexTable;
		int index(0);
		for(auto str : strs){
			string temp(str);
			sort(temp.begin(), temp.end());
			if(indexTable.find(temp) == indexTable.end()){
				indexTable[temp] = index++;
				vector<string> vec(1, str);
				res.push_back(vec);
			}else{
				res[indexTable[temp]].push_back(str);
			}
		}
		return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = strSort(s);
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
private:
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
};