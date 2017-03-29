class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
			return 0;
		stack<int> operands;
		for(auto& token : tokens){
			int operand1(0), operand2(0);
			if(token == "+"){
				if(popTwoOperands(operands, operand1, operand2))
					operands.push(operand1 + operand2);
				else
					return 0;
			}else if(token == "-"){
				if(popTwoOperands(operands, operand1, operand2))
					operands.push(operand1 - operand2);
				else
					return 0;
			}else if(token == "*"){
				if(popTwoOperands(operands, operand1, operand2))
					operands.push(operand1 * operand2);
				else
					return 0;
			}else if(token == "/"){
				if(popTwoOperands(operands, operand1, operand2))
					operands.push(operand1 / operand2);
				else
					return 0;
			}else{
				operands.push(stoi(token));
			}
		}
		return operands.top();
    }
private:
	bool popTwoOperands(stack<int>& operands, int& operand1, int& operand2){
		if(operands.size() < 2)
			return false;
		operand2 = operands.top();
		operands.pop();
		operand1 = operands.top();
		operands.pop();
		return true;
	}
};

//A recursive function
int evalRPN(vector<string> &n) {
string s = n.back(); n.pop_back();
if ( s== "*" || s=="/" || s=="+" || s == "-" ){
int r2 = evalRPN(n);
int r1 = evalRPN(n);
if ( s=="*") return r1*r2;
if ( s=="/") return r1/r2;
if ( s=="+") return r1+r2;
if ( s=="-") return r1-r2;
}
else
return atoi(s.c_str());
}