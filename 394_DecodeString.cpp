//%3.27%
class Solution {
public:
    string decodeString(string s) {
        if(s.empty())
			return s;
		string curr;
		stack<int> repeatedNums;
		stack<string> currStrs;
		for(int i = 0; i < s.size();){
			char c = s[i];
			if(isdigit(c)){
				int sum(c - '0');
				++i;
				while(i < s.size() && isdigit(s[i]))
					sum = sum * 10 + (s[i++] - '0');
				repeatedNums.push(sum);
				continue;
			}else if(c == '['){
				currStrs.push(curr);
				curr = "";
			}else if(c == ']'){
				int num(repeatedNums.top());
				repeatedNums.pop();
				string subRes(currStrs.top());
				currStrs.pop();
				while(num--) subRes += curr;
				curr = subRes;
			}else
				curr += c;
			++i;
		}
		return curr;
    }
};

//A recursive solution
class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
}


//A java solution which has the same idea with mine
public class Solution {
    public String decodeString(String s) {
        String res = "";
        Stack<Integer> countStack = new Stack<>();
        Stack<String> resStack = new Stack<>();
        int idx = 0;
        while (idx < s.length()) {
            if (Character.isDigit(s.charAt(idx))) {
                int count = 0;
                while (Character.isDigit(s.charAt(idx))) {
                    count = 10 * count + (s.charAt(idx) - '0');
                    idx++;
                }
                countStack.push(count);
            }
            else if (s.charAt(idx) == '[') {
                resStack.push(res);
                res = "";
                idx++;
            }
            else if (s.charAt(idx) == ']') {
                StringBuilder temp = new StringBuilder (resStack.pop());
                int repeatTimes = countStack.pop();
                for (int i = 0; i < repeatTimes; i++) {
                    temp.append(res);
                }
                res = temp.toString();
                idx++;
            }
            else {
                res += s.charAt(idx++);
            }
        }
        return res;
    }
}