//69.56%
class Solution {
public:
    string getHint(string secret, string guess) {
        string res("");
		int cows(0), bulls(0);
		const int digit_num(10);
		vector<int> digitsTable(digit_num, 0);
		for(int i = 0; i < secret.size(); i++){
			if(secret[i] == guess[i])
				cows++;
			else{
				if(digitsTable[secret[i] - '0'] < 0)
					bulls++;
				if(digitsTable[guess[i] - '0'] > 0)
					bulls++;
				digitsTable[secret[i] - '0']++;
				digitsTable[guess[i] - '0']--;
			}
		}
		res += to_string(cows);
		res += "A";
		res += to_string(bulls);
		res += "B";
		return res;
    }
};

//The solution from LeetCode and not as good as mine
class Solution {
public:
    // only contains digits 
    string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b 
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};