//17.17%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		if(n <= 0)
			return res;
		
		maxNum = n;
		int currLeft(1), currRight(0);
		
		generateParenthesisHelper(res, "(", currLeft, currRight);
		return res;
	}
private:
	int maxNum;
	void generateParenthesisHelper(vector<string> &res, string currStr, int currLeft, int currRight){
		if(currLeft == maxNum){
			while(currRight++ < maxNum){
				currStr += ")";
			}
			res.push_back(currStr);
			return;
		}
		generateParenthesisHelper(res, currStr + "(", currLeft + 1, currRight);
		if(currRight < currLeft)
			generateParenthesisHelper(res, currStr + ")", currLeft, currRight + 1);
	}		
};

//A more clear way from LeetCode
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};