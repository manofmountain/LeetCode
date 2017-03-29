//It's a DP problem actually
//18.34%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty())
			return false;
		const int size(s.size());
		int minLen(s.size()), maxLen(-1);
		unordered_set<string> dict;
		for(int i = 0; i < wordDict.size(); ++i){
			dict.insert(wordDict[i]);
			int wordSize(wordDict[i].size());
			if(wordSize < minLen)
				minLen = wordSize;
			if(wordSize > maxLen)
				maxLen = wordSize;
		}
		vector<vector<bool> > status(size, vector<bool>(size, false));
		for(int l = minLen; l <= size; ++l){
			for(int i = 0; i <= size - l; ++i){
				int j = i + l - 1;
				for(int k = i + minLen - 1; k < j - minLen + 1; ++k){
					if(status[i][k] && status[k + 1][j]){
						status[i][j] = true;
						break;
					}
				}
				if(dict.find(s.substr(i, l)) != dict.end())
					status[i][j] = true;
			}
		}
		return status[0][size - 1];		
    }
};

//A better way than mine
public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
        
        boolean[] f = new boolean[s.length() + 1];
        
        f[0] = true;
        
        
        /* First DP
        for(int i = 1; i <= s.length(); i++){
            for(String str: dict){
                if(str.length() <= i){
                    if(f[i - str.length()]){
                        if(s.substring(i-str.length(), i).equals(str)){
                            f[i] = true;
                            break;
                        }
                    }
                }
            }
        }*/
        
        //Second DP
        for(int i=1; i <= s.length(); i++){
            for(int j=0; j < i; j++){
                if(f[j] && dict.contains(s.substring(j, i))){
                    f[i] = true;
                    break;
                }
            }
        }
        
        return f[s.length()];
    }
}

//A C++ way
bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }