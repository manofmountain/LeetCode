//73.9%
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
			return vector<vector<string> > ();
		if(s.size() == 1)
			return vector<vector<string> >(1, vector<string>(1, s));
		vector<vector<string> > res;
		vector<string> vec;
		partitionHelper(res, vec, s, 0, s.size() - 1);
		return res;
    }
private:
	void partitionHelper(vector<vector<string> >& res, vector<string>& vec, const string& s, int left, int right){
		if(left > right){
			res.push_back(vec);
			return;
		}
		for(int i = left; i <= right; ++i){
			if(isPalindrome(s, left, i)){
				vec.push_back(s.substr(left, i - left + 1));
				partitionHelper(res, vec, s, i + 1, right);
				vec.pop_back();
			}
		}	
	}
	bool isPalindrome(const string& s, int left, int right){
		while(left < right){
			if(s[left++] != s[right--])
				return false;
		}
		return true;
	}
};