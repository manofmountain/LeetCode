int longestSubstring(string s, int k) {
   int max_len = 0;
   for (int first = 0; first+k <= s.size();) {
       int count[26] = {0};
       int mask = 0;
       int max_last = first;
       for (int last = first; last < s.size(); ++last) {
           int i = s[last] - 'a';
           count[i]++;
           if (count[i]<k) mask |= (1 << i);
           else   mask &= (~(1 << i));
           
           if (mask == 0) {
               max_len = max(max_len, last-first+1);
               max_last = last;
           }
       }
       first = max_last + 1;
   }
   return max_len;
}

int longestSubstring(string s, int k) {
    return longestSubstring_recur(s, k, 0, s.size());
}

int longestSubstring_recur(const string& s, int k, int first, int last) {
    int count[26] = {0};
    for (int j = first; j < last; ++j) ++count[s[j] - 'a'];
    
    int max_len = 0;
    for (int j = first; j < last;) {
        while (j < last && count[s[j]-'a']<k) ++j;
        if (j == last) break;
        int l = j;
        while (l < last && count[s[l]-'a']>=k) ++l;
        //all chars appear more than k times
        if (j == first && l == last) return last-first; 
        max_len = max(max_len, longestSubstring_recur(s, k, j, l));
        j = l;
    }
    return max_len;
}

//40.46%
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty() || s.size() < k)
			return 0;
		int maxLen(0);
		const int alpha_num(26);
		vector<int> sTable(alpha_num);
		for(char c : s)
			++sTable[c - 'a'];
		
		int idx(0);
		while(idx < s.size() && sTable[s[idx] - 'a'] >= k) ++idx;
		if(idx == s.size()) return s.size();
		
		return max(longestSubstring(s.substr(0, idx), k), longestSubstring(s.substr(idx + 1), k));
    }
};

//Other people's recursive solution
int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();
        
        unordered_map<char,int> Map;
        for(int i = 0; i < s.size(); i++){
            Map[s[i]]++;
        }
        
        int idx =0;
        while(idx <s.size() && Map[s[idx]] >= k)    idx++;
        if(idx == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx+1) , k);
        
        return max(left, right);
        
    }

//Java's recursive solution	
public int longestSubstring(String s, int k) {
    char[] str = s.toCharArray();
    return helper(str,0,s.length(),k);
}
private int helper(char[] str, int start, int end,  int k){
    if(end-start<k) return 0;//substring length shorter than k.
    int[] count = new int[26];
    for(int i = start;i<end;i++){
        int idx = str[i]-'a';
        count[idx]++;
    }
    for(int i = 0;i<26;i++){
        if(count[i]<k&&count[i]>0){ //count[i]=0 => i+'a' does not exist in the string, skip it.
            for(int j = start;j<end;j++){
                if(str[j]==i+'a'){
                    int left = helper(str,start,j,k);
                    int right = helper(str,j+1,end,k);
                    return Math.max(left,right);
                }
            }
        }
    }
    return end-start;
}