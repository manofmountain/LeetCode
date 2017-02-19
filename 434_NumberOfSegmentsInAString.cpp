//31.2%
class Solution {
public:
    int countSegments(string s) {
        int count(0);
		bool flag(false);
		for(auto c : s){
			if(c != ' '){
				if(!flag){
					flag = true;
					count++;
				}
			}else{
				if(flag)
					flag = false;
			}
		}
		return count;
    }
};

//A very clever solution from  LeetCode
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        s.push_back(' ');
        for(int i = 1; i < s.size(); ++i)
          if(s[i] == ' ' && s[i-1] != ' ') ++res;
        return res;
    }
};

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) 
            res += s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' ');
        return res;
    }
};

//WHich use regex to replace
int countSegments(string s) {
    return regex_replace(regex_replace(s, regex("\\S+"), "x"), regex(" "), "").size();
}