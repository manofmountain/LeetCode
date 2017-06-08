int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);
        int res = 0, len = 0;
        for (int i = 0; i < p.size(); ++i) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
            if (++len > letters[cur]) {
                res += len - letters[cur];
                letters[cur] = len;
            }
        }
        return res;
    }

//A good java solution with better comments
public class Solution {
    public int findSubstringInWraproundString(String p) {
        // count[i] is the maximum unique substring end with ith letter.
        // 0 - 'a', 1 - 'b', ..., 25 - 'z'.
        int[] count = new int[26];
        
        // store longest contiguous substring ends at current position.
        int maxLengthCur = 0; 

        for (int i = 0; i < p.length(); i++) {
            if (i > 0 && (p.charAt(i) - p.charAt(i - 1) == 1 || (p.charAt(i - 1) - p.charAt(i) == 25))) {
                maxLengthCur++;
            }
            else {
                maxLengthCur = 1;
            }
            
            int index = p.charAt(i) - 'a';
            count[index] = Math.max(count[index], maxLengthCur);
        }
        
        // Sum to get result
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += count[i];
        }
        return sum;
    }
}

//Timelimit exceeded with O(n^2)
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.empty())
			return 0;
		
		unordered_set<string> history;
		int start(0), cnt(1);
		history.insert(p.substr(0, 1));
		for(int i = 1; i < p.size(); ++i){
			//Check if it's a new alphabet
			string subRes(p.substr(i, 1));
			if(history.find(subRes) == history.end()){
				history.insert(subRes);
				++cnt;
			}
			//If it is the next alphabit after previous one
			if(p[i] - 'a' == (p[i - 1] + 1 - 'a') % 26){
				for(int j = i - 1;j >= start; --j){
					string subRes(p.substr(j, i - j + 1));
					if(history.find(subRes) == history.end()){
						++cnt;
						history.insert(subRes);
					}
				}
			}else
				start = i;
		}
		return cnt;
    }
};