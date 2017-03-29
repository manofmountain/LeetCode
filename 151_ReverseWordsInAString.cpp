//37.73%
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
			return;
		size_t start = s.find_first_not_of(" ");
		if(start == string::npos){
			s = "";
			return;
		}
		size_t end = s.find_last_not_of(" ");
		s = s.substr(start, end - start + 1);
		reverse(s.begin(), s.end());
		start = 0;
		for(int i = start; i < s.size();){
			if(s[i] == ' '){
				reverse(s.begin() + start, s.begin() + i);
				start = s.find_first_not_of(" ", i);
				i = start;
			}else
				++i;
		}
		reverse(s.begin() + start, s.end());
		int pos(0);
		for(int i = 0; i < s.size();){
			if(s[i] == ' ' && s[i - 1] == ' '){
				while(s[i] == ' ')
					++i;
			}else
				s[pos++] = s[i++];
		}
		s = s.substr(0, pos);
    }
};

//An in-place solution
void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int storeIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (storeIndex != 0) s[storeIndex++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
        }
    }
    s.erase(s.begin() + storeIndex, s.end());
}