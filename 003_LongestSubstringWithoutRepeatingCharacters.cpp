//40.7%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen(0), currLen(0);
        int startIndex(0);
		unordered_map<char, int> mapS;
		for(int i = 0; i < s.size(); i++){
			unordered_map<char, int>::iterator ite = mapS.find(s[i]);
			if(ite == mapS.end()){
				mapS[s[i]] = i;
				currLen++;
			}else{
				if(currLen > maxLen){
					maxLen = currLen;
				}
				currLen = i - ite -> second;
				int temp(ite -> second);
				for(int j = startIndex; j <= ite -> second; j++)
					mapS.erase(s[j]);
				mapS[s[i]] = i;
				startIndex = temp + 1;
			}
		}
		return max(currLen, maxLen);
    }
};

int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }