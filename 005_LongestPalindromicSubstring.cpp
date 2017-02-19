//O(n^2) Timeout limitExceeded
class Solution {
public:
    string longestPalindrome(string s) {
       int size(s.size()), len(size);
	   string res;
	   while(len > 1){
		   for(int i = 0; i <= size - len; i++){
			   if(isPalindrome(s, i, i + len - 1)){
				   return s.substr(i, len);
			   }
		   }
		   len--;
	   }
	   res += s[0];
	   return res;		   
    }
private:
	bool isPalindrome(string s, int left, int right){
		while(left < right){
			if(s[left++] != s[right--])
				return false;
		}
		return true;
	}
};

//A solution from LeetCode, hard to understand
string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}

//This one has better readability
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};