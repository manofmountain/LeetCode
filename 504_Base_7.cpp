//14.61%
class Solution {
public:
    string convertToBase7(int num) {
		if(!num)
			return "0";
		string res;
		int temp = num > 0 ? num : -num;
		while(temp){
			res += ('0' + (temp % 7));
			temp /= 7;
		}
		if(num < 0) res += '-';
		reverse(res.begin(), res.end());
		return res;
    }
};

    string convertToBase7(int n) {
      int x = abs(n); string res;
      do res = to_string(x%7)+res; while(x/=7);
      return (n>=0? "" : "-") + res;
    }
	
	string convertToBase7(int n) {
      return n>=0? n>=7? convertToBase7(n/7)+to_string(n%7) : to_string(n) : '-'+convertToBase7(-n);
    }