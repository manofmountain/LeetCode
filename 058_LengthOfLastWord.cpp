//13.78%
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
			return 0;
		
		size_t indexFirst = s.find_first_not_of(' ');
		if(indexFirst == string::npos)
		    return 0;
		size_t indexLast = s.find_last_not_of(' ');
		int sum(0);
		for(int i = indexFirst; i <= indexLast; i++){
			if(s[i] == ' '){
				sum = 0;
			}else{
				sum++;
			}
		}
		return sum;
    }
};

//From LeetCode
class Solution {
public:
    int lengthOfLastWord(string s) { 
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};

//From LeetCode
 int lengthOfLastWord(const char* s) {
        int len = 0;
        while (*s) {
            if (*s++ != ' ')
                ++len;
            else if (*s && *s != ' ')
                len = 0;
    
        }
        return len;
    }