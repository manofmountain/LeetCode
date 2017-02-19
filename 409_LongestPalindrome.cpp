class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> counter;
		for(auto c : s)
			counter[c]++;
		bool hasOdd(false);
		int res(0);
		for(auto &item : counter){
			if(item.second & 1){
				hasOdd = true;
				item.second--;
			}
			res += item.second;
		}
		return hasOdd ? 1 + res : res;
    }
};

int longestPalindrome(string s) {
    int odds = 0;
    for (char c='A'; c<='z'; c++)
        odds += count(s.begin(), s.end(), c) & 1;
    return s.size() - odds + (odds > 0);
}

int longestPalindrome(string s) {
    vector<int> count(256);
    for (char c : s)
        ++count[c];
    int odds = 0;
    for (int c : count)
        odds += c & 1;
    return s.size() - odds + (odds > 0);
}

int longestPalindrome(string s) {
    vector<int> count(256);
    int odds = 0;
    for (char c : s)
        odds += ++count[c] & 1 ? 1 : -1;
    return s.size() - odds + (odds > 0);
}