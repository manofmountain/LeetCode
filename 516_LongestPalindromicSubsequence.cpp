//Space O(n^2) + time O(n^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
			return 0;
		int size(s.size());
		vector<vector<int>> records(size, vector<int>(size));
		for(int i = 0; i < size; ++i)
			records[i][i] = 1;
		for(int i = size - 1; i >= 0; --i){
			records[i][i] = 1;
			for(int j = i + 1; j < size; ++j){
				records[i][j] = s[i] == s[j] ? 2 + records[i + 1][j - 1] : max(records[i + 1][j], records[i][j + 1]);
			}
		}
		return records[0][size - 1];
    }
};

class Solution {
public:
    //lhs means left hand side, rhs means right hand side
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        
        vector<vector<int>> longest(s.size(), vector<int>(s.size()));
        for (int len=1; len<=s.size(); len++) {
            for (int lhs=0; lhs+len<=s.size(); lhs++) {
                int rhs = lhs+len-1;
                if (lhs == rhs) {
                    longest[lhs][rhs] = 1;
                } else if (lhs+1 == rhs) {
                    longest[lhs][rhs] = (s[lhs] == s[rhs]) ? 2 : 1;
                } else {
                    int add = s[lhs] == s[rhs] ? 2 : 0;
                    longest[lhs][rhs] = max(max(longest[lhs][rhs-1], longest[lhs+1][rhs]), longest[lhs+1][rhs-1] + add);
                }
            }
        }
        
        return longest[0].back();
    }
};

//91.51%
class Solution {
public:
   int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> v0(n), v1(n,1), v(n), *i_2=&v0, *i_1=&v1, *i_=&v;
        for(int i=2;i<=n;i++) {//length
            for(int j=0;j<n-i+1;j++)//start index
                i_->at(j) = s[j]==s[i+j-1]?2+i_2->at(j+1):max(i_1->at(j),i_1->at(j+1));
            swap(i_1,i_2);    
            swap(i_1,i_); //rotate i_2, i_1, i_
        }
        return i_1->at(0); 
    }	
};

//Memory limit exceeded
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
			return 0;
		int size(s.size());
		unordered_map<int, int> records;
		return helper(s, 0, s.size() - 1, records);
    }
private:
	int helper(string s, int start, int end, unordered_map<int, int>& records){
		if(records.find((start << 16) | end) != records.end())
			return records[(start << 16) | end];
		if(start > end)
			return 0;
		if(start == end)
			return 1;
		if(s[start] == s[end])
			records.insert(make_pair((start << 16) | end, helper(s, start + 1, end - 1, records) + 2));
		else
			records.insert(make_pair((start << 16) | end, max(helper(s, start + 1, end, records), helper(s, start, end - 1, records))));
		return records[(start << 16) | end];
	}	
};

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n));
        for(int i=0;i<n;i++) dp[1][i]=1;
        for(int i=2;i<=n;i++) //length
            for(int j=0;j<n-i+1;j++) {//start index 
                dp[i][j] = s[j]==s[i+j-1]?2+dp[i-2][j+1]:max(dp[i-1][j],dp[i-1][j+1]);
        return dp[n][0]; 
    }
	
	//O(n^2) time, O(n) space dp. In #3, the current row is computed from the previous 2 rows only. So we don't need to keep all the rows.
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> v0(n), v1(n,1), v(n), *i_2=&v0, *i_1=&v1, *i_=&v;
        for(int i=2;i<=n;i++) {//length
            for(int j=0;j<n-i+1;j++)//start index
                i_->at(j) = s[j]==s[i+j-1]?2+i_2->at(j+1):max(i_1->at(j),i_1->at(j+1));
            swap(i_1,i_2);    
            swap(i_1,i_); //rotate i_2, i_1, i_
        }
        return i_1->at(0); 
    }	

public class Solution {
    public int longestPalindromeSubseq(String s) {
        return helper(s, 0, s.length() - 1, new Integer[s.length()][s.length()]);
    }
    
    private int helper(String s, int i, int j, Integer[][] memo) {
        if (memo[i][j] != null) {
            return memo[i][j];
        }
        if (i > j)      return 0;
        if (i == j)     return 1;
        
        if (s.charAt(i) == s.charAt(j)) {
            memo[i][j] = helper(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[i][j] = Math.max(helper(s, i + 1, j, memo), helper(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
}

//Classical DP
public class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()];
        
        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.length()-1];
    }
}