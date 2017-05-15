//30.52%
class Solution {
public:
    string removeKdigits(string num, int k) {
		return removeKdigitsHelper(num, k, true);
    }
private:
	string removeKdigitsHelper(string num, int k, bool first){
		  if(num.empty() || k == 0)
			return num;
		if(k == num.size()){
			if(first)
				return "0";
			else
				return "";
		}
		//Search first 'k + 1' characters within num
		int indexSmallest(0);
		for(int i = 1; i <= k; ++i){
			if(num[i] == '0'){
				if(!first){
					if(k == i)
						return num.substr(i);
				}
				int firstZero(i++);
				while(i < num.size() && num[i] == '0')
					++i;
				if(i == num.size())
					return "0";
				else
					return removeKdigitsHelper(num.substr(i), k - firstZero, first);
			}
			if(num[i] < num[indexSmallest])
				indexSmallest = i;
		}
		return num[indexSmallest] + removeKdigitsHelper(num.substr(indexSmallest + 1), k - indexSmallest, false);
	}
};

//A java solution
public class Solution {
    public String removeKdigits(String num, int k) {
        int digits = num.length() - k;
        char[] stk = new char[num.length()];
        int top = 0;
        // k keeps track of how many characters we can remove
        // if the previous character in stk is larger than the current one
        // then removing it will get a smaller number
        // but we can only do so when k is larger than 0
        for (int i = 0; i < num.length(); ++i) {
            char c = num.charAt(i);
            while (top > 0 && stk[top-1] > c && k > 0) {
                top -= 1;
                k -= 1;
            }
            stk[top++] = c;
        }
        // find the index of first non-zero digit
        int idx = 0;
        while (idx < digits && stk[idx] == '0') idx++;
        return idx == digits? "0": new String(stk, idx, digits - idx);
    }
}

//Another Java solution
public class Solution {
    public String removeKdigits(String num, int k) {
        int len = num.length();
        //corner case
        if(k==len)        
            return "0";
            
        Stack<Character> stack = new Stack<>();
        int i =0;
        while(i<num.length()){
            //whenever meet a digit which is less than the previous digit, discard the previous one
            while(k>0 && !stack.isEmpty() && stack.peek()>num.charAt(i)){
                stack.pop();
                k--;
            }
            stack.push(num.charAt(i));
            i++;
        }
        
        // corner case like "1111"
        while(k>0){
            stack.pop();
            k--;            
        }
        
        //construct the number from the stack
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty())
            sb.append(stack.pop());
        sb.reverse();
        
        //remove all the 0 at the head
        while(sb.length()>1 && sb.charAt(0)=='0')
            sb.deleteCharAt(0);
        return sb.toString();
    }
}

//A good C++ solution
string removeKdigits(string num, int k) {
        while (k > 0) {
            int n = num.size();
            int i = 0;
            while (i+1<n && num[i]<=num[i+1])  i++;
            num.erase(i, 1);
            k--;
        }
        // trim leading zeros
        int s = 0;
        while (s<(int)num.size()-1 && num[s]=='0')  s++;
        num.erase(0, s);
        
        return num=="" ? "0" : num;
    }

//Another C++ solution	
string removeKdigits(string num, int k) {
        string res;
        int keep = num.size() - k;
        for (int i=0; i<num.size(); i++) {
            while (res.size()>0 && res.back()>num[i] && k>0) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);
        
        // trim leading zeros
        int s = 0;
        while (s<(int)res.size()-1 && res[s]=='0')  s++;
        res.erase(0, s);
        
        return res=="" ? "0" : res;
    }