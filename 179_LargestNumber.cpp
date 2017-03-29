//39.77%


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty())
			return "";
		vector<string> strs;
		for(int i = 0; i < nums.size(); ++i)
			strs.push_back(to_string(nums[i]));
		sort(strs.begin(), strs.end(), compareStr);
		string res;
		for(int i = strs.size() - 1; i >= 0; --i){
			res += strs[i];
		}
		int start(0);
		while(start < res.length() - 1 && res[start] == '0')
			++start;
		return res.substr(start);
    }
private:
	static bool compareStr(const string& str1, const string& str2){
		return str1 + str2 < str2 + str1;
	}
};

//58.48%
//A good one from LeetCode
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](const string &s1, const string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};

//Another good one
class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        for(int i=0; i<num.size(); i++){
            ans += to_string(num[i]);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};