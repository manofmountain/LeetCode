//47.89%
class Solution {
public:
    int calculate(string s) {
        if(s.empty())
			return 0;
		queue<int> digits;
		queue<char> operators;
		for(int i = 0; i < s.size();){
			switch(s[i]){
				case '*':
				{
					++i;
					while(s[i] > '9' || s[i] < '0')
						++i;
					int num(s[i++] - '0');
					while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
						num = num * 10 + s[i] - '0';
						++i;
					}
					digits.back() *= num;
					//++i;
					break;
				}
				case '/':
				{
					++i;
					while(s[i] > '9' || s[i] < '0')
						++i;
					int num(s[i++] - '0');
					while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
						num = num * 10 + s[i] - '0';
						++i;
					}
					digits.back() /= num;
					//++i;
					break;
				}
				case '+':
					operators.push(s[i++]);
					break;
				case '-':
					operators.push(s[i++]);
					break;
				case ' ':
					++i;
					break;
				default:
				{
					int num(s[i++] - '0');
					while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
						num = num * 10 + s[i] - '0';
						++i;
					}
					digits.push(num);
				}
			}
		}
		while(!operators.empty()){
			if(operators.front() == '+'){
				int num1(digits.front());
				digits.pop();
				digits.front() += num1;
			}else{
				int num1(digits.front());
				digits.pop();
				swap(num1, digits.front());
				digits.front() -= num1;
			}
			operators.pop();
		}
		return digits.front();
    }
};


int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op; //44 - op <---> op == '+' ? 1 : -1
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

//A Java solution which is better than mine
public class Solution {
public int calculate(String s) {
    int len;
    if(s==null || (len = s.length())==0) return 0;
    Stack<Integer> stack = new Stack<Integer>();
    int num = 0;
    char sign = '+';
    for(int i=0;i<len;i++){
        if(Character.isDigit(s.charAt(i))){
            num = num*10+s.charAt(i)-'0';
        }
        if((!Character.isDigit(s.charAt(i)) &&' '!=s.charAt(i)) || i==len-1){
            if(sign=='-'){
                stack.push(-num);
            }
            if(sign=='+'){
                stack.push(num);
            }
            if(sign=='*'){
                stack.push(stack.pop()*num);
            }
            if(sign=='/'){
                stack.push(stack.pop()/num);
            }
            sign = s.charAt(i);
            num = 0;
        }
    }

    int re = 0;
    for(int i:stack){
        re += i;
    }
    return re;
}

//A better solution with using any extra space
class Solution {
public:
    int calculate(string s) {
        int result = 0, cur_res = 0;
        char op = '+';
        for(int pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {
            if(isdigit(s[pos])) {
                int tmp = s[pos] - '0';
                while(++pos < s.size() && isdigit(s[pos]))
                    tmp = tmp*10 + (s[pos] - '0');
                switch(op) {
                    case '+' : cur_res += tmp; break;
                    case '-' : cur_res -= tmp; break;
                    case '*' : cur_res *= tmp; break;
                    case '/' : cur_res /= tmp; break;
                }
            }
            else {
                if(s[pos] == '+' || s[pos] == '-') {
                    result += cur_res;
                    cur_res = 0;
                }
                op = s[pos++];
            }
        }
        return result + cur_res;
    }
};

//C++ normal solution
int calculate(string s) {
    stack<int> myStack;
    char sign = '+';
    int res = 0, tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            tmp = 10*tmp + s[i]-'0';
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
            if (sign == '-')
                myStack.push(-tmp);
            else if (sign == '+')
                myStack.push(tmp);
            else {
                int num;
                if (sign == '*' )
                    num = myStack.top()*tmp;
                else
                    num = myStack.top()/tmp;
                myStack.pop();
                myStack.push(num);
            } 
            sign = s[i];
            tmp = 0;
        }
    }
    while (!myStack.empty()) {
        res += myStack.top();
        myStack.pop();
    }
    return res;
}