//4.47%
class Solution {
public:
    string convertToTitle(int n) {
		if(!n)
			return "";
		string str("");
		str += (n - 1) % 26 + 'A';
		string strLeft = convertToTitle((n - 1) / 26);
		return strLeft + str;
    }
};

//4.47%
class Solution {
public:
    string convertToTitle(int n) {
		string res("");
		while(n){
			char right = (n - 1) % 26 + 'A';
			res = right + res;
			n = (n - 1) / 26;
		}
		return res;
    }
};

return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');