    
	//A java sliding window solution
public int characterReplacement(String s, int k) {
        int len = s.length();
        int[] count = new int[26];
        int start = 0, maxCount = 0, maxLength = 0;
        for (int end = 0; end < len; end++) {
            maxCount = Math.max(maxCount, ++count[s.charAt(end) - 'A']);
            while (end - start + 1 - maxCount > k) {
                count[s.charAt(start) - 'A']--;
                start++;
            }
            maxLength = Math.max(maxLength, end - start + 1);
        }
        return maxLength;
}
	
//A C++ solution
int characterReplacement(string s, int k) {
    int i = 0, j = 0, ctr[91] = {};
    while (j < s.size()) {
        ctr[s[j++]]++;
        if (j-i - *max_element(ctr+65, ctr+91) > k)
            ctr[s[i++]]--;
    }
    return j - i;
}

//68.23%
int characterReplacement(string s, int k) {
    int start(0), end(0), count[26] = {}, maxLen(0), maxCnt(0);
    while (end < s.size()) {
		maxCnt = max(maxCnt, ++count[s[end] - 'A']);
        if(end - start + 1 - maxCnt > k)
			--count[s[start++] - 'A'];
		maxLen = max(maxLen, end - start + 1);
		++end;
	}
    return maxLen;
}

//This is the most original solution but inefficient
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0;
        int maxCharCount = 0;
        int n = s.length();
        int result = 0;
        for(int end = 0; end < n; end++){
            counts[s[end]-'A']++;
            if(maxCharCount < counts[s[end]-'A']){
                maxCharCount = counts[s[end]-'A'];
            }
            while(end-start-maxCharCount+1 > k){
                counts[s[start]-'A']--;
                start++;
                for(int i = 0; i < 26; i++){
                    if(maxCharCount < counts[i]){
                        maxCharCount = counts[i];
                    }
                }
            }
            result = max(result, end-start+1);
        }
        return result;
    }
};