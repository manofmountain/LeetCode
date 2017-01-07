
//A solution from LeetCode
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};
//22.85%
class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
		for(string::iterator iteS = s.begin(); iteS != s.end(); iteS++)
		{
			switch(*iteS)
			{
				case '(':
				case '[':
				case '{':
					charStack.push(*iteS);
					break;
				case ')':
					if( charStack.empty() || charStack.top() != '(')
						return false;
					charStack.pop();
					break;
				case ']':
					if( charStack.empty() || charStack.top() != '[')
						return false;
					charStack.pop();
					break;
				case '}':
					if( charStack.empty() || charStack.top() != '{')
						return false;
					charStack.pop();
					break;
				default:
					return false;
			}
		}
		
		return charStack.empty();
    }
};