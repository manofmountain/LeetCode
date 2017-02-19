//1.66%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
		int size(digits.size());
		if(size == 0)
			return res;
		//string first;
		//first += digits[0];
		int first(0);
		while(first < size && !checkDigit(digits[first]))
			first++;
		if(first == size)
			return res;
		
		string strFirst = mapTable[digits[first] - '2'];
		vector<string> others = letterCombinations(digits.substr(first + 1, size - first));
		for(auto c : strFirst){
			string temp;
			temp += c;
			if(others.size() == 0)
				res.push_back(temp);
			else{
				for(auto str : others){
					res.push_back(temp + str);
				}
			}
		}
		return res;	
    }
private:
	inline bool checkDigit(char c){
		return c >= '2' && c <= '9';
	}
	string mapTable[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}

//This one has a better readibility
vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}